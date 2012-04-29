/* $Header: /MicroC-OSII/UC00/Source/IntegrationTests/Src/demo.c 4     2/03/06 3:04p Gkilley $
 *****************************************************************************
 *                       PROCESSOR PORT uC/OS-II Demo Code
 *
 *   Copyright 2005, 2006, Validated Software Corporation, Lafayette, CO
 *   					All Rights Reserved
 *
 *   Author:     Grant Killey
 *   Date:       21-Dec-05
 *
 *   References:
 *   $Workfile: demo.c $
 *
 *   Description:    This is a set of general purpose demonstration routines
 *                   for use on any port of MicroC/OS-II
 *
 *   Contents:
 *              main()
 *				initSems()
 *				createTasks()
 *              TaskStart()
 *              Tasksecond()
 *              Taskthird()
 *              CheckErr()
 *              SystemHalt()
 *
 *   Revision History - latest change on top
 *
 *   $Log: /MicroC-OSII/UC00/Source/IntegrationTests/Src/demo.c $
 *
 * 4     2/03/06 3:04p Gkilley
 * Changes for new style and additional parameter checking by Micrium
 *
 * 3     1/24/06 10:01a Scott
 * Non-functional change/layout clean up.
 *
 * 2     1/24/06 9:39a Gkilley
 * Cleanup, force type on "char"
 *
 *
 *****************************************************************************
 */
#include "zen.h"

#include <stdio.h>

/*****************************************************************************
 *                            	CONSTANTS
 *****************************************************************************
 */
#define FORCE_ERROR         -1      // Force an error for CheckErr function

#define TASK_START_PRIO     1
#define TASK_SECOND_PRIO    2
#define TASK_THIRD_PRIO     3

#if OS_TASK_STAT_EN > 0
#define TASK_OPTIONS        (OS_TASK_OPT_STK_CLR + OS_TASK_OPT_STK_CHK)
#else
#define TASK_OPTIONS        0
#endif

const   INT32U              Tasksecondarg = 0x12345678;
const   INT32U              Taskthirdarg = 0x55AA6699;

/*****************************************************************************
 *                              VARIABLES
 *****************************************************************************
 */

/* Enable the following section if the processor/toolset require and support
 * data alignment.  Modify the pragma/method as needed.
 */
#ifdef _TMS320C6400
// These are special for TI 6400 only.
#pragma DATA_ALIGN(TaskStartStk, 8);
#pragma DATA_ALIGN(Task2Stk, 8);
#pragma DATA_ALIGN(Task3Stk, 8);
#endif

#define TASK_STK_SIZE   512

OS_STK			Task2Stk[TASK_STK_SIZE];
OS_STK  		Task3Stk[TASK_STK_SIZE];
OS_STK  		TaskStartStk[TASK_STK_SIZE];
OS_EVENT		*MySem;
OS_EVENT    	*TxMbox;
volatile INT32U	stop_count;

/*****************************************************************************
 *                    FUNCTION PROTOTYPES
 *****************************************************************************
 */
INT8U 	createTasks(void);
void 	initSems(void);
void    TaskStart(void *pdata);
void    Tasksecond(void *pdata);
void    Taskthird(void *pdata);
void    CheckErr(INT8S err, char *s);
void    SystemHalt(void);

/*****************************************************************************
 * Function:	main()
 *
 * Description: Initializes the OS and tasks then starts the OS, never returning
 *
 *****************************************************************************
 */
void main (void)
{
    pll_init(120);          // Set the 5509 to 120MHz

    printf("\n\nDemonstration of uC/OS-II running three tasks.\n\n");
    printf("Initializing uC/OS-II.\n");
    OSInit();           // Initialize MicroScheduler

    printf("Initializing semiphores and mailboxes...\n");
    initSems();         // Does not return if error occurs

    printf("Creating tasks...\n");
    createTasks();      // Does not return if error occurs

    printf("Starting uC/OS-II.\n");
	OSStart(); 			// Start multitasking THIS NEVER RETURNS!!!

    CheckErr(FORCE_ERROR, "FATAL return from OSStart");
} /* End Of Function: main() */


