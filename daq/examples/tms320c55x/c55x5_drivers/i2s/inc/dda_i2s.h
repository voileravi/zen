/*
 * $$$MODULE_NAME dda_i2s.h
 *
 * $$$MODULE_DESC dda_i2s.h
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This software is licensed under the  standard terms and conditions in the Texas Instruments  Incorporated
 *  Technology and Software Publicly Available Software License Agreement , a copy of which is included in the
 *  software download.
*/

/**
 *  \mainpage PSP I2S Driver
 *
 *  \section Introduction
 *
 *  \subsection xxx Purpose and Scope
 *  The purpose of this document is to explain the I2S driver on the PSP
 *  Framework architecture.
 *
 *  \subsection aaa I2S Usage and Working
 *  I2S(Inter IC Sound) is used to transfer the digital audio data.
 *  \n I2S is a serial interface between the processor and audio codec.
 *  It takes the data from the processor and transfers it to the codec
 *  as serial bit stream. It receives serial data from codec and transfers
 *  it to the processor. Copying the data to/from the I2S data registers
 *  should be done by the processor.
 *
 *  \subsection bbb Application Interfaces
 *  I2S driver provides 6 interface APIs for the application.
 *  \n I2S_INIT(), I2S_DeInit(), I2S_DMA_INIT(), I2S_DMA_Deinit(),
 *  I2S_TransmitData(), I2S_ReceiveData().
 *
 *  \n I2S_INIT() creates and initializes an I2S instance and returns
 *  the handle to that instance to the application.All the configuration
 *  parameters are passed to this API. After successful return from this API
 *  I2S is ready for the data transmission.
 *
 *  \n I2S_DeInit() deinitializes an I2S instance. After calling this API no
 *  further transmission is possible on that particular instance of I2S.
 *  \n This API must be called after completing all the data transfers
 *  for proper operation of the I2S. Next I2S init will fail for that
 *  particular instance if it is not deinitialized properly.
 *
 *  \n I2S_DMA_INIT() initializes one dma cannel for the data transfer.
 *  DMA is used to copy the data to/from the I2S data buffers.
 *  This API requests and configures one DMA channel for I2S transfer.
 *
 *  \n I2S_DMA_Deinit() releases the DMA channel after completing the data
 *  transfer. This must be called after completing all the data transfers,
 *  so that particular DMA channel is free and can be used by other modules.
 *
 *  \n I2S_TransmitData() transmits the I2S data.
 *  Data is copied to the I2S by the DMA using two data buffers. DMA copies
 *  data from the first data buffer and after completely transferring the first
 *  buffer, it takes the data from second buffer and again from first and so on
 *  This process continuous until the DMA is stopped by the application.
 *  First buffer address is provided to the DMA while DMA init and second
 *  buffer is passed to I2S_TransmitData() API.
 *
 *  \n I2S_ReceiveData() receives I2S data.
 *  Data is copied from the I2S using DMA into processor memory.
 *  Data reception also takes place into two buffers.
 *  First buffer address is provided to the DMA while DMA init and second
 *  buffer is passed to I2S_ReceiveData() API.
 *
 *  \subsection ccc Mode of operation
 *  I2S device can work in two modes Master and Slave.
 *  In master mode frame sync is generated by the I2S by using the CPU clock.
 *  In slave mode clock is fed to the I2S from the master(Ex:Codec).
 *  Driver supports both master and slave modes of operation.
 *  All the data transfers in I2S takes place through DMA.
 *  Driver does not support polled and interrupt modes of operation.
 */

/**
 *  \file   dda_i2s.h
 *
 *  \brief  I2S driver DDA header file
 *
 *  This file defines the various data structures to be used by DDA of I2S.
 *
 *  (C) Copyright 2006, Texas Instruments, Inc
 *
 *  \author     PR Mistral
 *  \version    1.0
 *  \version    1.1     PR Mistral - modified for code review comments
 */

#ifndef _DDA_I2S_H_
#define _DDA_I2S_H_

#include "ddc_i2s.h"

/**
 *  \brief I2S DDA Interface handle Definition
 *
 *  This defines the DDA object data structure for DDA implementation.
 */
typedef struct
{
    Ptr     i2sHandle;  /**< I2S driver handle  */
    Int16   i2sNum;     /**< I2S instance       */
} DDA_I2SObj;

/**
 *  \brief Function to initialize the I2S driver.
 *
 *  This function is called from the application to initialize and open
 *  a particular I2S instance. One call from application for each instance.
 *  This API initializes and opens one I2S instance and returns the handle
 *  for that instance.
 *
 *  \param i2sInstance  [IN]  I2S instance of I2S.
 *  \param i2sChanDir   [IN]  Channel direction Read/Write
 *  \param chanType     [IN]  Channel type(MONO/ STEREO)
 *  \param opMode       [IN]  Mode of opeartion(polled/interrupt)
 *  \param i2sConfig    [IN]  I2S Config parameters
 *  \param callback     [IN]  Callback argument
 *
 *  \return PSP_Handle - successful
 *          NULL       - failure
 */
