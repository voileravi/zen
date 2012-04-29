/*
*********************************************************************************************************
*
*                                            MicroC/OS-II 5509-DSP Test code
*
* File : TEST.C
* By   : Mark Scott-Nash
*********************************************************************************************************
*/


#include    "zen.h"
#include    "c55x.h"

void    VectorInit(unsigned int);

void    pll_init(unsigned long DSP_Freq);


/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#define  TASK_STK_SIZE                  256     /* Size of each task's stacks (# of WORDs)            */
#define  TASK_SSTK_SIZE                 256     /* Size of each task's stacks (# of WORDs)            */
#define  TASKSTART_STK_SIZE             256
#define  TASKSTART_SSTK_SIZE            256
#define  N_TASKS                        2       /* Number of identical tasks                          */

/*
*********************************************************************************************************
*                                               VARIABLES
*********************************************************************************************************
*/

#pragma DATA_ALIGN( TaskStartStk, 2)
#pragma DATA_ALIGN( TaskStart_SStk, 2)
#pragma DATA_ALIGN( Task2Stk, 2)
#pragma DATA_ALIGN( Task2_SStk, 2)
#pragma DATA_ALIGN( Task3Stk, 2)
#pragma DATA_ALIGN( Task3_SStk, 2)

OS_STK           TaskStartStk[TASKSTART_STK_SIZE];
OS_STK           TaskStart_SStk[TASKSTART_SSTK_SIZE];
OS_STK           Task2Stk[TASK_STK_SIZE];       /* Tasks stacks                                  */
OS_STK           Task2_SStk[TASK_SSTK_SIZE];    /* Tasks stacks                                  */
OS_STK           Task3Stk[TASK_STK_SIZE];       /* Tasks stacks                                  */
OS_STK           Task3_SStk[TASK_SSTK_SIZE];    /* Tasks stacks                                  */

OS_EVENT         *MySem;
INT8U            err;

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void   TaskStart(void *pvdata);      /* Function prototypes of Startup task           */
void   Tasksecond(void *pvdata);     /* Function prototypes of tasks                  */
void   Taskthird(void *pvdata);

/*$PAGE*/
/*
*********************************************************************************************************
*                                                MAIN
*********************************************************************************************************
*/
float a=1024;

void main (void)
{
    //    VectorInit(1);          // change pointer to int vectors for test

    pll_init(120);          // Set the 5509 to 120MHz

    OSInit();               /* Initialize MicroC/OS-II */

//    printf ("Alpha port test for MicroC/OS-II for 5509-DSP.\n");
//    printf ("   Port to TI TMS320VC5509 \n");
//    printf ("\n");

    MySem   =OSSemCreate(1);

    err = OSTaskCreateExt(TaskStart,
        (void *)0,
        (void *)&TaskStartStk[TASKSTART_STK_SIZE-1],
        10,
        10,
        (void *)(&TaskStartStk[0]),
        TASKSTART_STK_SIZE,
        (void *)&TaskStart_SStk[TASKSTART_SSTK_SIZE-1],
        OS_TASK_OPT_STK_CLR + OS_TASK_OPT_STK_CHK);
    OSTaskNameSet(0, "TaskStart", &err);


    err = OSTaskCreateExt(Tasksecond,
        (void *)0,
        (void *)&Task2Stk[TASK_STK_SIZE-1],
        11,
        11,
        (void *)(&Task2Stk[0]),
        TASK_STK_SIZE,
        (void *)&Task2_SStk[TASK_SSTK_SIZE-1],
        OS_TASK_OPT_STK_CLR + OS_TASK_OPT_STK_CHK);
    OSTaskNameSet(1, "TaskSecond", &err);


    err = OSTaskCreateExt(Taskthird,
        (void *)0,
        (void *)&Task3Stk[TASK_STK_SIZE-1],
        12,
        12,
        (void *)(&Task3Stk[0]),
        TASK_STK_SIZE,
        (void *)&Task3_SStk[TASK_SSTK_SIZE-1],
        OS_TASK_OPT_STK_CLR + OS_TASK_OPT_STK_CHK);
    OSTaskNameSet(2, "TaskThird", &err);

    OSStart(); /* Start multitasking    */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                              STARTUP TASK
*********************************************************************************************************
*/

void TaskStart (void *pvdata)
{
    pvdata=pvdata;    // prevents compiler warnings

    OSTimerInit();          // Timer can not be started until the OS has been started.
    _enable_interrupts();   // This is the 5509 master interrupt enable. Individual IE bits have
    // been set in other routines, i.e., OSTimerInit() sets up its bits.
    OSStatInit();

    for(;;)
    {
        a=a/2;
        OSSemPend(MySem,0,&err);
//        printf("This is the first task function\n");
        err = OSSemPost(MySem);
        OSTimeDly(30);
    }
}
/*
*********************************************************************************************************
*                                                  TASKS
*********************************************************************************************************
*/

void Tasksecond (void * pvdata)
{
    char txmsg;

    pvdata=pvdata;    // prevents compiler warnings
    txmsg='A';
    for (;;)
    {
        while(txmsg <= 'Z')
        {
            OSSemPend(MySem,0,&err);
//            printf(" This is the second task function - %c\n", txmsg);
            err = OSSemPost(MySem);
            txmsg++;
        }
        txmsg='A';

        OSTimeDly(1);       /* Delay 1 clock tick to allow other task to run */
    }
}

void Taskthird(void * pvdata)
{
    int b=0;

    pvdata=pvdata;    // prevents compiler warnings
    for (;;)
    {
        b=b+1;
        OSSemPend(MySem,0,&err);
//        printf("  This is the third task function\n");
        err = OSSemPost(MySem);

        OSTimeDly(1);       /* Delay 1 clock tick to allow other task to run */
    }
}
