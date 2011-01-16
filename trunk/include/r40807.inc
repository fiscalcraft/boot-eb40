/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : r40807.inc
;- Object               : AT91R40807 Definition File.
;-
;- 1.0 06/04/00 JPP     : Creation
;------------------------------------------------------------------------------


;--------------------------
;- Internal RAM Definition
;--------------------------*/

#define LARGE_RAM_SIZE	(128*1024)
#define LARGE_RAM_BASE	(0x00100000)
#define LARGE_RAM_LIMIT	(LARGE_RAM_BASE + LARGE_RAM_SIZE)

#include         "m40800.inc"

           /*     END*/
