/*
 * $$$MODULE_NAME pal_sys_soc.h
 *
 * $$$MODULE_DESC pal_sys_soc.h
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This software is licensed under the  standard terms and conditions in the Texas Instruments  Incorporated
 *  Technology and Software Publicly Available Software License Agreement , a copy of which is included in the
 *  software download.
*/

/**
 *  \file   pal_sys_soc.h
 *
 *  \brief  defines data structure specfic to SoC
 *
 *  This file defines data types and services (macros as well as functions)
 *  that are applicable to the abstracted h/w system (SoC/Board).
 *
 *  (C) Copyright 2005, Texas Instruments, Inc
 *
 *  \version    1.0     PSP Architecture Team   Created
 */

#ifndef __PAL_SYS_SOC_H__
#define __PAL_SYS_SOC_H__

#include <tistdtypes.h>
/**
 * \defgroup PAL SYS SoC specific Data structure
 *
 * All Data structure are specific to SoC and it will be required to
 * redefine these all when move from one SoC to another.
 *
 * @{
 */


/*****************************************************************************
 * Reset Control Module
 *****************************************************************************/
#define PAL_SYS_RESET_UART 1U
#define PAL_SYS_RESET_I2C 2U
#define PAL_SYS_RESET_SPI 3U


/**
 *  \brief  System Reset  Mode
 *
 *  System Reset  Mode
 */
typedef enum
{
    PAL_SYS_RESET_SOC_NOT_DEFINED      = 1
} PAL_SysSystemRstMode;

/**
 *  \brief  System Reset  status
 *
 *  System Reset  status
 */
typedef enum
{
    PAL_SYS_HARDWARE_RESET_NOT_DEFINED = 0
} PAL_SysSystemResetStatus;



/*****************************************************************************
 * Power Control Module
 *****************************************************************************/
#define PAL_SYS_PWR_MODULE_DSP  1U
#define PAL_SYS_PWR_MODULE_ARM  2U



/**
 *  \brief  System Power  Mode
 *
 *  System Power Mode
 */
typedef enum
{
    PAL_SYS_GLOBAL_POWER_MODE__NOT_DEFINED       = 0
} PAL_SysSysytemPowerMode;

/*****************************************************************************
 * Wakeup Control
 *****************************************************************************/

 /**
 *  \brief  Wake Intrrupt number
 *
 *  Wake Intrrupt number
 */
typedef enum
{
    PAL_SYS_WAKEUP_INT0_NOT_DEFINED = 1
} PAL_SysWakeupInterrupt;

 /**
 *  \brief  Wake Intrrupt Control
 *
 *  Wake Intrrupt Control
 */
typedef enum
{
    PAL_SYS_WAKEUP_DISABLED = 0,
    PAL_SYS_WAKEUP_ENABLED
} PAL_SysWakeupCtrl;

 /**
 *  \brief  Wake Polarity
 *
 *  Wake Polarity
 */
typedef enum
{
    PAL_SYS_WAKEUP_ACTIVE_HIGH = 0,
    PAL_SYS_WAKEUP_ACTIVE_LOW
} PAL_SysWakeupPolarity;

/*****************************************************************************
 * GPIO Control
 *****************************************************************************/

#define PAL_SYS_GPIO1_PIN1
#define PAL_SYS_GPIO1_PIN2
#define PAL_SYS_GPIO1_PIN3

#define PAL_SYS_GPIO2_PIN1
#define PAL_SYS_GPIO2_PIN2
#define PAL_SYS_GPIO2_PIN3


/**
 * \brief Power/Clock control numbers for PSC Module
 *
 *  Once the device power is turned on, all the subsystes and peripherals are
 *  applied with power. Each m odule may have its own power down modes, the
 *  module  specific power down mode is covered in module specs. For normal
 *  operation the PSC takes the modules out of reset and enables clocks to the
 *  modules. Followin are the peripherals under PSC control. Each of the
 *  peripherals is assigned a power control number which is associated with
 *  the PSC registers.
 */
#define PAL_SYS_CLK_MODULE_MIN          (1u)
#define PAL_SYS_CLK_MODULE_DSP          (1u)
#define PAL_SYS_CLK_MODULE_EDMATPCC     (2u)
#define PAL_SYS_CLK_MODULE_EDMATPTC0    (3u)
#define PAL_SYS_CLK_MODULE_EDMATPTC1    (4u)
#define PAL_SYS_CLK_MODULE_EDMATPTC2    (5u)

#define PAL_SYS_CLK_MODULE_MCASP0       (6u)
#define PAL_SYS_CLK_MODULE_MCASP1       (7u)
#define PAL_SYS_CLK_MODULE_MCASP2       (8u)
#define PAL_SYS_CLK_MODULE_MCASP3       (9u)

