/*
*********************************************************************************************************
*                                               OS_CPU_C.C
*
*   Copyright 2003, Validated Software Corporation, Lafayette, CO
*   All Rights Reserved
*
*   Author:     Scott N.
*   Date:       August 2006
*
*   References:
*   $Workfile: OS_CPU_C.C $
*
*   Description:    These are the C level OS support routines
*                   for the TMS320C55xx port on Code Composer Studio
*
*   Contents:
*
*   Revision History - latest change on top
*
*   $Log:  $
*
*********************************************************************************************************
*/
#pragma DATA_ALIGN( OSTaskIdle_SStk, 2)
#pragma DATA_ALIGN( OSTaskStat_SStk, 2)

#define  OS_CPU_GLOBALS

#include "zen.h"

/*
 * The following defines are from the chip support library
 */
#define TSS             4
#define ARB             5
#define TLB             10

#define PRD0            *(ioport volatile unsigned int *)0x1001
#define TCR0            *(ioport volatile unsigned int *)0x1002
#define PRSC0           *(ioport volatile unsigned int *)0x1003

typedef unsigned short  Uint16;

//      Load TCR0 such that:
//      IDLE_EN = 0 (No idle mode)
//      FUNC = 01b (Pin reflects timer output)
//      TLB = 1 (Load TIM and PSC until TLB = 0)
//      FREE = 1 (Timer not stopped by breakpoints)
//      PWID = 01b (Pulses on pin last 2 CPU clock cycles)
//      ARB = 1 (Reload TIM and PSC when TIM reaches 0)
//      TSS = 1 (Stop timer)
//      C/P = 0 (Pulse mode selected for pin)
//      POLAR = 0 (Signal on pin starts low, pulses high)
//      Other bits contain 0s
#define TCR_RUN     0x0ce8

//
// Interrupt enable values
//
#define EN_TINT0    0x10        //   Timer Int0
#define BERRINTE    0x100       //   Bus error int

extern	OS_STK	*ptoSSsav;
extern  OS_STK  *pbossav;

#define OS_TASK_IDLE_SSTK_SIZE   256
#define OS_TASK_STAT_SSTK_SIZE   256

    OS_STK  OSTaskIdle_SStk[OS_TASK_IDLE_STK_SIZE];      /* Idle task SS stack                */
    OS_STK  OSTaskStat_SStk[OS_TASK_STAT_SSTK_SIZE];     /* Stat task SS stack                */


/*$PAGE*/
#if OS_CPU_HOOKS_EN
/*
*********************************************************************************************************
*                                          TASK CREATION HOOK
*
* Description: This function is called when a task is created.
*
* Arguments  : ptcb   is a pointer to the task control block of the task being created.
*
* Note(s)    : 1) Interrupts are disabled during this call.
*********************************************************************************************************
*/
void OSTaskCreateHook (OS_TCB *ptcb)
{
    if ( ptcb->OSTCBPrio == OS_TASK_IDLE_PRIO )
    {
        ptoSSsav = &OSTaskIdle_SStk[OS_TASK_IDLE_SSTK_SIZE - 1];
    }
    else if ( ptcb->OSTCBPrio == OS_TASK_STAT_PRIO )
    {
        ptoSSsav = &OSTaskStat_SStk[OS_TASK_STAT_SSTK_SIZE - 1];
    }
    else
    {
        ptoSSsav = ptcb->OSTCBExtPtr;
    }

    //
    // The tcb's stack doesn't exist yet.  Use the following trap to create it.
    //
//    asm("   TRAP    #5");           // Cause a software interrupt
    asm("   trap(#5) ");           // Cause a software interrupt
    ptcb->OSTCBStkPtr = pbossav;    // Update the tcb's stack pointer
}

void OSInitHookBegin(void)       /* Call port specific initialization code   */
{
}

void OSInitHookEnd(void)       /* Call port specific initialization code   */
{
}

void OSTaskIdleHook(void)       /* Call port specific initialization code   */
{
}

void OSTCBInitHook(OS_TCB *foo)       /* Call port specific initialization code   */
{
	foo = foo;
}

/*
*********************************************************************************************************
*                                           TASK DELETION HOOK
*
* Description: This function is called when a task is deleted.
*
* Arguments  : ptcb   is a pointer to the task control block of the task being deleted.
*
* Note(s)    : 1) Interrupts are disabled during this call.
*********************************************************************************************************
*/
void OSTaskDelHook (OS_TCB *ptcb)
{
    ptcb = ptcb;                       /* Prevent compiler warning                                     */
}

/*
*********************************************************************************************************
*                                           TASK SWITCH HOOK
*
* Description: This function is called when a task switch is performed.  This allows you to perform other
*              operations during a context switch.
*
* Arguments  : none
*
* Note(s)    : 1) Interrupts are disabled during this call.
*              2) It is assumed that the global pointer 'OSTCBHighRdy' points to the TCB of the task that
*                 will be 'switched in' (i.e. the highest priority task) and, 'OSTCBCur' points to the
*                 task being switched out (i.e. the preempted task).
*********************************************************************************************************
*/
void OSTaskSwHook (void)
{
}

/*
*********************************************************************************************************
*                                           STATISTIC TASK HOOK
*
* Description: This function is called every second by uC/OS-II's statistics task.  This allows your
*              application to add functionality to the statistics task.
*
* Arguments  : none
*********************************************************************************************************
*/
void OSTaskStatHook (void)
{
}

/*
*********************************************************************************************************
*                                               TICK HOOK
*
* Description: This function is called every tick.
*
* Arguments  : none
*
* Note(s)    : 1) Interrupts may or may not be ENABLED during this call.
*********************************************************************************************************
*/
void OSTimeTickHook (void)
{
}
#endif


/*
*********************************************************************************************************
*                                               OSTimerInit
*
* Description: This function initializes Timer 0.
*
* Arguments  : none
*
*********************************************************************************************************
*/
void timerInit(void)
{
	int	tmp;

//    TIMER_INIT(0, TCR_RUN, 49999, 11);
    TCR0 |= (1<<TSS);       // Timer halt
    TCR0 = TCR_RUN;         // Set control register
    PRD0 = 49999;           //
    PRSC0 = 11;             // Set prescaler

    TCR0 |= (1<<TSS);       // Timer halt
    TCR0 |= (1<<ARB) | (1<<TLB);
    TCR0 &= ~(1<<TLB);

    TCR0 &= ~(1<<TSS);      // Timer start

    // Enable the Timer 0 interrupt
    //lint -e413 Suppress probable NULL pointer warning
    tmp = (int)((Uint16)(*(volatile Uint16*)(0x0000u)));
    tmp |= EN_TINT0;
    (*(volatile Uint16*)(0x0000u))=(Uint16)(tmp);
    //lint +e413 Reenable probable NULL pointer warning

    // Enable the Bus Error interrupt
    tmp = (int)((Uint16)(*(volatile Uint16*)(0x0045u)));
    tmp |= BERRINTE;
    (*(volatile Uint16*)(0x0045u))=(Uint16)(tmp);

    // Clear any pending interrupt flags
    (*(volatile Uint16*)(0x0001u))=(Uint16)(0);
    (*(volatile Uint16*)(0x0001u))=(Uint16)(0);
}

