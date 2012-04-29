;*********************************************************************************************************
;                                               boot.asm
;
;   Copyright 2012
;   All Rights Reserved

;   Author:     Roger
;   Date:       26-Apr-03

;   References:
;   $Workfile: boot.asm $
;
;   Description:    These are the assembly language level C initialization support routines.
;
;   Contents:
;		void _c_int00(void)         INITIALIZE C RUNTIME AND EXECUTE
;
;   Revision History - latest change on top
;
;   $Log:  $
;
;
;*********************************************************************************************************

;
;
;  Copyright 2003 by Texas Instruments Incorporated.
;  All rights reserved. Property of Texas Instruments Incorporated.
;  Restricted rights to use, duplicate or disclose this code are
;  granted through contract.
;
;
; "@(#) DSP/BIOS 4.81.80 04-09-03 (__imports)"
;
;  ======== boot.s55 ========

;;        .include std.h55        ; work-around ".model mem=large" problem

;*****************************************************************************
;* boot.s55   v1.82 - Initialize the TMS320C55x C runtime environment
;* Copyright (c) 1993-2001  Texas Instruments Incorporated
;*****************************************************************************

        .include c55.h55

        .model  call=internal

;*****************************************************************************
;* boot.s55   v1.80 - Initialize the TMS320C55x C/C++ runtime environment
;* Copyright (c) 1993-2000  Texas Instruments Incorporated
;*
;* The user can and often will create a system-specific initialization
;* routine, but must perform the various functions of this routine in order
;* for C/C++ code in the system to operate correctly.
;*****************************************************************************

        .model  call=internal
        .mmregs

; Symbols from C/C++ Runtime
        .ref    _main
        .ref    _auto_init
        .ref    _pll_init
;        .ref    _VSC_RTDX_init

; Symbols defined by the Linker
        .ref    cinit
        .ref    ___bss__
        .ref    __STACK_SIZE    ; can be set with -stack linker option
        .ref    __SYSSTACK_SIZE ; can be set with -sysstack linker option

; Symbols defined here (and have special meaning to the linker)
        .def    _c_int00
        .def    __stack
        .def    __sysstack

;
; Define special symbol to guarantee that this boot file gets linked
; instead of boot file from rts.lib (SDSsq24217). The GBL_config macro
; will reference this symbol forcing a linker error if non-bios boot.obj
; has been linked with application.
;
        .def    GBL_boot
GBL_boot        .set    1

           .data
           .byte 0

           .global _PLL_Frequency
_PLL_Frequency:
           .word 0
           .text

;************************************************************************
; Data Stack (size set by the Linker, not blocked, longword aligned)
;************************************************************************
__stack:    .usect  .stack, 0, 0, 1


;************************************************************************
; System Stack (size set by the Linker, not blocked, longword aligned)
;************************************************************************
__sysstack: .usect  .sysstack, 0, 0, 1

args        .sect    ".args"

*******************************************************************
* FUNCTION DEF : _c_int00                                         *
*                                                                 *
*   1) Set up stack, sysstack                                     *
*   2) Check for omap device and call disable functionality       *
*   3) Set up proper status                                       *
*   4) Initialize variables                                       *
*   5) Call BIOS_init                                             *
*   6) Process pinit                                              *
*   7) Call users' main program                                   *
*   8) Call BIOS_start - this call does not return if the         *
*                        Task manager is enabled                  *
*******************************************************************

;************************************************************************
; c_int00() - C/C++ Environment Entry Point
;************************************************************************
        .sect ".sysinit"
