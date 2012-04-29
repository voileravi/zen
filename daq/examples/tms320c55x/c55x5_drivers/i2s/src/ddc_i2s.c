/*
 * $$$MODULE_NAME ddc_i2s.c
 *
 * $$$MODULE_DESC ddc_i2s.c
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This software is licensed under the  standard terms and conditions in the Texas Instruments  Incorporated
 *  Technology and Software Publicly Available Software License Agreement , a copy of which is included in the
 *  software download.
*/

/**
 *  \file   ddc_i2s.c
 *
 *  \brief  DDC of I2S Interface Driver file
 *
 *  This file implements the DDC interface of I2S driver functions.
 *
 *  (C) Copyright 2006, Texas Instruments, Inc
 *
 *  \author     PR Mistral.
 *  \version    1.0
 *  \version    1.1     PR Mistral - modified for code review comments
 */

#include <std.h>
#include <sem.h>
#include <log.h>

//#include "app_globals.h"
#include "ddc_i2s.h"
#include "psp_i2s.h"
#include "dda_i2s.h"
//#include "asrc_fix.h"

DDC_I2SObj DDC_I2S_Instance[I2S_PER_CNT];
/**< DDC instance handle */

Uint16   nextBuffer = FALSE;

Uint32    gi2sTxLeftBuf;
/**< Next left transmit buffer address     */
Uint32    gi2sTxRightBuf;

Uint32    gi2sNextTxLeftBuf;
/**< Next left transmit buffer address     */
Uint32    gi2sNextTxRightBuf;
/**< Next right transmit buffer address    */
Uint32    gi2sNextRxLeftBuf;
/**< Next left receive buffer address      */
Uint32    gi2sNextRxRightBuf;
/**< Next right receive buffer address     */
Uint32    gZeroBuf;
/**< zero buffer address     */
Uint32 dma_error = 0;

Bool prevDmaTxferComplete = FALSE;

//Bool      use_rx_buffer = FALSE;
Bool      use_tx_buffer = FALSE;

#ifdef ENABLE_RECORD
Uint32    gi2sRxLeftBuf;
/**< Next left receive buffer address     */
Uint32    gi2sRxRightBuf;
/**< Next left receive buffer address     */

extern Uint16 ping_pong_i2sRxLeftBuf[];
extern Uint16 ping_pongi2sRxRightBuf[];
#endif // ENABLE_RECORD

extern Uint16 ping_i2sTxLeftBuf[];
extern Uint16 ping_i2sTxRightBuf[];
extern Uint16 pong_i2sTxLeftBuf[];
extern Uint16 pong_i2sTxRightBuf[];

extern SEM_Obj SEM_DmaRxLeftComplete;
extern SEM_Obj SEM_DmaRxRightComplete;
extern LOG_Obj trace;

extern DMA_ChanHandle   hDmaTxLeft;
/**< DMA handle for left transmit channel  */
extern DMA_ChanHandle   hDmaTxRight;
/**< DMA handle for right transmit channel */
extern DMA_ChanHandle   hDmaRxLeft;
/**< DMA handle for left receive channel   */
extern DMA_ChanHandle   hDmaRxRight;
/**< DMA handle for right receive channel  */

extern Bool    gEp2Buff1Full;
extern Bool    gEp2Buff2Full;

//extern Bool usb_play_mode;
//extern Bool enable_asrc;
extern Uint16 outwrap;


/**
 *  \brief Assigns register starting address
 *
 *  Function to get the base register address for the specified I2S device.
 *  This API is called by driver code from DDC open function
 *
 *  \param eI2SNum  [IN]  I2S instance
 *  \param hI2S     [IN]  The handle to the I2S instance.
 *
 *  \return PSP_SOK - Successful, desired operation is done.
 *          PSP_E_INVAL_PARAM - Handle pass is INVALID.
 */
static Int16 DDC_I2SGetAttrs(I2S_INSTANCE    eI2SNum,
                             DDC_I2SHandle   hI2S);

/**
 *  \brief Opens I2S instance
 *
 *  Function to open the specified I2S device instance.
 *  This API is called by the driver code from DDA open function
 *
 *  \param eI2SNum    [IN]  I2S instance
 *  \param chType     [IN]  Channel type(MONO/ STEREO)
 *  \param i2sChanDir [IN]  Channel direction Read/Write
 *  \param opMode     [IN]  Mode of operation(polled/interrupt)
 *  \param callback   [IN]  Callback argument
 *  \param i2sHandle  [OUT] Pointer to the I2S instance handle
 *
 *  \return PSP_SOK - Successful, desired operation is done.
 *          PSP_E_INVAL_PARAM - I2S instance is INVALID.
 */