PSP_Handle I2S_INIT(PSP_I2SInstanceId      i2sInstance,
                    PSP_I2SChanDir         i2sChanDir,
                    PSP_I2SChanType        chanType,
                    PSP_I2SOpMode          opMode,
                    PSP_I2SConfig          *i2sConfig,
                    PSP_I2SAppCallBack     callback);

/**
 *  \brief Function to shutdown a I2S driver instance.
 *
 *  Application code calls this API to deinitialise the I2S instance.
 *  After this function call all the I2S registers are reset and no further
 *  transmission can be done on that particular instance.
 *
 *  CAUTION: This API must be called after completing all the data tarnsfers
 *           for proper operation of the I2S. Next I2S init will fail for that
 *           particular instance if it is not deinitialized properly.
 *
 *  \param i2sHandle    [IN]  I2S device handle
 *
 *  \return PSP_SOK
 */
Int16 I2S_DeInit(PSP_Handle    i2sHandle);

/**
 *  \brief Function to initialize the I2S hardware.
 *
 *  This function initializes the CPU registers to bring the I2S out of idle
 *  and to enable the peripheral interrupts.
 *  This API is called from the system init function.
 *  NOTE: This API must be called only once during system initialization
 *
 *  \return   void
 */
void DDA_I2SHWInit(void);

/**
 *  \brief  Function to initiate the DMA for data transfer on I2S.
 *
 *  This API is called by the application to initialize DMA HW.
 *
 *  \param i2sHandle  [IN]  I2S device handle
 *  \param dmaConfig  [IN]  DMA configuration structure
 *
 *  \return    hDma - dma channel handle
 */
DMA_ChanHandle I2S_DMA_INIT(PSP_Handle       i2sHandle,
                            PSP_DMAConfig    *dmaConfig);

/**
 *  \brief Function to deinitialise a DMA channel
 *
 *  This API is called by the application to deinitialise a DMA channel
 *
 *  \param hDma  [IN]  dma channel handle
 *
 *  \return PSP_SOK - if successful or else suitable error code
 */
Int16 I2S_DMA_Deinit(DMA_ChanHandle    hDma);

/**
 *  \brief Function to initiate I2S transmission through DMA
 *
 *  This API is called by the application to transmit I2S data using DMA
 *
 *  \param i2sHandle      [IN]  The handle to the I2S instance
 *  \param nextTxLeftBuf  [IN]  Pointer to next left transmit buffer
 *  \param nextTxRightBuf [IN]  Pointer to next right transmit buffer
 *  \param hDmaTxLeft     [IN]  Dma handle for left transmit channel
 *  \param hDmaTxRight    [IN]  Dma handle for right transmit channel
 *
 *  \return PSP_SOK - if successful else suitable error code.
 */
Int16 I2S_TransmitData(PSP_Handle        i2sHandle,
                       Uint32            *nextTxLeftBuf,
                       Uint32            *nextTxRightBuf,
                       DMA_ChanHandle    hDmaTxLeft,
                       DMA_ChanHandle    hDmaTxRight);

/**
 *  \brief Function to initiate I2S reception through DMA
 *
 *  This API is called from the application to receive I2S data using DMA
 *
 *  \param i2sHandle      [IN]  The handle to the I2S instance
 *  \param nextRxLeftBuf  [IN]  Pointer to next left receive buffer
 *  \param nextRxRightBuf [IN]  Pointer to next right receive buffer
 *  \param hDmaRxLeft     [IN]  Dma handle for left receive channel
 *  \param hDmaRxRight    [IN]  Dma handle for right receive channel
 *
 *  \return PSP_SOK - if successful else suitable error code.
 */
Int16 I2S_ReceiveData(PSP_Handle        i2sHandle,
                      Uint32            *nextRxLeftBuf,
                      Uint32            *nextRxRightBuf,
                      DMA_ChanHandle    hDmaRxLeft,
                      DMA_ChanHandle    hDmaRxRight);

/**
 *  \brief Transmits I2S data through DMA
 *
 *  Function to initiate DMA transmission
 *  This API is called by the application to transmit I2S data using DMA
 *
 *  \param i2sHandle    [IN]  The handle to the I2S instance
 *  \param txBuffer     [IN]  Pointer to transmit data buffer.
 *  \param buffLen      [IN]  Transmit data length
 *
 *  \return PSP_SOK - if successful else suitable error code.
 */
Int16 I2S_DMA_ISR_OUTPUT(PSP_Handle    i2sHandle,
                         Uint16        *txBuffer,
                         Uint16        buffLen);
/**
 *  \brief Receives I2S data through DMA
 *
 *  Function to initiate I2S reception
 *  This API is called from the application to receive I2S data using DMA
 *
 *  \param i2sHandle    [IN]  The handle to the I2S instance
 *  \param rxBuffer     [IN]  Pointer to receive data buffer.
 *  \param buffLen      [IN]  Receive data length
 *
 *  \return PSP_SOK - if successful else suitable error code.
 */
Int16 I2S_DMA_ISR_INPUT(PSP_Handle    i2sHandle,
                        Uint16*       rxBuffer,
                        Uint16        buffLen);

#endif  /* _DDA_I2S_H_ */