/*****************************************************************************
 * Function:	createTasks()
 *
 * Description: Create a semaphore and a mailboxes for our test tasks.
 *
 *****************************************************************************
 */
void initSems(void)
{
    MySem = OSSemCreate(0);

    if (MySem == NULL)
    {
        CheckErr(FORCE_ERROR, "No ECB available to create MySem");
    }
    else
    {
        printf("Semiphore created.\n");
    }

    TxMbox = (OS_EVENT *)OSMboxCreate((void *)0);

    if (TxMbox == NULL)
    {
        CheckErr(FORCE_ERROR, "No ECB available to create TxMbox");
    }
    else
    {
        printf("Mailbox created.\n");
    }
}

/*****************************************************************************
 * Function:	createTasks()
 *
 * Description: Create 3 tasks.
 *
 *****************************************************************************
 */
INT8U createTasks(void)
{
	INT8U	err;

    err = OSTaskCreateExt(TaskStart,
						 (void *)0,
						 (void *)&TaskStartStk[TASK_STK_SIZE-1],
                         TASK_START_PRIO,
                         TASK_START_PRIO,
						 (void *)(&TaskStartStk[0]),
						 TASK_STK_SIZE,
						 (void *)0,
                         TASK_OPTIONS);
    CheckErr(err, "Error creating TaskStart...");
    OSTaskNameSet(TASK_START_PRIO, (INT8U *)"TaskStart", &err);
    CheckErr(err, "OSTaskNameSet in createTasks");
    printf("TaskStart created.\n");

    err = OSTaskCreateExt(Tasksecond,
                         (void *)&Tasksecondarg,
						 (void *)&Task2Stk[TASK_STK_SIZE-1],
                         TASK_SECOND_PRIO,
                         TASK_SECOND_PRIO,
						 (void *)(&Task2Stk[0]),
						 TASK_STK_SIZE,
						 (void *)0,
                         TASK_OPTIONS);
    CheckErr(err, "Error creating Tasksecond...");
    OSTaskNameSet(TASK_SECOND_PRIO, (INT8U *)"TaskSecond", &err);
    CheckErr(err, "OSTaskNameSet in createTasks");
    printf("TaskSecond created.\n");

    err = OSTaskCreateExt(Taskthird,
                         (void *)&Taskthirdarg,
						 (void *)&Task3Stk[TASK_STK_SIZE-1],
                         TASK_THIRD_PRIO,
                         TASK_THIRD_PRIO,
						 (void *)(&Task3Stk[0]),
						 TASK_STK_SIZE,
						 (void *)0,
                         TASK_OPTIONS);
    CheckErr(err, "Error creating TaskThird...");
    OSTaskNameSet(TASK_THIRD_PRIO, (INT8U *)"TaskThird", &err);
    CheckErr(err, "OSTaskNameSet in createTasks");
    printf("TaskThird created.\n");

	return OS_NO_ERR;
}

/*****************************************************************************
 * Function:	TaskStart()
 *
 * Description: Starts the timer running, initializes the statistics task,
 *              then loops forever at a 1 Hz rate printing a simple message.
 *
 * Note:        This is a uC/OS-II task.  Tasks must not return.
 *
 *****************************************************************************
 */
void TaskStart(void *pvdata)
{
	INT8U 	err;
	INT32U	loopCnt;

    printf("TaskStart running...\n");
    pvdata = pvdata;                	// prevent compiler warning

    printf("TaskStart initializing timer.\n");
    timerInit();                        // Init the system tick timer
    // This is the 55xx master interrupt enable.  Individual IE bits have
    // been set in other routines, i.e., OSTimerInit() sets up its bits.
    //_enable_interrupts();

#if OS_TASK_STAT_EN > 0
    printf("TaskStart initializing statistics.\n");
    OSStatInit();                   	// Initialize statistics
#endif
    // tell the second task that its OK to run
    err = OSSemPost(MySem);
    CheckErr(err, "1st OSSemPost in TaskStart");

    printf("TaskStart beginning its infinite loop.\n");
    for (loopCnt = 0; ; loopCnt++)
	{
        printf("* This is the first task function. Task #1 has looped %d times.\n\n", loopCnt);
        OSTimeDly(OS_TICKS_PER_SEC);    // Delay for 1 second

        // this sequence prevents the printf messages from getting intermixed.
        // wait for the thrid task to ack the second tasks message
		OSSemPend(MySem, 0, &err);
        CheckErr(err, "OSSemPend in TaskStart");

        // tell the second task that the third task received the message
        err = OSSemPost(MySem);
        CheckErr(err, "2nd OSSemPost in TaskStart");
	}
} /* End Of Function: TaskStart() */