Int16 DDC_I2SOpen(I2S_INSTANCE           eI2SNum,
                  PSP_I2SChanType        chType,
                  PSP_I2SChanDir         i2sChanDir,
                  PSP_I2SOpMode          opMode,
                  PSP_I2SAppCallBack     callback,
                  PSP_Handle             *i2sHandle)
{
    Int16            status;
    DDC_I2SHandle    hI2S;

    status = PSP_E_INVAL_PARAM;

    hI2S  =  &DDC_I2S_Instance[eI2SNum];

    /* Check whether the device is in use */
    if(hI2S->i2sNum == eI2SNum)
    {
        //return status;
    }

    if(((eI2SNum >= 0) && (eI2SNum <= 3)) && (i2sHandle != NULL))
    {
        status  =  DDC_I2SGetAttrs(eI2SNum, hI2S);
        if(status != PSP_SOK)
        {
            return status;
        }
        hI2S->configured    =  FALSE;
        hI2S->chanDir       =  i2sChanDir;
        hI2S->chanType      =  chType;
        hI2S->opMode        =  opMode;
        hI2S->applCallBack  =  callback;
        *i2sHandle = hI2S;
        status     = PSP_SOK;
    }

    return status;
}

/**
 *  \brief Closes I2S instance
 *
 *  Function to close the specified I2S device instance.
 *  This API is called by driver code from DDA close function
 *
 *  \param i2sHandle  [IN]  The handle to the I2S instance
 *  \return PSP_SOK - Successful, desired operation is done.
 *          PSP_E_INVAL_PARAM - Handle pass is INVALID.
 */
Int16 DDC_I2SClose(PSP_Handle    i2sHandle)
{
    DDC_I2SHandle   hI2S;
    Int16           status;

    status = PSP_E_INVAL_PARAM;

    if(i2sHandle != NULL)
    {
        hI2S = (DDC_I2SHandle)i2sHandle;
        /* Reset the all register values */
        LLC_ResetAll(hI2S->regs);
        DDC_I2S_Instance[hI2S->i2sNum].regs = NULL;
        hI2S->i2sNum = (I2S_INSTANCE)-1;
        hI2S->configured = FALSE;
        hI2S = NULL;
        /* Enable DMA interrupts(Desabled for I2S transfer) */
        /* Caution for not effecting other modules */
        CSL_DMAEVTINT_REGS->DMAINTEN  =  0xFFFF;
        status  =  PSP_SOK;
    }

    return status;
}

/**
 *  \brief Assigns register starting address
 *
 *  Function to get the base register address for the specified I2S device.
 *  This API is called by driver code from DDC open function
 *
 *  \param eI2SNum  [IN]  I2S instance
 *  \param hI2S     [IN]  The handle to the I2S instance.
 *
 *  \return PSP_SOK - Successful, desired operation is done.
 *          PSP_E_INVAL_PARAM - Handle pass is INVALID.
 */
static Int16 DDC_I2SGetAttrs(I2S_INSTANCE    eI2SNum,
                             DDC_I2SHandle   hI2S)
{
    Int16    status;

    status  =  PSP_E_INVAL_PARAM;

    if(hI2S != NULL)
    {
        switch(eI2SNum)
        {
            case I2S_0:     /* Enable I2S0 */
                hI2S->regs      =  (CSL_I2sDrvRegs *)(CSL_I2S_REGS0);
                hI2S->i2sDmaId  =  PSP_DMA_I2S0;
                break;
            case I2S_1:     /* Enable I2S1 */
                hI2S->regs      =  (CSL_I2sDrvRegs *)(CSL_I2S_REGS1);
                hI2S->i2sDmaId  =  PSP_DMA_I2S1;
                break;
            case I2S_2:     /* Enable I2S2 */
                hI2S->regs      =  (CSL_I2sDrvRegs *)(CSL_I2S_REGS2);
                hI2S->i2sDmaId  =  PSP_DMA_I2S2;
                break;
            case I2S_3:     /* Enable I2S3 */
                hI2S->regs      =  (CSL_I2sDrvRegs *)(CSL_I2S_REGS3);
                hI2S->i2sDmaId  =  PSP_DMA_I2S3;
                break;
            default:
                break;
        }
        status  =  PSP_SOK;
    }
    hI2S->i2sNum = eI2SNum;

    return status;
}

