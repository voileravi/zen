/*
 * $$$MODULE_NAME pal_sys.c
 *
 * $$$MODULE_DESC pal_sys.c
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This software is licensed under the  standard terms and conditions in the Texas Instruments  Incorporated
 *  Technology and Software Publicly Available Software License Agreement , a copy of which is included in the
 *  software download.
*/

/** \file   pal_sys.c
    \brief  OsSem Services Source File for PrOS

    (C) Copyright 2004, Texas Instruments, Inc

    \author    PSP Team
    \version   0.2 - earlier implementation
               0.3 - adapted for DA225

 */

#include <pal_sys.h>

#ifndef BIOS_BUILD
#include <cslr_psc.h>
#endif

/* ARM Auxilary Control Register 0, used for locking/unlocking PSC/PLL */
#define CFG_ARMAUX_CTL0 (*(volatile Uint32 *)(0x01C4814C))

/**
 *  \brief Reset Ioctl
 *
 *  This function provides reset Ctrl functionality.
 *
 *  \param  resetModuleId [IN]          module Id
 *  \param  resetIoctl [IN]             reset Ctrl
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysResetCtrl(Uint32 resetModuleId,PAL_sysResetControl resetCtrl)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief Get status of Reset
 *
 *  This function get reset status.
 *
 *  \param  resetModuleId [IN]          module Id
  *  \return PAL_sysResetControl
 */
PAL_sysResetControl PAL_sysGetResetStatus(Uint32 resetModuleId)
{
    return (PAL_sysResetControl)PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief perform system reset
 *
 *  This function performs system reset.
 *
 *  \param  mode[IN]        reset mode
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysSystemReset(PAL_SysSystemRstMode mode)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}
/**
 *  \brief perform system reset
 *
 *  This function performs system reset.
 *
 *  \param
 *  \return PAL_SysSystemResetStatus
 */
PAL_SysSystemResetStatus PAL_sysGetSysLastResetStatus(void)
{
    return (PAL_SysSystemResetStatus)1;
}





/*****************************************************************************
 * Power Control Module
 *****************************************************************************/


/**
 *  \brief Module Power Ioctl
 *
 *  This function provides module power control functionality.
 *
 *  \param  powerModule [IN]            module Id
 *  \param  powerCtrl [IN]              power Ctrl
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysPowerCtrl(Uint32 powerModule,  PAL_sysPowerControl powerCtrl)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief Get Module Power status
 *
 *  This function provides module power control functionality.
 *
 *  \param  powerModule [IN]            module Id
 *  \return PAL_sysPowerControl
 */
PAL_sysPowerControl PAL_sysGetPowerStatus(Uint32 powerModule)
{
    return (PAL_sysPowerControl)PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief Set Global Power Mode
 *
 *  This function sets global power mode.
 *
 *  \param  powerMode [IN]        power mode
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysSetGlobalPowerMode(PAL_SysSysytemPowerMode powerMode)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief Get Global Power mode
 *
 *  This function provides global power mode.
 *
 *  \param
 *  \return PAL_SysSysytemPowerMode
 */
PAL_SysSysytemPowerMode PAL_sysGetGlobalPowerMode(void)
{
    return (PAL_SysSysytemPowerMode)1;
}




/*****************************************************************************
 * Wakeup Control
 *****************************************************************************/


/**
 *  \brief Wake up control
 *
 *  This function provides functionality of wake up control.
 *
 *  \param   wakeupInt[IN]      Interrupt for wakeup
 *  \param   wakeupCtrl[IN]     wake up control
 *  \param   wakeupPolarity[IN] wake up polarity
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWakeupCtrl(PAL_SysWakeupInterrupt wakeupInt,
                         PAL_SysWakeupCtrl wakeupCtrl,
                         PAL_SysWakeupPolarity wakeupPolarity)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}


/*****************************************************************************
 * GPIO Control
 *****************************************************************************/




/**
 *  \brief GPIO Init
 *
 *  Init function for GPIO.
 *
 *  \param
 *  \return
 */
void PAL_sysGpioInit(void)
{

}


/**
 *  \brief GPIO control
 *
 *  This function provides functionality for GPIO control.
 *
 *  \param   gpioPin[IN]        GPIO Pin number
 *  \param   pinMode[IN]        mode of GPIO pin
 *  \param   pinDirection[IN]   GPIO pin direction
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysGpioCtrl(Uint32 gpioPin,
                      PAL_SysGpioPinMode pinMode,
                      PAL_SysGpioPinDirection pinDirection)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief GPIO pin Out
 *
 *  It is used to set value to one GPIO pin.
 *
 *  \param   gpioPin[IN]        GPIO Pin number
 *  \param   value[IN]          value to be set on GPIO pin
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysGpioOutBit(Uint32 gpioPin, int value)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief GPIO pin In
 *
 *  It is used to get value at one GPIO pin.
 *
 *  \param   gpioPin[IN]        GPIO Pin number
 *  \return value at GPIO pin
 */
Int PAL_sysGpioInBit(Uint32 gpioPin)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief Set value to group of GPIO Pin
 *
 *  It is used to set value to group of GPIO Pin.
 *
 *  \param   outVal[IN]         vale to be set on group of GPIO pin
 *  \param   outMask[IN]        Mask defines group of pins in GPIO register
 *  \param   regIndex[IN]       Index of register
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysGpioOutValue(Uint32 outVal, Uint32 outMask,
                           Uint32 regIndex)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief Get value of group of GPIO Pin
 *
 *  It is used to get value of group of GPIO Pin.
 *
 *  \param   inVal[IN]          vale of group of GPIO pin
 *  \param   regIndex[IN]       Index of register
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysGpioInValue(Uint32 *inVal, Uint32 regIndex)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}


