;*********************************************************************************************************
;                                               autoinit.asm
;
;   Copyright 2004, Validated Software Corporation, Lafayette, CO
;   All Rights Reserved

;   Author:     Jim Elliott
;   Date:       26-Apr-03

;   References:
;   $Workfile: autoinit.asm $
;
;   Description:    These are the assembly language level C initialization support routines.
;
;   Contents:
;		void auto_init(void)         INITIALIZE GLOBAL VARIABLES
;
;   Revision History - latest change on top
;
;   $Log:  $
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
;  ======== autoinit.s55 ========
;

        .include std.h55        ; work-around ".model mem=large" problem

;/*****************************************************************************/
;/* AUTO_INIT()   v1.82 - Perform initialization of C variables.              */
;/*  Copyright (c) 1996-2001  Texas Instruments Incorporated                  */
;/*****************************************************************************/
        .mmregs
        .cpl_on
        .arms_on
        .model call=internal    ; This function is recognized by name
                                ; in the compiler.
        .ref cinit
        .ref ___bss__
        .ref ___pinit__

        .def _auto_init

           .data
           .byte 0
           .text

        .sect ".bios"

;****************************************************************************/
; C VARIABLE INITIALIZATION TABLE FORMAT                                    */
;                                                                           */
;      .field <reserved>,                      2                            */
;      .field <length of init data in words>, 14                            */
;      .field <address of variable>,          24                            */
;      .field <address space indicator>,       8                            */
;      .word  <init data>                                                   */
;      .word  ...                                                           */
;                                                                           */
; The table is terminated with a record with data length zero.              */
;                                                                           */
; The first two bits of the word containing the data length are reserved,   */
; and must be 00. If you create your own cinit records and use other values */
; your code may be incompatible with a future compiler.                     */
;                                                                           */
;****************************************************************************/

;*****************************************************************************
; auto_init() - C/C++ auto-initialization. Uses .cinit sections to
;               initialize variables. Uses .pinit sections to call
;               static initialization functions
;*****************************************************************************

_auto_init:
                                ; Note: When this function is entered
                                ;       SP contains an odd address because
                                ;       of the function call.
                                ;       So, the next instruction (SP -= #1)
                                ;       will make SP contain an even address

        SP -= #1                ; Align Stack in case of pinit section

;----------------------------------------------------------------------
; Load address register with 23-bit address of cinit table
;----------------------------------------------------------------------
        .if .PHASE3
          XAR0 = #cinit
        .else
          MDP05 = #((cinit >> 16) & 0x7f)
          AR0   = #(cinit & 0xffff)
        .endif
;----------------------------------------------------------------------
;  If table pointer is -1 then exit
;----------------------------------------------------------------------
        AR7 = ~AR0
        if (AR7 == #0) goto BIOSINIT

;----------------------------------------------------------------------
; Copy data from .cinit section to .bss section
;   AR2 = data length of current record (0 => finished)
;   AC0 = 23-bit variable address in .bss section
;   AC1 = Address space indicator (0 => DATA, 1 => IO)
;----------------------------------------------------------------------
LOOP:
        AR2 = *AR0+
        if (AR2==#0) goto BIOSINIT

        AC0 = uns(*AR0+) << #8
||      AR2 = AR2 - #1
        AC1 = uns(*AR0+)
||      CSR = AR2
        AC0 = AC0 | (AC1 <<< #-8)
        AC1 = AC1 & #0xFF
;----------------------------------------------------------------------
; Load address register with 23-bit address of variable
;----------------------------------------------------------------------
        .if .PHASE3
          XAR6  = AC0
        .else
          AR6   = AC0
          MDP67 = AC0H_MMR || mmap()
        .endif
;----------------------------------------------------------------------
; Do the appropriate copy operation
;----------------------------------------------------------------------
        if (AC1 != #0) goto PORTMEMCOPY

DATAMEMCOPY:
        repeat(CSR)
          *AR6+ = *AR0+

        goto LOOP

PORTMEMCOPY:
        repeat(CSR)
          *AR6+ = *AR0+ || writeport()

        goto LOOP

;----------------------------------------------------------------------
; Initialize the runtime environment for BIOS
;----------------------------------------------------------------------
BIOSINIT:

;----------------------------------------------------------------------
; Reset address extension value
;----------------------------------------------------------------------
        .noremark 5573                          ; Safe wrt CPU_43
                                                ; Switch remark off.
        .if .PHASE3
          XAR0 = #___bss__
        .else
          MDP05 = #0
        .endif
        .remark 5573                            ; Switch remark on.

;not with MicroCOS        call BIOS_init

PINIT:
;----------------------------------------------------------------------
; Call initialization routines found in pinit table
;----------------------------------------------------------------------
;----------------------------------------------------------------------
; Load extended address register with 23-bit address of pinit table
;----------------------------------------------------------------------

        .if .PHASE3
          XAR6  = mar(*(#___pinit__))
        .else
          AR6   = #((___pinit__) & 0xffff)
          MDP67 = #(((___pinit__) >> 16) & 0x7f)
        .endif

;----------------------------------------------------------------------
;  IF table pointer is -1 then exit
;----------------------------------------------------------------------
        AR7 = ~AR6
        if (AR7 == #0) goto EXIT

LOOP2:
;----------------------------------------------------------------------
;  AC0 = address of initialization routine to call (0 => finished)
;----------------------------------------------------------------------
        AC0 = dbl(*AR6+)
        if (AC0 == #0) goto EXIT

;----------------------------------------------------------------------
; Call Initialization Function. Save/restore address extension values
; around the call to compiled code.
;----------------------------------------------------------------------
        *SP(#0) = AR6

        .noremark 5573                          ; Safe wrt CPU_43
                                                ; switch remark off.
        .if .PHASE3
          XAR6 = #___bss__
        .else
          MDP67 = #0
        .endif
        .remark 5573                            ; Switch remark on.

        call AC0

        .if .PHASE3
          XAR6  = #___pinit__
        .else
          MDP67 = #(((___pinit__) >> 16) & 0x7f)
        .endif

        AR6 = *SP(#0)
        goto LOOP2

EXIT:
;----------------------------------------------------------------------
; Reset address extension value
;----------------------------------------------------------------------
        .if .PHASE3
          XAR6 = #___bss__
        .else
          MDP67 = #0
        .endif                      

        SP += #1                

        return