/**
 *  \brief Configures I2S hardware
 *
 *  Function to setup the specified I2S device hardware registers.
 *  This API is called by driver code from DDA init function
 *
 *  \param i2sHandle     [IN]  The handle to the I2S instance
 *  \param i2sConfig     [IN]  Pointer to the i2s config structure.
 *
 *  \return PSP_SOK - Successful, desired operation is done.
 *          PSP_E_INVAL_PARAM - Handle pass is INVALID.
 */
Int16 DDC_I2SHwSetup(PSP_Handle       i2sHandle,
                     PSP_I2SConfig    *i2sConfig)
{
    DDC_I2SHandle     hI2S;
    DDC_I2S_HwSetup   *pi2sHwConfig;
    DDC_I2S_HwSetup   i2sHwConfig;
    Int16             status;

    status = PSP_E_INVAL_PARAM;

    if((i2sHandle != NULL) && (i2sConfig != NULL))
    {
        hI2S = (DDC_I2SHandle)i2sHandle;

        i2sHwConfig.eTxMode      =  (I2S_TXMODE_TYPE)i2sConfig->i2sMode;
        i2sHwConfig.eDataPack    =  (I2S_DATAPACK_TYPE)i2sConfig->datapack;
        i2sHwConfig.eSignExt     =  (I2S_SIGNEXT_TYPE)i2sConfig->signext;
        i2sHwConfig.eDataType    =  (I2S_MONO_TYPE)i2sConfig->datatype;
        i2sHwConfig.eWordLength  =
                                  (I2S_DATATX_WORDLEN_TYPE)i2sConfig->word_len;
        i2sHwConfig.eClkPol      =  (I2S_TX_CLKPOL_TYPE)i2sConfig->clk_pol;
        i2sHwConfig.eFsPol       =  (I2S_FSPOL_TYPE)i2sConfig->fsync_pol;
        i2sHwConfig.eDataDelay   =  (I2S_DATADELAY_TYPE)i2sConfig->datadelay;
        i2sHwConfig.eDataFormat  =
                                  (I2S_DATAFORMAT_TYPE)i2sConfig->dataformat;
        i2sHwConfig.eFsdiv       =  (I2S_FSDIV_TYPE)i2sConfig->fsdiv;
        i2sHwConfig.eClkdiv      =  (I2S_CLKDIV_TYPE)i2sConfig->clkdiv;

        if(hI2S->configured == FALSE)
        {
            pi2sHwConfig  = &i2sHwConfig;

            LLC_ResetAll(hI2S->regs);

            if(i2sConfig->loopBack == PSP_I2S_LOOPBACK_ENABLE)
            {
                LLC_I2SEnableLoopBack(hI2S->regs);
            }
            else
            {
                LLC_I2SDisableLoopBack(hI2S->regs);
            }

            /* Sign extension */
            LLC_I2SSetSignExt(hI2S->regs, pi2sHwConfig->eSignExt);

            /* Set the data packing */
            LLC_I2SSetDataPacking(hI2S->regs, pi2sHwConfig->eDataPack);

            /* Set the transmit mode of the I2S */
            LLC_I2SSetTransmitMode(hI2S->regs, pi2sHwConfig->eTxMode);

            /* Set the data type(Mono/stereo) */
            LLC_I2SSetMono(hI2S->regs, pi2sHwConfig->eDataType);

            /* Set the number of words for each frame */
            LLC_I2SSetWordLength(hI2S->regs, pi2sHwConfig->eWordLength);

            /* Set the clock polarity */
            LLC_I2SSetClkPol(hI2S->regs, pi2sHwConfig->eClkPol);

            /* Set frame sync polarity */
            LLC_I2SSetFsPol(hI2S->regs, pi2sHwConfig->eFsPol);

            /* Set data delay */
            LLC_I2SSetDataDelay(hI2S->regs, pi2sHwConfig->eDataDelay);

            /* Set data format */
            if(hI2S->chanType == PSP_I2S_CHAN_STEREO)
            {
                LLC_I2SSetDataFormat(hI2S->regs, I2S_DATAFORMAT_LJUST);

                /* Disable XMIT0 and RCV0 interrupts */
                LLC_I2SDisableICMR(hI2S->regs, I2S_ICMR_XMIT0_DISABLE);
                LLC_I2SDisableICMR(hI2S->regs, I2S_ICMR_RCV0_DISABLE);

                /* Enable XMIT1 and RCV1 interrupts */
                LLC_I2SEnableICMR(hI2S->regs, I2S_ICMR_XMIT1_ENABLE);
                LLC_I2SEnableICMR(hI2S->regs, I2S_ICMR_RCV1_ENABLE);
            }
            else
            {
                LLC_I2SSetDataFormat(hI2S->regs, I2S_DATAFORMAT_DSP);

                /* Enable XMIT0 and RCV0 interrupts */
                LLC_I2SEnableICMR(hI2S->regs,I2S_ICMR_XMIT0_ENABLE);
                LLC_I2SEnableICMR(hI2S->regs,I2S_ICMR_RCV0_ENABLE);

                /* Disable XMIT1 and RCV1 interrupts */
                LLC_I2SDisableICMR(hI2S->regs, I2S_ICMR_XMIT1_DISABLE);
                LLC_I2SDisableICMR(hI2S->regs, I2S_ICMR_RCV1_DISABLE);
            }

            /* Set the FSDIV value */
            LLC_I2SSetFsdiv(hI2S->regs, pi2sHwConfig->eFsdiv);

            /* SET CLKDIV value */
            LLC_I2SSetClkdiv(hI2S->regs, pi2sHwConfig->eClkdiv);

            /* Clear all the interrupts by resetting IR */
            LLC_I2SResetIR(hI2S->regs);

            /* Enable framesync and overrun/underrun errors */
            LLC_I2SEnableICMR(hI2S->regs,I2S_ICMR_FERR_ENABLE);
            LLC_I2SEnableICMR(hI2S->regs,I2S_ICMR_ORUR_ENABLE);

            hI2S->configured = TRUE;
            status = PSP_SOK;
        }
    }

    return status;
}