#define PAL_SYS_CLK_MODULE_DARTE        (10u)
#define PAL_SYS_CLK_MODULE_SPDIFDOR     (11u)
#define PAL_SYS_CLK_MODULE_RTI1         (12u)
#define PAL_SYS_CLK_MODULE_EMIFA        (13u)
#define PAL_SYS_CLK_MODULE_EMIFB        (14u)

#define PAL_SYS_CLK_MODULE_VPSS         (15u)
#define PAL_SYS_CLK_MODULE_LCD          (16u)
#define PAL_SYS_CLK_MODULE_VCP          (17u)

#define PAL_SYS_CLK_MODULE_UART1        (18u)
#define PAL_SYS_CLK_MODULE_UART2        (19u)
#define PAL_SYS_CLK_MODULE_UART0        (20u)
#define PAL_SYS_CLK_MODULE_UART3        (21u)

#define PAL_SYS_CLK_MODULE_I2C0         (22u)
#define PAL_SYS_CLK_MODULE_I2C1         (23u)
#define PAL_SYS_CLK_MODULE_I2C2         (24u)
#define PAL_SYS_CLK_MODULE_I2C3         (25u)

#define PAL_SYS_CLK_MODULE_ECAP0        (26u)
#define PAL_SYS_CLK_MODULE_ECAP1        (27u)
#define PAL_SYS_CLK_MODULE_ECAP2        (28u)
#define PAL_SYS_CLK_MODULE_ECAP3        (29u)
#define PAL_SYS_CLK_MODULE_ECAP4        (30u)
#define PAL_SYS_CLK_MODULE_ECAP5        (31u)
#define PAL_SYS_CLK_MODULE_ECAP6        (32u)
#define PAL_SYS_CLK_MODULE_ECAP7        (33u)
#define PAL_SYS_CLK_MODULE_HECC0        (34u)
#define PAL_SYS_CLK_MODULE_SPI1         (35u)
#define PAL_SYS_CLK_MODULE_SPI2         (36u)
#define PAL_SYS_CLK_MODULE_SPI3         (37u)
#define PAL_SYS_CLK_MODULE_HECC1        (38u)
#define PAL_SYS_CLK_MODULE_ATA          (39u)
#define PAL_SYS_CLK_MODULE_UHPI         (40u)
#define PAL_SYS_CLK_MODULE_USB          (41u)
#define PAL_SYS_CLK_MODULE_GPIO         (42u)
#define PAL_SYS_CLK_MODULE_SPI0         (43u)
#define PAL_SYS_CLK_MODULE_ECC          (44u)
#define PAL_SYS_CLK_MODULE_CRC          (45u)
#define PAL_SYS_CLK_MODULE_RTI2         (46u)
#define PAL_SYS_CLK_MODULE_MMCSD        (47u)
#define PAL_SYS_CLK_MODULE_MS           (48u)
#define PAL_SYS_CLK_MODULE_VLYNQ        (49u)
#define PAL_SYS_CLK_MODULE_ALT          (50u)
#define PAL_SYS_CLK_MODULE_MAX          (51u)

/** Module state */
#define PAL_SYS_CLK_MODULE_STATE_ENABLE     (0x3u)
#define PAL_SYS_CLK_MODULE_STATE_DISABLE    (0x2u)

#define PAL_SYS_CLK_MODULE_TIMEOUT          (0x3FFF)
/*****************************************************************************
 * Timer Control
 *****************************************************************************/

 /**
 *  \brief  Timer Ioctl Param
 *
 *  Timer Ioctl Param
 */
typedef enum
{
    PAL_SYS_IOCTLE_TIMER_SET_COUNT_DIRECTION = 0,
    PAL_SYS_IOCTLE_TIMER_GET_COUNT_DIRECTION,
    PAL_SYS_IOCTLE_SET_TIMER_SET_TICK_RELOAD,
    PAL_SYS_IOCTLE_SET_TIMER_GET_TICK_RELOAD
}
PAL_SysTimerIoctl;


/*****************************************************************************
 * RTC Control
 *****************************************************************************/

 /**
 *  \brief  Timer Ioctl Param
 *
 *  Timer Ioctl Param
 */
typedef enum
{
    PAL_SYS_IOCTLE_RTC_SET_HOUR_FORMAT = 0,
    PAL_SYS_IOCTLE_RTC_GET_HOUR_FORMAT
}
PAL_SysRtcIoctl;

/*****************************************************************************
 * MISC
 *****************************************************************************/

 /**
 *  \brief  Chip Info
 *
 *  Chip Info
 */
typedef struct
{
    Uint32 chipInfo;
    Uint32 versionId;
}PAL_SysVersionInfo;

#endif