/*****************************************************************************
 * CLKC Control
 *****************************************************************************/

 /**
 *  \brief Clock Init
 *
 *  Init function for Clock.
 *
 *  \param  param[IN]
 *  \return
 */
void PAL_sysClkcInit(void* param)
{

}

/**
 *  \brief Set frequency to clock
 *
 *  It is used to set frequncy to clock .
 *
 *  \param   clkId[IN]          Clock Id
 *  \param   outputFreq[IN]     frequency
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysClkcSetFreq(Uint32 clkId, Uint32 outputFreq)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}


/**
 *  \brief Get Clock frequency
 *
 *  It is used to get frequncy of clock .
 *
 *  \param   clkId[IN]          Clock Id
 *  \return Clock frequency
 */
Int PAL_sysClkcGetFreq(Uint32 clkId)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief Module Clock Control
 *
 *  It is used provides module clock control functionalties .
 *
 *  \param   moduleId[IN]               module Id
 *  \param   clkIoctl[IN]               Clock Ctrl
  *  \return PSP_SOK or PSP Error code
 */

PAL_Result PAL_sysModuleClkCtrl(Uint32 moduleId,PAL_SysModuleClkControl clkCtrl)
{
#ifndef BIOS_BUILD
    CSL_PscRegsOvly     pscRegs;
    volatile Uint32     newState;
    volatile Uint32     count = PAL_SYS_CLK_MODULE_TIMEOUT;

    if ((moduleId < PAL_SYS_CLK_MODULE_MIN) || (moduleId > PAL_SYS_CLK_MODULE_MAX)) {
        return(PAL_SYS_ERROR_INVALID_PARAM);
    }

    if ((clkCtrl != PAL_SYS_MODULE_CLK_ENABLE) && (clkCtrl != PAL_SYS_MODULE_CLK_DISABLE)) {
        return(PAL_SYS_ERROR_INVALID_PARAM);
    }

    if(clkCtrl == PAL_SYS_MODULE_CLK_ENABLE) {
        newState = PAL_SYS_CLK_MODULE_STATE_ENABLE;
    } else {
        newState = PAL_SYS_CLK_MODULE_STATE_DISABLE;
    }

    /* Unlock the PSC & PLL */
    CFG_ARMAUX_CTL0 &= 0xFFF0FFFF;
    CFG_ARMAUX_CTL0 |= 0x00090000;

    pscRegs = (CSL_PscRegsOvly)CSL_PSC_REGS;
    pscRegs->MDCTL[moduleId] = (pscRegs->MDCTL[moduleId] & CSL_PSC_MDCTL_NEXT_MASK) | newState;
    while (((pscRegs->MDSTAT[moduleId] & CSL_PSC_MDSTAT_STATE_MASK) != newState) && (count != 0)) {
        count --;
    }

    count = PAL_SYS_CLK_MODULE_TIMEOUT;
    pscRegs->PTCMD = 0x00000001;
    while ((count != 0) && (pscRegs->PTSTAT & 0x1)) {
        count--;
    }

    /* Lock PLL0, PLL1, MPROT and PSC registers */
    CFG_ARMAUX_CTL0 |= 0x000F0000;

    return (PAL_SOK);
#else
    return(PAL_SYS_ERROR_NOT_SUPPORTED);
#endif
}