/**
 *  \brief DMA init function
 *
 *  Function to initiate the DMA for data transfer.
 *  This API is called by the driver code from DDA DMA init function
 *  to request and configure one DMA channel.
 *
 *  \param i2sHandle  [IN]  The handle to the I2S instance
 *  \param dmaConfig  [IN]  DMA configuration structure
 *
 *  \return   hDma  - DMA channel handle
 */
DMA_ChanHandle DDC_I2SDMAInit(PSP_Handle       i2sHandle,
                              PSP_DMAConfig    *dmaConfig)
{
    DDC_I2SHandle    hI2S;
    DMA_ChanHandle   hDma;
    Int16            status;

    hDma = NULL;

    if((i2sHandle != NULL) && (dmaConfig != NULL))
    {
        hI2S  =  (DDC_I2SHandle)i2sHandle;

        /* Request for the DMA channel */
        hDma  =  DMA_RequestChan(hI2S->i2sDmaId);

        if(hDma != NULL)
        {
            dmaConfig->dataCallback  =  hI2S;

            /* Configure the DMA channel */
            status  =  DMA_ConfigChan(hDma, dmaConfig);
            if(status != PSP_SOK)
            {
                status  =  DMA_ReleaseChan(hDma);
                return NULL;
            }
        }
    }

    return hDma;
}

/**
 *  \brief DMA deinit function
 *
 *  Function to deinitialise the DMA channel
 *
 *  \param hDma   [IN]  Handle to the DMA channel
 *
 *  \return PSP_SOK - if successful else suitable error code.
 */
Int16 DDC_I2SDMADeinit(DMA_ChanHandle    hDma)
{
    Int16   status;

    status  =  PSP_E_INVAL_PARAM;

    if(hDma != NULL)
    {
        status  =  DMA_ReleaseChan(hDma);
    }

    return status;
}

/**
 *  \brief DMA data write
 *
 *  Function to write the data from DMA to I2S.
 *  This API is called by the driver code from DDA to transmit
 *  I2S data using DMA.
 *
 *  \param i2sHandle      [IN]  The handle to the I2S instance
 *  \param nextTxLeftBuf  [IN]  Pointer to next left transmit buffer
 *  \param nextTxRightBuf [IN]  Pointer to next right transmit buffer
 *  \param hDmaTxLeft     [IN]  Dma handle for left transmit channel
 *  \param hDmaTxRight    [IN]  Dma handle for right transmit channel
 *
 *  \return PSP_SOK - Successful, else suitable error code
 *
 */
