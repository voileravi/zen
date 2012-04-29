;*********************************************************************************************************
;                                               OS_CPU_A.ASM
;
;   Copyright 2003, Validated Software Corporation, Lafayette, CO
;   All Rights Reserved
;
;   Author:     Scott N.
;   Date:       10-Sep-03
;
;   References:
;   $Workfile: OS_CPU_A.ASM $
;
;   Description:    These are the assembly language level OS support routines
;                   for the TMS320C55xx port on Code Composer Studio
;
;   Contents:
;		unsigned int ReturnCurrentDP(void)	RETURN CURRENT DATA POINTER
;       	unsigned int getStackPtr(void)      	RETURN CURRENT STACK POINTER
;		void OSIntCtxSw(void)			OS CONTEXT SWITCH, INTERRUPT LEVEL
;		void OSCtxSw(void)			OS CONTEXT SWITCH
;		void OSStartHighRdy(void)               OS START HIGHEST PRIORITY TASK
;
;   Revision History - latest change on top
;
;   $Log:  $
;
;
;*********************************************************************************************************

	.include	c55.h55

;
;       Functions defined in this file and used by other files
;
        .def    _OSCtxSw
        .def    _OSIntCtxSw
        .def    _OSStartHighRdy
        .def    _OSTaskStkInit
        .def    _OS_CPU_SaveSR
        .def    _OS_CPU_RestoreSR
        .def    _OSTickISR
        .def    _InvalidISR
        .def    _IntStack
        .def    _BerrISR
        .def    _VectorInit

;       External functions referenced in this file
;
        .ref    _OSTCBHighRdy, _OSTaskSwHook, _OSRunning, _OSTCBCur
        .ref    _OSPrioCur, _OSPrioHighRdy
        .ref    _OSTimeTick, _OSIntExit, _OSIntNesting
	.if 0
        .ref    _hrt_interruptHandler0
        .ref    _phy_dacAD9767_Dma0XmtIsr
        .ref    _hrt_interruptHandler1
   	.endif

;
;       Variables defined in this file and referenced by files
;
        .global _ptoSSsav, _pbossav

;
;       Assembler directives
;
        .mmregs
        .C54CM_off
        .CPL_on
        .ARMS_on
        .model call=c55_std
        .model mem=large

        .noremark       5650
        .noremark       5571

;
;       lable assignments
;
        .asg AR6, FP
        .asg XAR6, XFP
        .asg DPH, MDP

;
;      Define space for temporary variables
;
        .bss    _SPsav    ,2,,2         ; force this section to start on an even address
        .bss    _SSPsav   ,2
        .bss    _XSPsav   ,2
        .bss    _XSSPsav  ,2
        .bss    _XSPsav1  ,2
        .bss    _XSSPsav1 ,2
        .bss    _tasksav  ,2
        .bss    _retasav  ,2
        .bss    _Cretasav ,2
        .bss    _pdatasav ,2
        .bss    _ptossav  ,2
        .bss    _ptoSSsav ,2
        .bss    _pbossav  ,2
        .bss    _pargsav  ,2
        .bss    _SSP1     ,1
        .bss    _SP1      ,1
        .bss    _SSP2     ,1
        .bss    _SP2      ,1
        .bss    _SSP3     ,1
        .bss    _SP3      ,1

        .text

