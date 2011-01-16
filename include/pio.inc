/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : pio.inc
;- Object               : Assembler PIO Controller Definition File.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------

;------------------------------------------------------------
; Parallel IO Controller User Interface Structure Definition
;------------------------------------------------------------*/
/*                    ^       0
PIO_PER             #       4           ;- PIO Enable Register
PIO_PDR             #       4           ;- PIO Disable Register
PIO_PSR             #       4           ;- PIO Status Register
                    #       4           ;- Reserved 0
PIO_OER             #       4           ;- Output Enable Register
PIO_ODR             #       4           ;- Output Disable Register
PIO_OSR             #       4           ;- Output Status Register
                    #       4           ;- Reserved 1
PIO_IFER            #       4           ;- Input Filter Enable Register
PIO_IFDR            #       4           ;- Input Filter Disable Register
PIO_IFSR            #       4           ;- Input Filter Status Register
                    #       4           ;- Reserved 2
PIO_SODR            #       4           ;- Set Output Data Register
PIO_CODR            #       4           ;- Clear Output Data Register
PIO_ODSR            #       4           ;- Output Data Status Register
PIO_PDSR            #       4           ;- Pin Data Status Register
PIO_IER             #       4           ;- Interrupt Enable Register
PIO_IDR             #       4           ;- Interrupt Disable Register
PIO_IMR             #       4           ;- Interrupt Mask Register
PIO_ISR             #       4           ;- Interrupt Status Register
PIO_MDER            #       4           ;- Interrupt Enable Register
PIO_MDDR            #       4           ;- Interrupt Disable Register
PIO_MDSR            #       4           ;- Interrupt Status Register*/

/*;-------------------------------------------------
;- PIO Controller Descriptor Structure Definition
;-------------------------------------------------*/
 /*                   ^       0
PioBase             #       4           ;- Peripheral base address
AsmPioHandler       #       4           ;- Assembly interrupt handler
PioHandlerPt        #       4
PeriphId            #       1           ;- Peripheral Identifier
PioNumber           #       1

                END*/
