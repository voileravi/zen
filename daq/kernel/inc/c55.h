/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.81.80 04-09-03 (__imports)" */
/*
 *  ======== c55.h ========
 *  C55 header file
 *
 */

#ifndef C55_
#define C55_

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  Interrupt Vector Id
 */
#define C55_RESET	0	/* Hardware RESET */
#define C55_NMI		1	/* NMI */
#define C55_INT2	2	/* S/w or H/w interrupts */
#define C55_INT3	3
#define C55_INT4	4
#define C55_INT5	5
#define C55_INT6	6
#define C55_INT7	7
#define C55_INT8	8
#define C55_INT9	9
#define C55_INT10	10
#define C55_INT11	11
#define C55_INT12	12
#define C55_INT13	13
#define C55_INT14	14
#define C55_INT15	15
#define C55_INT16	16
#define C55_INT17	17
#define C55_INT18	18
#define C55_INT19	19
#define C55_INT20	20
#define C55_INT21	21
#define C55_INT22	22
#define C55_INT23	23
#define C55_BERR	24	/* BERR Bus Error interrupt */
#define C55_DLOG	25	/* DLOG Emulation interrupt */
#define C55_RTOS	26	/* RTOS Emulation interrupt */
#define C55_INT27	27	/* Software interrupts */
#define C55_INT28	28
#define C55_INT29	29
#define C55_INT30	30
#define C55_TINT	31


/* interrupt mask registers, interrupt flag registers */
#define	C55_IMR0	(Uns *)0x0
#define C55_IFR0	(Uns *)0x1
#define C55_IMR1	(Uns *)0x45
#define C55_IFR1	(Uns *)0x46

/* IMR0 Register masks */
#define C55_IEN02	(1 << C55_INT2)
#define C55_IEN03	(1 << C55_INT3)
#define C55_IEN04	(1 << C55_INT4)
#define C55_IEN05	(1 << C55_INT5)
#define C55_IEN06	(1 << C55_INT6)
#define C55_IEN07	(1 << C55_INT7)
#define C55_IEN08	(1 << C55_INT8)
#define C55_IEN09	(1 << C55_INT9)
#define C55_IEN010	(1 << C55_INT10)
#define C55_IEN011	(1 << C55_INT11)
#define C55_IEN012	(1 << C55_INT12)
#define C55_IEN013	(1 << C55_INT13)
#define C55_IEN014	(1 << C55_INT14)
#define C55_IEN015	(1 << C55_INT15)

/* IMR1 Register masks */
#define C55_IEN016	(1 << (C55_INT16 - 16))
#define C55_IEN017	(1 << (C55_INT17 - 16))
#define C55_IEN018	(1 << (C55_INT18 - 16))
#define C55_IEN019	(1 << (C55_INT19 - 16))
#define C55_IEN020	(1 << (C55_INT20 - 16))
#define C55_IEN021	(1 << (C55_INT21 - 16))
#define C55_IEN022	(1 << (C55_INT22 - 16))
#define C55_IEN023	(1 << (C55_INT23 - 16))
#define C55_IEBERR	(1 << (C55_BERR - 16))
#define C55_IEDLOG	(1 << (C55_DLOG - 16))
#define C55_IERTOS	(1 << (C55_RTOS - 16))

/* IFR0 Register masks */
#define C55_IFG02	(1 << C55_INT2)
#define C55_IFG03	(1 << C55_INT3)
#define C55_IFG04	(1 << C55_INT4)
#define C55_IFG05	(1 << C55_INT5)
#define C55_IFG06	(1 << C55_INT6)
#define C55_IFG07	(1 << C55_INT7)
#define C55_IFG08	(1 << C55_INT8)
#define C55_IFG09	(1 << C55_INT9)
#define C55_IFG010	(1 << C55_INT10)
#define C55_IFG011	(1 << C55_INT11)
#define C55_IFG012	(1 << C55_INT12)
#define C55_IFG013	(1 << C55_INT13)
#define C55_IFG014	(1 << C55_INT14)
#define C55_IFG015	(1 << C55_INT15)

/* IFR1 Register masks */
#define C55_IFG016	(1 << (C55_INT16 - 16))
#define C55_IFG017	(1 << (C55_INT17 - 16))
#define C55_IFG018	(1 << (C55_INT18 - 16))
#define C55_IFG019	(1 << (C55_INT19 - 16))
#define C55_IFG020	(1 << (C55_INT20 - 16))
#define C55_IFG021	(1 << (C55_INT21 - 16))
#define C55_IFG022	(1 << (C55_INT22 - 16))
#define C55_IFG023	(1 << (C55_INT23 - 16))
#define C55_IBERR	(1 << (C55_BERR - 16))
#define C55_IDLOG	(1 << (C55_DLOG - 16))
#define C55_IRTOS	(1 << (C55_RTOS - 16))

/*=====================C55_plug====================
 *
 */ 
extern Void C55_plug(Int, Fxn);	/* plug interrupt vector */

/*
 *====================C55_disableIMR0==============
 */
extern Uns C55_disableIMR0( Uns mask );
#define C55_disableIER0(mask)  C55_disableIMR0(mask) 
/*
 *===================C55_disableIMR1==============
 */
extern Uns C55_disableIMR1( Uns mask ); 
#define C55_disableIER1(mask)  C55_disableIMR1(mask) 
/*
 *==================C55_enableIMR0==============
 */
extern Void C55_enableIMR0( Uns mask );
#define C55_enableIER0(mask)  C55_enableIMR0(mask) 

/*
 *===================C55_enableIMR1=============
 */
extern Void C55_enableIMR1( Uns mask );
#define C55_enableIER1(mask)  C55_enableIMR1(mask) 


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* C55_ */