Int16 DDC_I2SDMAWrite(PSP_Handle        i2sHandle,
                        Uint32            *nextTxLeftBuf,
                      Uint32            *nextTxRightBuf,
                      DMA_ChanHandle    hDmaTxLeft,
                      DMA_ChanHandle    hDmaTxRight)
{
    DDC_I2SHandle    hI2S;
    Int16            status;
    PSP_Result       status0;
    PSP_Result       status1;
    Uint16           leftDmaChanNum;
    Uint16           dmaChanCount;
    Uint16           dmaNum;

    status   =  PSP_E_INVAL_PARAM;
    status0  =  PSP_E_INVAL_PARAM;
    status1  =  PSP_E_INVAL_PARAM;

    if(i2sHandle != NULL)
    {
        hI2S   =  (DDC_I2SHandle)i2sHandle;
        leftDmaChanNum   =  hDmaTxLeft->chanNum;
        dmaChanCount  =  4;
        dmaNum  =  0;


        if(hDmaTxLeft != NULL)
        {
            /* Find out the DMA engine number and channel number for
             * left Tx DMA channel */
            while(leftDmaChanNum >= dmaChanCount)
            {
                leftDmaChanNum  -=  dmaChanCount;
                   dmaNum   +=  1;
            }
            /* Disable the DMA interrupts on left transmit channel */
            CSL_DMAEVTINT_REGS->DMAINTEN  &=  ~(0x0001 <<
                                       (dmaNum*dmaChanCount + leftDmaChanNum));
        }

#if 0
        if(hDmaTxRight != NULL)
        {
            /* Find out the DMA channel number for right Tx DMA channel */
            while(RightDmaChanNum >= dmaChanCount)
            {
                RightDmaChanNum  -=  dmaChanCount;
            }
            /* Disable the DMA interrupts on Right transmit channel */
            CSL_DMAEVTINT_REGS->DMAINTEN  &=  ~(0x0001 <<
                                      (dmaNum*dmaChanCount + RightDmaChanNum));
        }
#endif
        /* Enable I2S transfer */
        LLC_I2SEnable(hI2S->regs);

        switch(hI2S->chanType)
        {
            case PSP_I2S_CHAN_STEREO:  /* Stereo data */
                if((hDmaTxLeft != NULL) && (hDmaTxRight != NULL) &&
                   (nextTxLeftBuf != NULL) && (nextTxRightBuf != NULL))
                {
                    /* Enable transfer on two dma channels */
                    status0  =  DMA_StartTransfer(hDmaTxLeft);
                    status1  =  DMA_StartTransfer(hDmaTxRight);
                }
                break;

            case PSP_I2S_CHAN_MONO:  /* Mono data */
                if((hDmaTxLeft != NULL) && (nextTxLeftBuf != NULL))
                {
                    /* Enable transfer on one dma channel */
                    status0  =  DMA_StartTransfer(hDmaTxLeft);
                    status1  =  PSP_SOK;
                }
                break;

            default:
                break;
        }

        if((status0 == PSP_SOK) && (status1 == PSP_SOK))
        {
            status  =  PSP_SOK;
        }
    }

    return status;
}

/**
 *  \brief DMA data read.
 *
 *  Function to receive the data from I2S using DMA.
 *  This API is called by the driver code from DDA to receive
 *  I2S data using DMA.
 *
 *  \param i2sHandle      [IN]  Handle to the I2S instance
 *  \param nextRxLeftBuf  [IN]  Pointer to next left receive buffer
 *  \param nextRxRightBuf [IN]  Pointer to next right receive buffer
 *  \param hDmaRxLeft     [IN]  Dma handle for left receive channel
 *  \param hDmaRxRight    [IN]  Dma handle for right receive channel
 *
 *  \return PSP_SOK -  if successful, else suitable error code
 */