;**************** Context save and restore macros ************
;
;  order must be the same as the compiler generated
;  ISR context save/restores
;
;**************************************************************
;
CONTEXT_SAVE .macro
        PSH dbl(AC0)
        PSH mmap(AC0G)
        PSH dbl(AC1)
        PSH mmap(AC1G)
        PSH dbl(AC2)
        PSH mmap(AC2G)
        PSH dbl(AC3)
        PSH mmap(AC3G)
        PSH T1, T0
        PSHBOTH XAR0
        PSHBOTH XAR1
        PSHBOTH XAR2
        PSHBOTH XAR3
        PSHBOTH XAR4
        PSH mmap(BKC)
        PSH mmap(BK03)
        PSH mmap(BK47)
        PSH mmap(ST3_55)
        PSH mmap(BRC0)
        PSH mmap(RSA0L)
        PSH mmap(RSA0H)
        PSH mmap(REA0L)
        PSH mmap(REA0H)
        PSH mmap(BRS1)
        PSH mmap(BRC1)
        PSH mmap(RSA1L)
        PSH mmap(RSA1H)
        PSH mmap(REA1L)
        PSH mmap(REA1H)
        PSH mmap(CSR)
        PSH mmap(RPTC)
        PSHBOTH XCDP
        PSH mmap(TRN0)
        PSH mmap(TRN1)
        PSH mmap(BSA01)
        PSH mmap(BSA23)
        PSH mmap(BSA45)
        PSH mmap(BSA67)
        PSH mmap(BSAC)
        NOP       ;     avoids Silicon Exception CPU_8
        NOP       ;     avoids Silicon Exception CPU_8
        NOP       ;     avoids Silicon Exception CPU_8
        MOV SSP, AR1            ; save SSP on stack
        PSH AR1                 ; save ssp  (leaves SP on even addr)
        MOV SP, AR1             ; save SP
        AND #0xfffe, mmap(SP)   ; Force SP to even
        PSH AR1                 ; save SP on stack
        AADD #-1, SP
        AND #0xf91f, mmap(ST1_55)
        OR #0x4100, mmap(ST1_55)
        BSET ST2_ARMS
        BCLR ST2_AR0LC ; circ mode (AR0)
        BCLR ST2_AR1LC ; circ mode (AR1)
        BCLR ST2_AR2LC ; circ mode (AR2)
        BCLR ST2_AR3LC ; circ mode (AR3)
        BCLR ST2_AR4LC ; circ mode (AR4)
        BCLR ST2_AR5LC ; circ mode (AR5)
        BCLR ST2_AR6LC ; circ mode (AR6)
        BCLR ST2_AR7LC ; circ mode (AR7)
        BCLR ST2_CDPLC ; circ mode (CDP)
        .endm

;
CONTEXT_RESTORE .macro
        AADD #1, SP
        POP mmap(SP)
        POP AR1                  ;get ssp for task
        mov AR1, SSP
        POP mmap(BSAC)
        POP mmap(BSA67)
        POP mmap(BSA45)
        POP mmap(BSA23)
        POP mmap(BSA01)
        POP mmap(TRN1)
        POP mmap(TRN0)
        POPBOTH XCDP
        POP mmap(RPTC)
        POP mmap(CSR)
        POP mmap(REA1H)
        POP mmap(REA1L)
        POP mmap(RSA1H)
        POP mmap(RSA1L)
        POP mmap(BRC1)
        POP mmap(BRS1)
        POP mmap(REA0H)
        POP mmap(REA0L)
        POP mmap(RSA0H)
        POP mmap(RSA0L)
        POP mmap(BRC0)
        POP mmap(ST3_55)
        POP mmap(BK47)
        POP mmap(BK03)
        POP mmap(BKC)
        POPBOTH XAR4
        POPBOTH XAR3
        POPBOTH XAR2
        POPBOTH XAR1
        POPBOTH XAR0
        POP T1,T0
        POP mmap(AC3G)
        POP dbl(AC3)
        POP mmap(AC2G)
        POP dbl(AC2)
        POP mmap(AC1G)
        POP dbl(AC1)
        POP mmap(AC0G)
        POP dbl(AC0)
        NOP       ;     avoids Silicon Exception CPU_99/100
        NOP       ;     avoids Silicon Exception CPU_99/100
        NOP       ;     avoids Silicon Exception CPU_99/100
        NOP       ;     avoids Silicon Exception CPU_99/100
        NOP       ;     avoids Silicon Exception CPU_99/100
        NOP       ;     avoids Silicon Exception CPU_99/100
        .endm


        .text
;*********************************************************************************************************
;                                          START MULTITASKING
;                                       void OSStartHighRdy(void)
;
; The stack frame is assumed to look as follows:
;
; OSTCBHighRdy->OSTCBStkPtr --> IMR
;								REA
;								RSA
;								PMST
;								BRC
;								ST0
;								ST1
;								T
;								BK
;								AR7
;								AR7
;								AR6
;								AR5
;								AR4
;								AR3
;								AR2
;								AR1
;								AR0
;								BG
;								BH
;								BL
;								AG
;								AH
;								AL   (*pdata, passed in register A)
;								*task (serve as the return address)
;
;
; Note : OSStartHighRdy() MUST:
;           a) Call OSTaskSwHook() then,
;           b) Set OSRunning to TRUE,
;           c) Switch to the highest priority task.
;*********************************************************************************************************
_OSStartHighRdy:
        .ref ___bss__
        MOV #((___bss__ >> 16) & 0x7f), DPH