_c_int00:

    bit(st1, #STBIT_INTM) = #1          ; disable interrupts

    IER0_MMR = #0h || mmap()            ; clear ier0 and ier1
    IER1_MMR = #0h || mmap()

    .if $isdefed ("CANTATA")  ; Syntax shown in assembly guide section 3.9.3.
    ; Do not reset or change interrupt vectors when running Cantata tests.
    .else
    .ref    Interrupt_Vectors
;   Examine one of the interrupt vector pointers.  If FFFF (the value
;   the hardware gives it upon hardware reset), reset both vectors
;   to the page containing vectors.asm and do a software reset.
    T0 = @IVPD_L
    T1 = #0FFFFh
    TC1 = T0 == T1
    if (!TC1) goto DidSoftResetAlready

    ; Set the interrupt vectors registers to the page where vectors.asm in located
    ; (by the linker and its .cmd file).
    @IVPD_L = #(Interrupt_Vectors >> 8) || mmap()
    @IVPH_L = #(Interrupt_Vectors >> 8) || mmap()

;   Do a software reset.  This sets the stack mode to whatever is coded in
;   vectors.asm at Reset_int.  Software resets do not change IVPD or IVPH.
    RESET
    .endif

DidSoftResetAlready:

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; HWI_init used to clear ier0 and ier1. However say if     ;
    ; user's init function writes a particular value to ier0   ;
    ; HWI_init would clear it back, as user's init function    ;
    ; is called before HWI_init. Hence HWI_init would nullify  ;
    ; the effect of user's init codes. Hence the clearing code ;
    ; is added in here                                         ;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    .if .PHASE2
      SP = SP + #0   ; avoid ECNs 372 and 438
    .endif

    ;------------------------------------------------------------------------
    ; Initialize the Stack Pointer
    ;   Note: SP must be aligned on doubleword boundary
    ;------------------------------------------------------------------------

    .noremark 5573                              ; Safe wrt CPU_43
                                                ; Switch remark off.
    .if .PHASE3
      XSP = #((__stack + (__STACK_SIZE >> 1)) & 0x7FFFFE)
    .else
      SP  = #((__stack + (__STACK_SIZE >> 1)) & 0xFFFE)
    .endif
    .remark 5573                                ; Switch remark on.

    ;------------------------------------------------------------------------
    ; Initialize the System Stack Pointer
    ;------------------------------------------------------------------------

    SSP = #((__sysstack + (__SYSSTACK_SIZE >> 1)) & 0xFFFF)


    ;------------------------------------------------------------------------
    ; Initialize the Status Registers
    ;
    ; Set the value of each status bit that compiled C/C++ code assumes has a
    ; particular value. Other bits are not touched.
    ;------------------------------------------------------------------------

    .if .PHASE3

      ;  Status Register ST1
      ;    BRAF  == don't care
      ;    CPL   == 1  Compiler mode on: direct addr via SP
      ;    XF    == don't care
      ;    HM    == don't care
      ;    INTM  == don't care
      ;    M40   == 0  32-bit mode (40-bit off)
      ;    SATD  == 0  D-unit saturation off
      ;    SXMD  == 1  Sign-extension on
      ;    C16   == 0  Disallow dual arithmetic in C54X mode
      ;    FRCT  == 0  Fractional mode off
      ;    C54CM == 0  C54X compatibility off
      ;    ASM   == don't care

ST1_ON  .equ (1<<ST1_CPL)|(1<<ST1_SXMD)
ST1_OFF .equ (1<<ST1_M40)|(1<<ST1_SATD)|(1<<ST1_C16)|(1<<ST1_FRCT)|(1<<ST1_C54CM)

      ; Status Register ST2
      ;    ARMS   == 1  AR Mode 1: allow short-offset operand
      ;    DBGM   == don't care
      ;    EALLOW == don't care
      ;    RDM    == 0  Round toward the infinite
      ;    CDPLC  == 0  CDP linear (not circular) addressing
      ;    AR0LC  == 0  AR0 linear (not circular) addressing
      ;     ...
      ;    AR7LC  == 0  AR7 linear (not circular) addressing

ST2_03LC .equ (1<<ST2_AR0LC) | (1<<ST2_AR1LC) | (1<<ST2_AR2LC) | (1<<ST2_AR3LC)
ST2_47LC .equ (1<<ST2_AR4LC) | (1<<ST2_AR5LC) | (1<<ST2_AR6LC) | (1<<ST2_AR7LC)

ST2_ON   .equ (1<<ST2_ARMS)
ST2_OFF  .equ (1<<ST2_RDM) | (1<<ST2_CDPLC) | ST2_03LC | ST2_47LC

      ; Status Register ST3
      ;    SATA   == 0  A-unit saturation off
      ;    SMUL   == 1  Saturation on multiply on
      ;    others == don't care

      ; Change the bits
      ST1_55_MMR = ST1_55_MMR & #(~ST1_OFF) || mmap()
      ST1_55_MMR = ST1_55_MMR | #( ST1_ON ) || mmap()
      .noremark 5601                            ; Safe wrt CPU_75
                                                ; since interrupts are disabled
                                                ; Switch remark off.
      ST2_55_MMR = ST2_55_MMR & #(~ST2_OFF) || mmap()
      ST2_55_MMR = ST2_55_MMR | #( ST2_ON ) || mmap()
      .remark 5601                              ; Switch remark on.
      bit(ST3, #STBIT_SATA) = #0
      bit(ST3, #STBIT_SMUL) = #1

      .C54CM_off
      .CPL_on
      .ARMS_on

    .else

      ; Same settings as above except some bits are in different locations
      ; and some have different names (SMUL => GSM, C54CM => LEAD)

ST1_ON  .equ (1<<ST1_ARMS)|(1<<ST1_CPL)|(1<<ST1_SXMD)
ST1_OFF .equ (1<<ST1_LEAD)|(1<<ST1_SATA)|(1<<ST1_GSM)|(1<<ST1_RDM)|(1<<ST1_FRCT)|(1<<ST1_M40)|(1<<ST1_SATD)

ST2_03LC .equ (1<<ST2_AR0LC) | (1<<ST2_AR1LC) | (1<<ST2_AR2LC) | (1<<ST2_AR3LC)
ST2_47LC .equ (1<<ST2_AR4LC) | (1<<ST2_AR5LC) | (1<<ST2_AR6LC) | (1<<ST2_AR7LC)

ST2_OFF  .equ (1<<ST2_CDPLC) | ST2_03LC | ST2_47LC

      ST1_55_MMR = ST1_55_MMR & #(~ST1_OFF) || mmap()
      ST1_55_MMR = ST1_55_MMR | #( ST1_ON ) || mmap()

      ST2_55_MMR = ST2_55_MMR & #(~ST2_OFF) || mmap()

      .LEAD_off
      .CPL_on
      .ARMS_on

      bit (ST3, #1) = #0
$1:   TC1 = bit(ST3_55_MMR, #1) || mmap()
      nop_16
      if (TC1) goto $1
      nop_16
      nop_16

      bit (ST3, #0) = #0
$2:   TC1 = bit(ST3_55_MMR, #0) || mmap()
      nop_16
      if (TC1) goto $2
      nop_16
      nop_16
    .endif


    ;------------------------------------------------------------------------
    ; Initialize Extended Address Registers
    ;------------------------------------------------------------------------
    .if .PHASE3
      .noremark 5573                            ; Safe wrt CPU_43
                                                ; Switch remark off.
      XAR0 = #___bss__
      .remark 5573                              ; Switch remark on.
      XAR1 = XAR0
      XAR2 = XAR0
      XAR3 = XAR0
      XAR4 = XAR0
      XAR5 = XAR0
      XAR6 = XAR0
      XAR7 = XAR0
      XCDP = XAR0
      XDP  = XAR0
    .else
      MDP   = #0
      MDP05 = #0
      MDP67 = #0
    .endif

    ;------------------------------------------------------------------------
    ; Perform autoinitialization. Must be after other initialization since
    ; C++ static initializers may be called.
    ;------------------------------------------------------------------------

    call _auto_init

    ;------------------------------------------------------------------------
    ; Call the user's program
    ;------------------------------------------------------------------------
    xar2 = #args
    .if (__large_model)
      dr0 = *ar2+       ; set up argc as the 1st param to main
      mar(ar2 + #1)     ; traverse the hole created by the alignment constraint
      xar0 = dbl(*ar2+) ; set up argv as the 2nd param to main
      xar1 = dbl(*ar2+) ; set up envp as the 3rd param to main
    .else
      dr0 = *ar2+       ; set up argc as the 1st param to main
      ar0 = *ar2+       ; set up argv as the 2nd param to main
      ar1 = *ar2+       ; set up envp as the 3rd param to main
    .endif

    ; Change the PLL frequency to 200MHz.  Save the number for timer initialization.
    AC0 = #200
    *(#_PLL_Frequency) = AC0

    ; Set the PLL to a frequency specified within this function.
    call _pll_init

    .if $isdefed ("CANTATA")  ; Syntax shown in assembly guide section 3.9.3.
    ; Do not initialize the timer when running Cantata tests.
    .else
    .ref    _timerInit
    call _timerInit
    .endif

    ; Initialize RTDX.  This is here only to demonstrate non-interference with MicroCOS.
    ;
    ; call _VSC_RTDX_init
    ;

    ; The RTDX initialization turns interrupts on.  Turn them back off.
    bit(ST1, 11) = #1

    call _main

    ;------------------------------------------------------------------------
    ; Execution should never reach this point
    ;------------------------------------------------------------------------
Stop: goto  Stop
