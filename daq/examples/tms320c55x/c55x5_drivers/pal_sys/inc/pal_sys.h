/*
 * $$$MODULE_NAME pal_sys.h
 *
 * $$$MODULE_DESC pal_sys.h
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This software is licensed under the  standard terms and conditions in the Texas Instruments  Incorporated
 *  Technology and Software Publicly Available Software License Agreement , a copy of which is included in the
 *  software download.
*/

/**
 *  \file   pal_sys.h
 *
 *  \brief  PAL SYS SoC level API header file
 *
 *  This file defines data types and services (macros as well as functions)
 *  that are applicable to the abstracted h/w system (SoC/Board).
 *
 *  (C) Copyright 2005, Texas Instruments, Inc
 *
 *  \version    1.0     PSP Architecture Team   Created
 */



#ifndef _PAL_SYS_H_
#define _PAL_SYS_H_


#include <psp_common.h>
#include "pal_sys_soc.h"



/**
 * \defgroup PAL SYS Interface Definitions
 *
 * All interface definitions for PAL SYS are contained in this file.
 *
 * @{
 */
#define PAL_SYS_COMMON_ERR   (0)

/* Common error codes for ALL PAL OS modules */
#define PAL_SYS_COMMON_ERROR_CREATE(x)   (PAL_ERROR(PAL_CRITICAL_ERROR, PAL_SYS_COMMON_ERR, 0, (x)))

/* Invalid parameter passed to the function error */
#define PAL_SYS_ERROR_INVALID_PARAM      (PAL_SYS_COMMON_ERROR_CREATE(1))

/* Feature not supported error */
#define PAL_SYS_ERROR_NOT_SUPPORTED      (PAL_SYS_COMMON_ERROR_CREATE(2))

/* No resources available error */
#define PAL_SYS_ERROR_NO_RESOURCES       (PAL_SYS_COMMON_ERROR_CREATE(3))

/* Timeout from the OS call */
#define PAL_SYS_ERROR_TIMEOUT            (PAL_SYS_COMMON_ERROR_CREATE(4))



/*****************************************************************************
 * Reset Control Module
 *****************************************************************************/
/**
 *  \brief  Reset Ctrl options
 *
 *  Reset Ioctl options
 */
typedef enum
{
    PAL_SYS_IN_RESET        = 0,
    PAL_SYS_OUT_OF_RESET
} PAL_sysResetControl;

/*****************************************************************************
 * WatchDog Control
 *****************************************************************************/
 /**
 *  \brief  WatchDog  struct
 *
 *  Structure to define the Count to be loaded to watch Dog Module
 */
typedef struct {
        Uint32  lsb;
        Uint32  msb;
} PAL_sysWdgTime;

/*****************************************************************************
 * RTC Control
 *****************************************************************************/

  /**
 *  \brief  RTC Time struct
 *
 *  RTC Time struct
 */
typedef struct
{
    Uint16  rtc_year;
    Uint8   rtc_month;
    Uint8   rtc_day;
    Uint8   rtc_hour;
    Uint8   rtc_minute;
    Uint8   rtc_second;
}PAL_SysRtctime;


/*****************************************************************************
 * CLKC Control
 *****************************************************************************/
 typedef enum
{
    PAL_SYS_MODULE_CLK_ENABLE = 0u,
    PAL_SYS_MODULE_CLK_DISABLE
}PAL_SysModuleClkControl;

/*****************************************************************************
 * GPIO Control
 *****************************************************************************/

 /**
 *  \brief  GPIO pin mode
 *
 *  Pin mode for GPIO
 */
typedef enum
{
    FUNCTIONAL_PIN = 0,
    GPIO_PIN = 1
} PAL_SysGpioPinMode;

/**
 *  \brief  GPIO pin direction
 *
 *  Direction for GPIO pin
 */
typedef enum PAL_SYS_GPIO_PIN_DIRECTION_tag
{
    GPIO_OUTPUT_PIN = 0,
    GPIO_INPUT_PIN = 1
} PAL_SysGpioPinDirection;