||      BCLR ST2_RDM
        AMOV #___bss__, XAR0
        AMAR *AR0, XAR1
        AMAR *AR0, XAR2
        AMAR *AR0, XAR3
        AMAR *AR0, XAR4
        AMAR *AR0, XAR5
        AMAR *AR0, XAR6
        AMAR *AR0, XAR7
        AMAR *AR0, XCDP
;
        BSET ST3_SMUL
        BCLR ST3_SATA
        CALL #_OSTaskSwHook
;
        MOV #1, *abs16(#_OSRunning)	;OSRunning = OS_TRUE
;
        MOV dbl(*abs16(#_OSTCBHighRdy)), XAR3
        MOV dbl(*AR3+), XAR1
        MOV XAR1, XSP
        nop
        nop

        CONTEXT_RESTORE                 ; new task context is restored here, sp points to *task

        reti                            ;      run task

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;       OS_STK * OSTaskStkInit(task, p_arg, ptos, opt);    /* Initialize the task's stack         */
;
; inputs:
;       * T0    _opt
;       * AR1   _ptos
;       * AR0   _p_arg
;       * AC0   _task
;
; outputs:
;	A = new stack_top ->need to save in TCB
;
; After calling this function, the task stack will look like this:
;
; A(new stack_top) ---->  ---   ST2_55
;                         |     ST1_55
;         Setup for reti  |     PC(15-0)
;                         |     ST0_55
;                         |     DBSTAT
;                         ---   (Loop bits): PC(23-16)
;                               AC0
;                               AC0G
;                               AC1
;                               AC1G
;                               AC2
;                               AC2G
;                               AC3
;                               AC3G
;                               T0
;                               T1
;                               XAR0
;                               XAR1
;                               XAR2
;                               XAR3
;                               XAR4
;                               BKC
;                               BK03
;                               BK47
;                               ST3_55
;                               BRC0
;                               RSA0L
;                               RSA0H
;                               REA0L
;                               REA0H
;                               BRS1
;                               BRC1
;                               RSA1L
;                               RSA1H
;                               REA1L
;                               REA1H
;                               CSR
;                               RPTC
;                               XCDP
;                               TRN0
;                               TRN1
;                               BSA01
;                               BSA23
;                               BSA45
;                               BSA67
;                               BSAC
;                               SSP
;    Bottom of Stack            SP
;
;
;
_OSTaskStkInit:
        mov     XAR1, dbl(*(#_ptossav)) ;* AR1  _ptos
        mov     AC0, dbl(*(#_tasksav))  ;* AC0  _task
        mov     XAR0, dbl(*(#_pargsav))  ;* AR0  _p_arg
        ;
        ; This function does not return the correct value of the new TOS because
        ; it is no known here.  It will be fixed in OSTaskCreateHook()
        ;
        ret

;       This is the actual Task Stack Init function.
;

_IntStack:                              ; trap 5 lands here
;
;       Save the Interrupt context
;
        nop
        nop
        nop
        mov     xsp, dbl(*(#_XSPsav))   ; XSP
        mov     xssp, dbl(*(#_XSSPsav)) ; XSSP

        CONTEXT_SAVE
        nop
        nop
        nop
        mov     xsp, dbl(*(#_XSPsav1))  ; XSP
        mov     xssp, dbl(*(#_XSSPsav1)); XSSP
        nop
        nop
        nop
        nop
        nop
        nop
        mov     dbl(*(#_XSPsav)), xsp   ; XSP
        mov     dbl(*(#_XSSPsav)), xssp ; XSSP
        nop
        nop
        nop
        nop
        nop
        nop
        mov     ssp, AR3
        nop
        nop
        nop
        mov     *AR3+, AR1
        mov     *AR3+, AR1
        mov     AR1, *(#_SSP2)          ; DBSTAT
        mov     *AR3, AR1
        mov     AR1, *(#_SSP3)           ;  ST0_55
;
        mov     *SP(#0), AR1
        mov     *SP(#1), AR1
        bclr    #11, AR1       ; Enable interrupts
        mov     AR1, *(#_SP2)            ; ST1_55
        mov     *SP(#2), AR1
        mov     AR1, *(#_SP3)            ; ST2_55
;
;
;  Restore the stack to where it was just before the trap
;  and get the function parameters that were passed to OSTaskStkInit(...)
;

        mov     dbl(*(#_ptoSSsav)), XAR1        ; Build a reti SSP stack (using SP)
        mov     XAR1, XSSP                      ; SSP = ptoSS
        mov     dbl(*(#_ptossav)), XAR1         ; Build a reti SP stack
        mov     XAR1, XSP                       ; SP = ptos
                nop                             ; a little time to let the SP settle
        nop
        nop
        mov     dbl(*(#_SSP3)), AC0             ; ST0_55  ST2_55
        pshboth AC0
        mov     dbl(*(#_SSP2)), AC0             ; DBSTAT  ST1_55
        pshboth AC0
        mov     dbl(*(#_tasksav)), AC0          ; (Loop bits): PC(23-16) and PC(15-0)
        pshboth AC0

        mov     #0x0000, AC0
        mov     #0x0101, AC1
        mov     #0x0202, AC2
        mov     #0x0303, AC3
        mov     #0x0404, T0
        mov     #0x0505, T1
;;        amov    #0x0606, XAR0
        mov    dbl(*(#_pargsav)), XAR0
        amov    #0x0707, XAR1
        amov    #0x0808, XAR2
        amov    #0x0909, XAR3
        amov    #0x1010, XAR4
        amov    #0x1111, XAR5
        amov    #0x1212, XAR6
        amov    #0x1313, XAR7

        CONTEXT_SAVE;
        mov     xsp, dbl(*(_pbossav))           ; save the current stack pointer for OSTaskCreateHook()
        mov     dbl(*(#_XSPsav1)), xsp          ; XSP
        mov     dbl(*(#_XSSPsav1)), xssp        ; XSSP
        nop
        nop
        nop
        nop
        nop
        nop
        CONTEXT_RESTORE
        nop
        nop
        nop
        nop
        nop
        nop
        reti


;*********************************************************************************************************
;                                PERFORM A CONTEXT SWITCH (From task level)
;                                           void OSCtxSw(void)
;
; Note(s): 1) Upon entry,
;             OSTCBCur     points to the OS_TCB of the task to suspend
;             OSTCBHighRdy points to the OS_TCB of the task to resume
;
;          2) The stack frame of the task to suspend looks as follows:
;
;                 SP -> PC of task to suspend
;
;          3) The stack frame of the task to resume looks as follows:
;
;                 PC of task to resume
;*********************************************************************************************************

_OSCtxSw:
        CONTEXT_SAVE                    ; save all registers on the current stack
        nop                             ;
        nop                             ;
        nop                             ;
;
;       OSTCBCur->OSTCBStkPtr = SP
;
        mov     dbl(*(#_OSTCBCur)), XAR3
        mov     XSP, dbl(*AR3)                  ;OSTCBCur->OSTCBStkPtr = SP
;
;       Call OSTaskSwHook();
;
        call    #_OSTaskSwHook
;
;       Make high ready task the current task
;
        mov     dbl(*abs16(#_OSTCBHighRdy)), XAR0
        nop                                     ;
        mov     XAR0, dbl(*(#_OSTCBCur))        ; OSTCBCur = OSTCBHighRdy
;
        mov     *abs16(#_OSPrioHighRdy), AR3
        nop                                     ;
        mov     AR3, *(#_OSPrioCur)             ; OSPrioCur = OSPrioHighRdy
;
; restore new task  ( SP = OSTCBHighRdy->OSTCBStkPtr )
;
        mov     dbl(*AR0+), XAR3
        nop
        mov     XAR3, XSP               ; load the sp for new task
        nop                             ;
        nop                             ;
        nop                             ;

        CONTEXT_RESTORE                 ; new task context is restored here, no A has *pdata, sp point to *task

        nop
        nop
        nop
        nop
        nop
        nop
        reti                            ;      run task

;*********************************************************************************************************
;                                PERFORM A CONTEXT SWITCH (From an ISR)
;                                        void OSIntCtxSw(void)
;
; Note(s): 1) Upon entry,
;             OSTCBCur     points to the OS_TCB of the task to suspend
;             OSTCBHighRdy points to the OS_TCB of the task to resume
;
;          2) The stack frame of the task to suspend looks as follows:
;
;                                  SP --> 	FRAME -1 from OSIntExit
;                                	        return address to OSIntExit()
;                                    	    return address to ISR
;                                         	dummy to make even SP after push old SP
;                                           old SP, -- SP before old even adjustment
;                                           if old SP is odd, this is a dummy, otherwise non-exist
;                                           MMRs - but no IMR
;                                           ..
;											..
;											..
;                                           return address of the task code

;          3) The stack frame of the task to resume looks as follows:
;
;             OSTCBHighRdy->OSTCBStkPtr --> MMRs
;                                           address of the task to resume
;*********************************************************************************************************

_OSIntCtxSw:
        aadd    #-1, SP
;
;       Call OSTaskSwHook();
;
        call    #_OSTaskSwHook
;
;       Make high ready task the current task
;
        mov     dbl(*abs16(#_OSTCBHighRdy)), XAR0
        nop                                     ;
        mov     XAR0, dbl(*(#_OSTCBCur))        ; OSTCBCur = OSTCBHighRdy
;
        mov     *abs16(#_OSPrioHighRdy), AR3
        nop                                     ;
        mov     AR3, *(#_OSPrioCur)             ; OSPrioCur = OSPrioHighRdy
;
; restore new task  ( SP = OSTCBHighRdy->OSTCBStkPtr )
;
        mov     dbl(*AR0+), XAR3
        nop
        mov     XAR3, XSP               ; load the sp for new task

        nop                             ;
        nop                             ;
        nop                             ;

        CONTEXT_RESTORE                 ; new task context is restored here
        nop
        nop
        nop
        nop
        nop
        nop
	reti;

;*********************************************************************************************************
;                                            HANDLE TICK ISR
;
; Description: This function is .
;
; Arguments  : none
;
; Returns    : none
;
; Note(s)    : The following C-like pseudo-code describe the operation being performed in the code below.
;
;              Save all registers on the current task's stack;
;              OSIntNesting++;
;              OSTimeTick();              Notify uC/OS-II that a tick has occured
;              OSIntExit();               Notify uC/OS-II about end of ISR
;              Restore all registers that were save on the current task's stack;
;              Return from Interrupt;
;*********************************************************************************************************

_OSTickISR:
;
;              Save all registers on the current task's stack
;
        CONTEXT_SAVE
        nop
        nop
        nop
;
;              OSIntNesting++;
;
        and     #0FBFFh, mmap(ST1_55)   ; clear M40
        add     1, *(#_OSIntNesting)
;
;       if OSIntNesting == 1 then save the SP of the current task into OSTCBCur->OSTCBStkPtr
;
        mov     *(#_OSIntNesting), AR1
        cmp     mmap(AR1) == 1, TC1
        bcc     L3,!TC1                 ; branch if not
        mov     dbl(*(#_OSTCBCur)), XAR3
        mov     XSP, dbl(*AR3)          ;OSTCBCur->OSTCBStkPtr = SP
;
;              OSTimeTick();            Notify uC/OS-II that a tick has occured
;
L3:     call    _OSTimeTick
;
;              OSIntExit();             Notify uC/OS-II about end of ISR
;
        call    _OSIntExit
;
;              Restore all registers that were save on the current task's stack;
;              Return from Interrupt
;
        CONTEXT_RESTORE
        nop
        nop
        nop
        nop
        nop
        nop
        reti

;*********************************************************************************************************
;                               Save / Restore status routines
;
;       Support for OS_ENTER_CRITICAL and OS_ENTER_CRITICAL
;
;       OS_CPU_SaveSR saves the current interrupt enable status, disables interrupts and returns the
;       previous setting to the caller.
;
;       OS_CPU_RestoreSR sets the interrupt enable to the passed value.
;
;*********************************************************************************************************
;
; OS_CPU_SR OS_CPU_SaveSR(void)
;
_OS_CPU_SaveSR:
        mov     mmap(ST1_55),  T0       ; get the interrupt enable bit
        and     #0800h,  T0, T0
        bclr    #st1_intm, st1_55       ; Disable interrupts
        ret

;
; OS_CPU_RestoreSR(OS_CPU_SR foo)
;
_OS_CPU_RestoreSR:
        aadd    #-1, SP
        mov     T0, *SP(#0)
        cmp     *SP(#0) == #0800h, TC1  ; Were interrupts enabled when OSEnterCritical called?
        bcc     L1,!TC1
        bset    #st1_intm, st1_55       ; yes, enable them again
        b L2
L1:
        bclr    #st1_intm, st1_55       ; no, leave them disabled
L2:
        aadd    #1, SP
        ret

;*********************************************************************************************************
;                               VectorInit
;
;       For debugging only.  Changes the interrupt vector table location for testing w/o burning flash
;
;*********************************************************************************************************
_VectorInit:
        mov     T0, mmap(IVPD)
        mov     T0, mmap(IVPH)
        ret

;*********************************************************************************************************
;                               Error Interrupt Catch-all
;
;       These error traps need to be expanded to provide safe shutdown or controlled restart!
;
;*********************************************************************************************************
_BerrISR:
        b _BerrISR
        nop
        nop
        nop

_InvalidISR:
        b _InvalidISR
        nop
        nop
        nop

.end