/**
 *  \brief Get Status of Module Clock
 *
 *  It is used provides module clock control functionalties .
 *
 *  \param   moduleId[IN]               module Id
 *  \return PAL_SysModuleClkControle
 */
PAL_SysModuleClkControl PAL_sysGetModuleClkCtrl(Uint32 moduleId)
{
#ifndef BIOS_BUILD
    CSL_PscRegsOvly     pscRegs;

    if ((moduleId < PAL_SYS_CLK_MODULE_MIN) || (moduleId > PAL_SYS_CLK_MODULE_MAX)) {
        return(PAL_SYS_MODULE_CLK_DISABLE);
    }

    pscRegs = (CSL_PscRegsOvly)CSL_PSC_REGS;
    if ((pscRegs->MDSTAT[moduleId] & CSL_PSC_MDSTAT_STATE_MASK) == PAL_SYS_CLK_MODULE_STATE_ENABLE) {
        return(PAL_SYS_MODULE_CLK_ENABLE);
    } else {
        return(PAL_SYS_MODULE_CLK_DISABLE);
    }
#else
    return((PAL_SysModuleClkControl)-1);
#endif
}





/*****************************************************************************
 * RTC Control
 *****************************************************************************/




 /**
 *  \brief RTC Init
 *
 *  Init function for RTC.
 *
 *  \param  param[IN]
 *  \return
 */
void PAL_sysRtcInit(void* param)
{

}

 /**
 *  \brief RTC DeInit
 *
 *  DeInit function for RTC.
 *
 *  \param  param[IN]
 *  \return
 */
void PAL_sysRtcDeInit(void* param)
{

}
 /**
 *  \brief Set time to RTC
 *
 *  Set time to RTC
 *
 *  \param  rtcTime[IN]   current time to be set to RTC
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysRtcSetTime(PAL_SysRtctime* rtcTime)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

 /**
 *  \brief Get current time from RTC
 *
 *  Get current time from RTC
 *
 *  \param  rtcTime[OUT]   current time
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysRtcGetTime(PAL_SysRtctime* rtcTime)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}

/**
 *  \brief RTC Control
 *
 *  It is used provides RTC control functionalties .
 *
 *  \param   rtcIoctl[IN]               timer Ioctl
 *  \param  arg [IN/OUT]                argument for Ioctl
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysRtcCtrl(Uint32 timerId,PAL_SysRtcIoctl rtcIoctl, void *arg)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}



/*****************************************************************************
 * RTC Control
 *****************************************************************************/

/**
 *  \brief WatchDog Init
 *
 *  Init function for WatchDog.
 *
 *  \param  param[IN]
 *  \param  wdgInstId[IN]    Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgInit (Uint32 wdgInstId,void* param)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}



/**
 *  \brief WatchDog DeInit
 *
 *  DeInit function for WatchDog.
 *
 *  \param  param[IN]
 *  \param  wdgInstId[IN]    Wdg instanceId
 *  \return
 */
void PAL_sysWdgDeInit (Uint32 wdgInstId,void *param)
{

}



 /**
 *  \brief Set time to Wdg
 *
 *  Set time to Wdg
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \param  time[IN]        time to be set to Wdg
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgSetTimeOut (Uint32 wdgInstId, PAL_sysWdgTime *time)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}



 /**
 *  \brief Get time to Wdg
 *
 *  Get time to Wdg
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \param  time[OUT]       time
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgGetTimeOut (Uint32 wdgInstId, PAL_sysWdgTime *time)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}




 /**
 *  \brief Pet the Watch Dog, to avoid Reset
 *
 *  Pet the Watch Dog, to avoid Reset
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgKeepAlive (Uint32 wdgInstId)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}





 /**
 *  \brief Enable the Watch Dog
 *
 *  Enable the Watch Dog. This function returns error if the
 *  Count loaded is Zero
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgEnable (Uint32 wdgInstId)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}



 /**
 *  \brief Disable the Watch Dog
 *
 *  Disable the Watch Dog.
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgDisable (Uint32 wdgInstId)
{
    return PAL_SYS_ERROR_NOT_SUPPORTED;
}
/*****************************************************************************
 * MISC
 *****************************************************************************/

 /**
 *  \brief Get chip vesrion info
 *
 *  It is used to chip vesrion info.
 *
 *  \param   verInfo[IN]                verInfo
 *  \return Pointer to chip info
 */
char *PAL_sysGetChipVersionInfo(PAL_SysVersionInfo *verInfo)
{
    return NULL;
}

