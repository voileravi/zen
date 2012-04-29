;*********************************************************************************************************
;                                               vectors.asm
;
;   Copyright 2004, Validated Software Corporation, Lafayette, CO
;   All Rights Reserved

;   Author:     Jim Elliott
;   Date:       26-Apr-03

;   References:
;   $Workfile: vectors.asm $
;
;   Description:    These are interrupt vectors.
;
;   Contents:
;		This is a table of interrupt vectors.  There is no executable code here.
;       The section "vectors" is known to the linker control file.  The linker
;       places this code at the proper address for use as an interrupt vector table.
;
;   Revision History - latest change on top
;
;   $Log:  $
;
;*********************************************************************************************************



;   MODULE ENTRY POINT:
        .def   Interrupt_Vectors
;
	.mmregs

;   SUBROUTINES CALLED

        .ref    _OSCtxSw, _c_int00, _OSTickISR, _InvalidISR, _BerrISR, _IntStack

           .data
           .byte 0
           .text

;********************************* LOCALS *************************************
; DEFINITIONS:
;
;*********************************   BODY   ***********************************
        .sect  "vectors"
        .align  256

Interrupt_Vectors:

Reset_int:      .ivec   _c_int00, NO_RETA

NMI_int:        .ivec   NMI_int         ;Non-maskable Interrupt Vector (vector_base + 0x8)

                .ivec   _InvalidISR     ;Int0 Interrupt Vector  (vector_base + 0x10)

                .ivec   _InvalidISR     ;Int1 Interrupt Vector  (vector_base + 0x18)

Timer_INT:      .ivec   _OSTickISR      ;Timer Interrupt Vector  (vector_base + 0x20)

                .ivec   _IntStack	; Stack Initialization entry point

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

SWINT10:        .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

SWINT15:        .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

SWINT20:        .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .if $isdefed("BOOTTEST")  ; Syntax shown in assembly guide section 3.9.3.
                ; Only change vector 23 for the test UCUT-Boot.
                .ref    _testISR
                .ivec   _testISR        ;Function to test interrupt context switching.
                .else
                .ivec   _InvalidISR     ;Unused Software Interrupt Vector
                .endif

BERR:           .ivec   _BerrISR        ; Bus Error Interrupt Vector

SWINT25:        .ivec   _InvalidISR     ;Unused Software Interrupt Vector

RTOS:           .ivec   _OSCtxSw        ; MicroC/OS-II Context Switch Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector

SWINT30:        .ivec   _InvalidISR     ;Unused Software Interrupt Vector

                .ivec   _InvalidISR     ;Unused Software Interrupt Vector


.end
