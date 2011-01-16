/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : ps40800.inc
;- Object               : AT91M40800 Power Saving Definition Assembly File.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------

;--------------------------------------------------------------
;- Power Saving Controller User Interface Structure Definition
;--------------------------------------------------------------*/
/*                ^       0
PS_CR           #       4       ;- Control Register
PS_PCER         #       4       ;- Peripheral Clock Enable Register
PS_PCDR         #       4       ;- Peripheral Clock Disable Register
PS_PCSR         #       4       ;- Peripheral Clock Status Register*/

/*;-----------------------------------------------------------
;- PS_CR: Power Saving Controller Registers Bits Definition
;-----------------------------------------------------------*/

#define PS_ARM7DIS	0x1     /*;- Disables the CPU clock*/

/*;---------------------------
;- Power Saving Base Address
;---------------------------*/

#define PS_BASE		0xFFFF4000      /*;- Disables the CPU clock*/

/*            END*/
