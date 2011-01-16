;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : ps40400.inc
;- Object               : Assembler Power Saving Definition File for 40400.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------

;--------------------------------------------------------------
;- Power Saving Controller User Interface Structure Definition
;--------------------------------------------------------------
                ^       0
PS_CR           #       4       ;- Control Register

;-----------------------------------------------------------
;- PS_CR: Power Saving Controller Registers Bits Definition
;-----------------------------------------------------------

PS_ARM7DIS          EQU     0x1     ;- Disables the CPU clock

;---------------------------
;- Power Saving Base Address
;---------------------------

PS_BASE             EQU     0xFFFF4000      ;- Disables the CPU clock

            END