/*****************************************************************************
 * Power Control Module
 *****************************************************************************/
typedef enum
{
    PAL_SYS_POWER_CTRL_POWER_UP = 0,
    PAL_SYS_POWER_CTRL_POWER_DOWN
} PAL_sysPowerControl;

/**
 *  \brief Reset Ctrl
 *
 *  This function provides reset Ctrl functionality.
 *
 *  \param  resetModuleId [IN]          module Id
 *  \param  resetIoctl [IN]             reset Ctrl
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysResetCtrl(Uint32 resetModuleId,PAL_sysResetControl resetCtrl);

/**
 *  \brief Get the status of module Reset
 *
 *  This function get provides reset state.
 *
 *  \param  resetModuleId [IN]          module Id
  *  \return PAL_sysResetControl
 */
PAL_sysResetControl PAL_sysGetResetStatus(Uint32 resetModuleId);

/**
 *  \brief perform system reset
 *
 *  This function performs system reset.
 *
 *  \param  mode[IN]        reset mode
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysSystemReset(PAL_SysSystemRstMode mode);

/**
 *  \brief perform system reset
 *
 *  This function performs system reset.
 *
 *  \param
 *  \return PAL_SysSystemResetStatus
 */
PAL_SysSystemResetStatus PAL_sysGetSysLastResetStatus(void);

/**
 *  \brief Module Power Ctrl
 *
 *  This function provides module power control functionality.
 *
 *  \param  powerModule [IN]            module Id
 *  \param  powerIoctl [IN]             power Ctrl
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysPowerCtrl(Uint32 powerModule,  PAL_sysPowerControl powerCtrl);

/**
 *  \brief Get Module Power Status
 *
 *  This function provides module power control functionality.
 *
 *  \param  powerModule [IN]            module Id
 *  \return PAL_sysPowerControl
 */
PAL_sysPowerControl PAL_sysGetPowerStatus(Uint32 powerModule);

/**
 *  \brief Set Global Power Mode
 *
 *  This function sets global power mode.
 *
 *  \param  powerMode [IN]        power mode
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysSetGlobalPowerMode(PAL_SysSysytemPowerMode powerMode);

/**
 *  \brief Get Global Power mode
 *
 *  This function provides global power mode.
 *
 *  \param
 *  \return PAL_SysSysytemPowerMode
 */
PAL_SysSysytemPowerMode PAL_sysGetGlobalPowerMode(void);

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
                         PAL_SysWakeupPolarity wakeupPolarity);

/**
 *  \brief GPIO Init
 *
 *  Init function for GPIO.
 *
 *  \param
 *  \return
 */
void PAL_sysGpioInit(void);


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
                      PAL_SysGpioPinDirection pinDirection);

/**
 *  \brief GPIO pin Out
 *
 *  It is used to set value to one GPIO pin.
 *
 *  \param   gpioPin[IN]        GPIO Pin number
 *  \param   value[IN]          value to be set on GPIO pin
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysGpioOutBit(Uint32 gpioPin, int value);

/**
 *  \brief GPIO pin In
 *
 *  It is used to get value at one GPIO pin.
 *
 *  \param   gpioPin[IN]        GPIO Pin number
 *  \return value at GPIO pin
 */
Int PAL_sysGpioInBit(Uint32 gpioPin);

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
                           Uint32 regIndex);

/**
 *  \brief Get value of group of GPIO Pin
 *
 *  It is used to get value of group of GPIO Pin.
 *
 *  \param   inVal[IN]          vale of group of GPIO pin
 *  \param   regIndex[IN]       Index of register
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysGpioInValue(Uint32 *inVal, Uint32 regIndex);

 /**
 *  \brief Clock Init
 *
 *  Init function for Clock.
 *
 *  \param  param[IN]
 *  \return
 */
void PAL_sysClkcInit(void* param);

