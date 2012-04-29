/*
*********************************************************************************************************
*                                               uC/OS-II
*                                        The Real-Time Kernel
*
*                         (c) Copyright 1992-2002, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
* File         : OS_CPU.H
* By           : Jean J. Labrosse
*
*   Additional Copyright 2003, Validated Software Corporation, Lafayette, CO
*   All Rights Reserved
*
*   Modified by:    Mark Scott-Nash
*   Date:           03-Sep-03
*
*
*********************************************************************************************************
*/

#ifdef OS_GLOBALS
#pragma DATA_ALIGN( OSTaskIdleStk, 2)
#endif

#define OS_ISR_PROTO_EXT 1
/*
*********************************************************************************************************
*                                              DATA TYPES
*                                         (Compiler Specific)
*********************************************************************************************************
*/

typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                    /* Unsigned  8 bit quantity                           */
typedef signed   char  INT8S;                    /* Signed    8 bit quantity                           */
typedef unsigned short INT16U;                   /* Unsigned 16 bit quantity                           */
typedef signed   short INT16S;                   /* Signed   16 bit quantity                           */
typedef unsigned long  INT32U;                   /* Unsigned 32 bit quantity                           */
typedef signed   long  INT32S;                   /* Signed   32 bit quantity                           */
typedef float          FP32;                     /* Single precision floating point                    */
typedef double         FP64;                     /* Double precision floating point                    */

typedef unsigned int   OS_STK;                   /* Each stack entry is 32-bit wide                    */
typedef unsigned int   OS_CPU_SR;                /* Define size of CPU status register (PSR = 32 bits) */

/*
*********************************************************************************************************
*                                              320VC5509
*
* Method #1:  NOT IMPLEMENTED
*             Disable/Enable interrupts using simple instructions.  After critical section, interrupts
*             will be enabled even if they were disabled before entering the critical section.
*
* Method #2:  NOT IMPLEMENTED
*             Disable/Enable interrupts by preserving the state of interrupts.  In other words, if
*             interrupts were disabled before entering the critical section, they will be disabled when
*             leaving the critical section.
*             NOT IMPLEMENTED
*
* Method #3:  Disable/Enable interrupts by preserving the state of interrupts.  Generally speaking you
*             would store the state of the interrupt disable flag in the local variable 'cpu_sr' and then
*             disable interrupts.  'cpu_sr' is allocated in all of uC/OS-II's functions that need to
*             disable interrupts.  You would restore the interrupt disable state by copying back 'cpu_sr'
*             into the CPU's status register.  This is the prefered method to disable interrupts.
*********************************************************************************************************
*/

#define  OS_CRITICAL_METHOD    3


#if      OS_CRITICAL_METHOD == 3
#define  OS_ENTER_CRITICAL()  (cpu_sr = OS_CPU_SaveSR())  /* Disable interrupts                        */
#define  OS_EXIT_CRITICAL()   (OS_CPU_RestoreSR(cpu_sr))  /* Restore  interrupts                       */
#endif


// Interrupt controller registers

/*
*********************************************************************************************************
*                                         C5509 Miscellaneous
*********************************************************************************************************
*/

#define  OS_STK_GROWTH        1                       /* Stack grows from HIGH to LOW memory on DSP    */

#define  OS_TASK_SW()         asm("   TRAP    #26");

/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/

OS_CPU_EXT  INT32U  OSIntCtxSwFlag;                   /* Used to flag a context switch                 */

/*
*********************************************************************************************************
*                                              PROTOTYPES
*********************************************************************************************************
*/

void IRQStackInit(void);

#if OS_CRITICAL_METHOD == 3                           /* Allocate storage for CPU status register      */
OS_CPU_SR  OS_CPU_SaveSR(void);
void       OS_CPU_RestoreSR(OS_CPU_SR cpu_sr);
#endif


void       OS_CPU_Init(void);
void       OS_CPU_InitTick(void);

void       OS_CPU_IRQ_ISR(void);
void       OS_CPU_IRQ_Handler(void);

void       OS_CPU_FIQ_ISR(void);
void       OS_CPU_FIQ_Handler(void);

void	   OSTimerInit(void);