Int16 DDC_I2SDMARead(PSP_Handle        i2sHandle,
                       Uint32            *nextRxLeftBuf,
                     Uint32            *nextRxRightBuf,
                     DMA_ChanHandle    hDmaRxLeft,
                     DMA_ChanHandle    hDmaRxRight)
{
    DDC_I2SHandle    hI2S;
    Uint16           leftDmaChanNum;
    Uint16           dmaChanCount;
    Uint16           dmaNum;
    Int16            status;
    PSP_Result       status0;
    PSP_Result       status1;

    status   =  PSP_E_INVAL_PARAM;
    status0  =  PSP_E_INVAL_PARAM;
    status1  =  PSP_E_INVAL_PARAM;

    if(i2sHandle != NULL)
    {
        hI2S  =  (DDC_I2SHandle)i2sHandle;
        leftDmaChanNum  =  hDmaRxLeft->chanNum;
        dmaChanCount  =  4;
        dmaNum  =  0;
        //gNextRxLeftBuf   =  (Uint32)nextRxLeftBuf;
        //gNextRxRightBuf  =  (Uint32)nextRxRightBuf;
        if(hDmaRxLeft != NULL)
        {
            /* Find out the DMA engine number and channel number for
             * left Rx DMA channel */
            while(leftDmaChanNum >= dmaChanCount)
            {
                leftDmaChanNum  -=  dmaChanCount;
                   dmaNum   +=  1;
            }
            /* Disable the DMA interrupts on left receive channel */
            CSL_DMAEVTINT_REGS->DMAINTEN  &=  ~(0x0001 <<
                                       (dmaNum*dmaChanCount + leftDmaChanNum));
        }

        /* Enable I2S reception */
        LLC_I2SEnable(hI2S->regs);

        switch(hI2S->chanType)
        {
            case PSP_I2S_CHAN_STEREO:  /* Stereo data */
                if((hDmaRxLeft != NULL) && (hDmaRxRight != NULL) &&
                   (nextRxLeftBuf != NULL) && (nextRxRightBuf != NULL))
                {
                    /* Enable transfer on two dma channels */
                    status0  =  DMA_StartTransfer(hDmaRxLeft);
                    status1  =  DMA_StartTransfer(hDmaRxRight);
                }
                break;

            case PSP_I2S_CHAN_MONO:  /* Mono data */
                if((hDmaRxLeft != NULL) && (nextRxLeftBuf != NULL))
                {
                    /* Enable transfer on one dma channel */
                    status0  =  DMA_StartTransfer(hDmaRxLeft);
                    status1  =  PSP_SOK;
                }
                break;

            default:
                break;
        }

        if((status0 == PSP_SOK) && (status1 == PSP_SOK))
        {
            status  =  PSP_SOK;
        }
    }

    return status;
}

/**
 *   \brief Call back function for DMA transmit complete
 *
 *  This function will be called when DMA transmit completes.
 *  This function changes the source address of the DMA channel and
 *  restarts the DMA transfer.
 *
 *   \param dmaStatus    [IN]    Status of the DMA transfer
 *   \param dataCallback [IN]    I2S handle
 *
 *   \return   void
 *
 */