/**
 *  \brief Set frequency to clock
 *
 *  It is used to set frequncy to clock .
 *
 *  \param   clkId[IN]          Clock Id
 *  \param   outputFreq[IN]     frequency
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysClkcSetFreq(Uint32 clkId, Uint32 outputFreq);

/**
 *  \brief Get Clock frequency
 *
 *  It is used to get frequncy of clock .
 *
 *  \param   clkId[IN]          Clock Id
 *  \return Clock frequency
 */
Int PAL_sysClkcGetFreq(Uint32 clkId);

/**
 *  \brief Module Clock Control
 *
 *  It is used provides module clock control functionalties .
 *
 *  \param   moduleId[IN]               module Id
 *  \param   clkIoctl[IN]               Clock Ctrl
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysModuleClkCtrl(Uint32 moduleId,PAL_SysModuleClkControl clkCtrl);

/**
 *  \brief Get Status of Module Clock
 *
 *  It is used provides module clock control functionalties .
 *
 *  \param   moduleId[IN]               module Id
 *  \return PAL_SysModuleClkControle
 */
PAL_SysModuleClkControl PAL_sysGetModuleClkCtrl(Uint32 moduleId);

 /**
 *  \brief RTC Init
 *
 *  Init function for RTC.
 *
 *  \param  param[IN]
 *  \return
 */
void PAL_sysRtcInit(void* param);

 /**
 *  \brief RTC DeInit
 *
 *  DeInit function for RTC.
 *
 *  \param  param[IN]
 *  \return
 */
void PAL_sysRtcDeInit(void* param);

 /**
 *  \brief Set time to RTC
 *
 *  Set time to RTC
 *
 *  \param  rtcTime[IN]   current time to be set to RTC
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysRtcSetTime(PAL_SysRtctime* rtcTime);

 /**
 *  \brief Get current time from RTC
 *
 *  Get current time from RTC
 *
 *  \param  rtcTime[OUT]   current time
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysRtcGetTime(PAL_SysRtctime* rtcTime);

/**
 *  \brief RTC Control
 *
 *  It is used provides RTC control functionalties .
 *
 *  \param   rtcIoctl[IN]               timer Ioctl
 *  \param  arg [IN/OUT]                argument for Ioctl
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysTimerCtrl(Uint32 timerId,PAL_SysRtcIoctl rtcIoctl, void *arg);

/**
 *  \brief WatchDog Init
 *
 *  Init function for WatchDog.
 *
 *  \param  param[IN]
 *  \param  wdgInstId[IN]    Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgInit (Uint32 wdgInstId,void* param);

/**
 *  \brief WatchDog DeInit
 *
 *  DeInit function for WatchDog.
 *
 *  \param  param[IN]
 *  \param  wdgInstId[IN]    Wdg instanceId
 *  \return
 */
 void PAL_sysWdgDeInit (Uint32 wdgInstId,void *param);

 /**
 *  \brief Set time to Wdg
 *
 *  Set time to Wdg
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \param  time[IN]        time to be set to Wdg
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgSetTimeOut (Uint32 wdgInstId, PAL_sysWdgTime *time);

 /**
 *  \brief Get time to Wdg
 *
 *  Get time to Wdg
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \param  time[OUT]       time
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgGetTimeOut (Uint32 wdgInstId, PAL_sysWdgTime *time);

 /**
 *  \brief Pet the Watch Dog, to avoid Reset
 *
 *  Pet the Watch Dog, to avoid Reset
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgKeepAlive (Uint32 wdgInstId);

 /**
 *  \brief Enable the Watch Dog
 *
 *  Enable the Watch Dog. This function returns error if the
 *  Count loaded is Zero
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgEnable (Uint32 wdgInstId);

 /**
 *  \brief Disable the Watch Dog
 *
 *  Disable the Watch Dog.
 *
 *  \param  wdgInstId[IN]   Wdg instanceId
 *  \return PSP_SOK or PSP Error code
 */
PAL_Result PAL_sysWdgDisable (Uint32 wdgInstId);

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
char *PAL_sysGetChipVersionInfo(PAL_SysVersionInfo *verInfo);

#endif