/*****************************************************************************
 * Function:	Tasksecond()
 *
 * Description: Loop forever.
 *              Send a message to Taskthird in mailbox TxMbox
 *              Pend on MySem being available
 *              Prints a message
 *              Posts MySem
 *              Pend of a message in AckMbox
 *              Increment message and loop counter
 *
 * Note:        This is a uC/OS-II task.  Tasks must not return.
 *
 *****************************************************************************
 */
void Tasksecond(void * pvdata)
{
	INT8U 	    err;
	signed char txmsg;
    INT32U      loopCnt;

    printf("Tasksecond running...\n");
    txmsg = 'A';

	// wait for TaskStart to say it's OK to run
	OSSemPend(MySem, 0, &err);
    CheckErr(err, "1st OSSemPend in Tasksecond");

    printf("Tasksecond beginning its infinite loop.\n");
    for (loopCnt = 0; ;)
    {
    	txmsg = 'A';
		while(txmsg <= 'Z')
		{
            printf("** This is the second task function. Tasksecond has looped %d times.\n", loopCnt);
            printf("** the second task sent message %c to the third task\n", txmsg);

			// send a message to the thrid task
            err = OSMboxPost(TxMbox, (void *)&txmsg);
            CheckErr(err, "OSMboxPost in Tasksecond");

            printf("** the second task is waiting for the third task to acknowledge.\n\n", txmsg);

			// wait for the thrid task to ack the message
			OSSemPend(MySem, 0, &err);
            CheckErr(err, "2nd OSSemPend in Tasksecond");

			txmsg++;
			loopCnt++;
		}
   }
} /* End Of Function: Tasksecond() */


/*****************************************************************************
 * Function:	Taskthird()
 *
 * Description: Loop forever.
 *              Pend on the message from Tasksecond in mailbox TxMbox
 *              Pend on MySem being available
 *              Prints a message
 *              Posts MySem
 *              Posts a message in AckMbox to Tasksecond
 *              Increment message and loop counter
 *
 * Note:        This is a uC/OS-II task.  Tasks must not return.
 *
 *****************************************************************************
 */
void Taskthird(void * pvdata)
{
	INT8U	    err;
    signed char *rxmsg;
    INT32U      loopCnt;

    printf("Taskthird running...\n");
    printf("Taskthird beginning its infinite loop.\n");
    for (loopCnt = 0; ; loopCnt++)
    {
        rxmsg = (signed char *)OSMboxPend(TxMbox, 0, &err);
        CheckErr(err, "OSMboxPend in Taskthird");

        printf("*** This is the third task function. Taskthird has looped %d times.\n", loopCnt);
        printf("*** the third task received message %c from the second task\n", *rxmsg);
        printf("*** the third task is posting an ack semiphore to the second task\n\n");

        err = OSSemPost(MySem);
        CheckErr(err, "OSSemPost in Taskthird");
	}
} /*End Of Funtion: Taskthird() */

/*****************************************************************************
 * Function:    CheckErr()
 *
 * Description: Test first argument for zero, and print string arg if non zero
 *
 *****************************************************************************
 */
void CheckErr(INT8S err, char *s)
{
    if ( err != OS_NO_ERR )
    {
        printf("\nERROR: %d, %s\n", err, s);
        SystemHalt();
    }
}

/*****************************************************************************
 * Function:    SystemHalt()
 *
 * Description: Stop the OS and enter into a forever loop
 *
 *****************************************************************************
 */
void SystemHalt(void)
{
    /* Prevent the OS from doing any context switching */
    OSSchedLock();

    for (;;)
    {
        stop_count++;       /* Set a breakpoint here to catch errors */
    }
}

/* End Of File: demo.c */