void I2S_DmaTxCallBack(PSP_DMATransferStatus    dmaStatus,
                       void    *dataCallback)
{
#if 0 // currently unused
    Uint16 i;
    Int16 status;
    Uint16 * ptr_tx_left;
    Uint16 * ptr_tx_right;
    Uint16 * ptr_tx_codec_buf;
    Uint16 next_position;
    Uint16 wrap;

    prevDmaTxferComplete = TRUE;

    if((dataCallback != NULL) && (dmaStatus == PSP_DMA_TRANSFER_COMPLETE))
    {
        if(usb_play_mode == FALSE)
        {
            //playback not active- use zero buffer
            DMA_ChangeI2SSrcAddr(hDmaTxLeft,gZeroBuf);
            DMA_ChangeI2SSrcAddr(hDmaTxRight,gZeroBuf);

            /* Start dma transfer */
            DMA_StartTransfer(hDmaTxLeft);
            DMA_StartTransfer(hDmaTxRight);
            return;
        }

        // playback is active - get the next output buffer
        if(nextBuffer == TRUE)
        {
            nextBuffer = FALSE;

            //if(gEp2Buff2Full == TRUE)
            if(1)
            {
                // output pong buffer
                gEp2Buff2Full = FALSE;
                DMA_ChangeI2SSrcAddr(hDmaTxLeft,gi2sNextTxLeftBuf);
                DMA_ChangeI2SSrcAddr(hDmaTxRight,gi2sNextTxRightBuf);
            }
            else
            {
                // buffer is not ready
            //    dma_error++;
            //    DMA_ChangeI2SSrcAddr(hDmaTxLeft,gZeroBuf);
            //    DMA_ChangeI2SSrcAddr(hDmaTxRight,gZeroBuf);
            }

            /* Start dma transfer */
            DMA_StartTransfer(hDmaTxLeft);
            DMA_StartTransfer(hDmaTxRight);

            // fill the next buffer
            if(enable_asrc == TRUE)
            {
                // fill output buffer with ASRC output
                for(i = 0; i < I2S_TXBUFF_SIZE; i++)
                {
                    /* Generate output samples L and R */
                    status = ASRC_genOutAdaptCoefs16b(hAsrc, (Int16 *)&ping_i2sTxLeftBuf[i]);
                    if (status != ASRC_SOK)
                    {
                        dma_error++;
                    }
                    else
                    {
                        // save the right sample to the right output buffer
                        ping_i2sTxRightBuf[i] = ping_i2sTxLeftBuf[i + 1];
                    }

                    status = ASRC_accPhaseAdapt(hAsrc);
                    if (status != ASRC_SOK)
                    {
                        dma_error++;
                    }
                }
            }
            else // - fill output buffer with data from circular buffer
            {
                // this buffer needs to be filled with data to output
                ptr_tx_left = &ping_i2sTxLeftBuf[0];
                ptr_tx_right = &ping_i2sTxRightBuf[0];

                ptr_tx_codec_buf = &codec_output_buffer[codec_output_buffer_output_index];

                next_position = codec_output_buffer_output_index + (2*I2S_TXBUFF_SIZE);

                //prepare the next buffer
                if(next_position < CODEC_OUTPUT_BUFFER_SIZE)
                {
                    // copy without wrap
                    for(i = 0; i < I2S_TXBUFF_SIZE; i++)
                    {
                        *ptr_tx_left++ = *ptr_tx_codec_buf++;
                        *ptr_tx_right++ = *ptr_tx_codec_buf++;
                    }
                    // update index into circular buffer - 'x2' due to 2 writes
                    codec_output_buffer_output_index += (2*I2S_TXBUFF_SIZE);
                }
                else
                {
                    // copy with wrap
                    outwrap++;
                    wrap = (CODEC_OUTPUT_BUFFER_SIZE - codec_output_buffer_output_index)>>1;
                    // copy prior to wrap
                    for(i = 0; i < wrap; i++)
                    {
                        *ptr_tx_left++ = *ptr_tx_codec_buf++;
                        *ptr_tx_right++ = *ptr_tx_codec_buf++;
                    }
                    // now wrap
                    ptr_tx_codec_buf = &codec_output_buffer[0];
                    wrap = I2S_TXBUFF_SIZE - wrap;
                    // copy after wrap
                    for(i = 0; i < wrap; i++)
                    {
                        *ptr_tx_left++ = *ptr_tx_codec_buf++;
                        *ptr_tx_right++ = *ptr_tx_codec_buf++;
                    }
                    // update index into circular buffer - 'x2' due to 2 writes
                    codec_output_buffer_output_index = 2*wrap;
                }
            }
        }
        else
        {
            nextBuffer = TRUE;

            //if(gEp2Buff1Full == TRUE)
            if(1)
            {
                // output ping buffer
                gEp2Buff1Full = FALSE;
                DMA_ChangeI2SSrcAddr(hDmaTxLeft,gi2sTxLeftBuf);
                DMA_ChangeI2SSrcAddr(hDmaTxRight,gi2sTxRightBuf);
            }
            else
            {
                // buffer is not ready
                //dma_error++;
                //DMA_ChangeI2SSrcAddr(hDmaTxLeft,gZeroBuf);
                //DMA_ChangeI2SSrcAddr(hDmaTxRight,gZeroBuf);
            }

            /* Start dma transfer */
            DMA_StartTransfer(hDmaTxLeft);
            DMA_StartTransfer(hDmaTxRight);

            // fill the next buffer
            if(enable_asrc == TRUE)
            {
                // fill output buffer with ASRC output
                for(i = 0; i < I2S_TXBUFF_SIZE; i++)
                {
                    /* Generate output samples L and R */
                    status = ASRC_genOutAdaptCoefs16b(hAsrc, (Int16 *)&pong_i2sTxLeftBuf[i]);
                    if (status != ASRC_SOK)
                    {
                        dma_error++;
                    }
                    else
                    {
                        // save the right sample to the right output buffer
                        pong_i2sTxRightBuf[i] = pong_i2sTxLeftBuf[i + 1];
                    }

                    status = ASRC_accPhaseAdapt(hAsrc);
                    if (status != ASRC_SOK)
                    {
                        dma_error++;
                    }
                }
            }
            else // - fill output buffer with data from circular buffer
            {
                // this buffer needs to be filled with data to output
                ptr_tx_left = &pong_i2sTxLeftBuf[0];
                ptr_tx_right = &pong_i2sTxRightBuf[0];

                ptr_tx_codec_buf = &codec_output_buffer[codec_output_buffer_output_index];

                next_position = codec_output_buffer_output_index + (2*I2S_TXBUFF_SIZE);

                //prepare the next buffer
                if(next_position < CODEC_OUTPUT_BUFFER_SIZE)
                {
                    // copy without wrap
                    for(i = 0; i < I2S_TXBUFF_SIZE; i++)
                    {
                        *ptr_tx_left++ = *ptr_tx_codec_buf++;
                        *ptr_tx_right++ = *ptr_tx_codec_buf++;
                    }
                    // update index into circular buffer - 'x2' due to 2 writes
                    codec_output_buffer_output_index += (2*I2S_TXBUFF_SIZE);
                }
                else
                {
                    // copy with wrap
                    wrap = (CODEC_OUTPUT_BUFFER_SIZE - codec_output_buffer_output_index)>>1;
                    // copy prior to wrap
                    for(i = 0; i < wrap; i++)
                    {
                        *ptr_tx_left++ = *ptr_tx_codec_buf++;
                        *ptr_tx_right++ = *ptr_tx_codec_buf++;
                    }
                    // now wrap
                    ptr_tx_codec_buf = &codec_output_buffer[0];
                    wrap = I2S_TXBUFF_SIZE - wrap;
                    // copy after wrap
                    for(i = 0; i < wrap; i++)
                    {
                        *ptr_tx_left++ = *ptr_tx_codec_buf++;
                        *ptr_tx_right++ = *ptr_tx_codec_buf++;
                    }
                    // update index into circular buffer - 'x2' due to 2 writes
                    codec_output_buffer_output_index = 2*wrap;
                }
            }
        }
    }
    else
    {
        //printf("TX DMA Failed\n"); // ****NOTE: printf causes USB problems if called in this funtion
    }

    /* Please add your semaphore here */
#endif
}

