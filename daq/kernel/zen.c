/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*
*                              (c) Copyright 1992-2007, Micrium, Weston, FL
*                                           All Rights Reserved
*
* File    : uCOS_II.C
* By      : Jean J. Labrosse
* Version : V2.86
*
* LICENSING TERMS:
* ---------------
*   uC/OS-II is provided in source form for FREE evaluation, for educational use or for peaceful research.  
* If you plan on using  uC/OS-II  in a commercial product you need to contact Micriµm to properly license 
* its use in your product. We provide ALL the source code for your convenience and to help you experience 
* uC/OS-II.   The fact that the  source is provided does  NOT  mean that you can use it without  paying a 
* licensing fee.
*********************************************************************************************************
*/

#define  OS_GLOBALS                           /* Declare GLOBAL variables                              */
#include "zen.h"


#define  OS_MASTER_FILE                       /* Prevent the following files from including includes.h */
#include "core.c"
#include "flag.c"
#include "mbox.c"
#include "mem.c"
#include "mutex.c"
#include "queue.c"
#include "sem.c"
#include "task.c"
#include "time.c"
#include "tmr.c"
