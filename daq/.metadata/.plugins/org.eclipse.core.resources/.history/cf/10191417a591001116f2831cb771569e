;****************************************************************************
; Interrupt Vector Table
;
; 32 interrupt vector addresses.  Each is 64 bits long.  The first 32 bits
; contains the 24-bit program address of the Interrupt Service Routine (ISR).
; The second 32 bits are executed before transferring control to the ISR.
;****************************************************************************
	.C54CM_off
    .CPL_off
    .ARMS_off
    .sect   "vectors"
    .align  256
    .global _VECSTART

;****************************************************************************
;* Point Reset Vector to C Environment Entry Point
;****************************************************************************
   	.def 	_Reset
    .ref    _c_int00
	.ref	_TINT_isr
	.ref	_RTC_isr
	.ref	_illegal_isr
_VECSTART:

;****************************************************************************
;* interrupt vector definitions
;****************************************************************************
    .if __TMS320C55X_PLUS_BYTE__
_Reset:    .ivec _c_int00, STK_LINEAR | RET_FAST | DATA_PTR_BYTE
    .else
_Reset:    .ivec _c_int00, USE_RETA
    .endif
NMI:		.ivec    _illegal_isr	       ; Nonmaskable Interrupt

INT0:		.ivec    _illegal_isr          ; External User Interrupt #0

INT1:		.ivec    _illegal_isr	       ; External User Interrupt #1

TINT:		.ivec    _TINT_isr	       ; Timer #0 / Software Interrupt #4

PROG0:		.ivec    _illegal_isr  ; Programmable 0 Interrupt

UART:		.ivec    _illegal_isr		   ; IIS #1 Receive Interrupt

PROG1:		.ivec    _illegal_isr  ; Programmable 1 Interrupt

DMA:		.ivec    _illegal_isr           ; DMA Interrupt

PROG2:		.ivec    _illegal_isr  ; Programmable 2 Interrupt

COPROCFFT:  .ivec    _illegal_isr	   ; Coprocessor FFT Module Interrupt

PROG3:		.ivec    _illegal_isr  ; Programmable 3 Interrupt

LCD:		.ivec	 _illegal_isr		   ; LCD Interrupt

SARADC:		.ivec    _illegal_isr		   ; SAR ADC Interrupt

XMT2:		.ivec	 _illegal_isr	   ; I2S2 Tx Interrupt

RCV2:		.ivec	 _illegal_isr	   ; I2S2 Rx Interrupt

XMT3:		.ivec	 _illegal_isr	   ; I2S3 Tx Interrupt

RCV3:		.ivec	 _illegal_isr	   ; I2S3 Rx Interrupt

RTC:		.ivec    _RTC_isr		   ; RTC interrupt

SPI:    	.ivec    _illegal_isr		   ; SPI Receive Interrupt

USB:		.ivec    _illegal_isr		   ; USB Transmit Interrupt

GPIO:		.ivec    _illegal_isr		   ; GPIO Interrupt

EMIF:	    .ivec    _illegal_isr	   ; EMIF Error Interrupt

I2C:		.ivec    _illegal_isr		   ; IIC interrupt

BERR:		.ivec    _illegal_isr		   ; Bus Error Interrupt

DLOG:		.ivec    _illegal_isr		   ; Emulation Interrupt - DLOG

RTOS:		.ivec    _illegal_isr		   ; Emulation Interrupt - RTOS

RTDXRCV:	.ivec    _illegal_isr	   ; Emulation Interrupt - RTDX receive

RTDXXMT:	.ivec    _illegal_isr	   ; Emulation Interrupt - RTDX transmit

EMUINT:		.ivec    _illegal_isr		   ; Emulation monitor mode interrupt

SINT30:		.ivec    _illegal_isr		   ; Software Interrupt #30

SINT31:		.ivec    _illegal_isr		   ; Software Interrupt #31

    .end