/**
 *   \brief Call back function for DMA left channel receive complete
 *
 *  This function will be called when DMA receive completes
 *  This function changes the destination address of the DMA channel and
 *  restarts the DMA transfer.
 *
 *   \param dmaStatus    [IN]    Status of the DMA transfer
 *   \param dataCallback [IN]    I2S handle
 *
 *   \return             void
 *
 */
void I2S_DmaRxLChCallBack(
    PSP_DMATransferStatus    dmaStatus,
    void    *dataCallback
)
{
#ifdef ENABLE_RECORD

    if ((dataCallback != NULL) && (dmaStatus == PSP_DMA_TRANSFER_COMPLETE))
    {
        SEM_post(&SEM_DmaRxLeftComplete);
    }
    else
    {
        LOG_printf(&trace, "RX DMA Failed\n");
    }
#endif // ENABLE_RECORD
}

/**
 *   \brief Call back function for DMA right channel receive complete
 *
 *  This function will be called when DMA receive completes
 *  This function changes the destination address of the DMA channel and
 *  restarts the DMA transfer.
 *
 *   \param dmaStatus    [IN]    Status of the DMA transfer
 *   \param dataCallback [IN]    I2S handle
 *
 *   \return             void
 *
 */
void I2S_DmaRxRChCallBack(
    PSP_DMATransferStatus    dmaStatus,
    void    *dataCallback
)
{
#ifdef ENABLE_STEREO_RECORD

    if ((dataCallback != NULL) && (dmaStatus == PSP_DMA_TRANSFER_COMPLETE))
    {
        SEM_post(&SEM_DmaRxRightComplete);
    }
    else
    {
        LOG_printf(&trace, "RX DMA Failed\n");
    }
#endif // ENABLE_STEREO_RECORD
}
