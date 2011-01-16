//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : eb40.h
//* Object              : AT91 Evaluation Board Features Definition File
//*
//* 1.0 06/04/00 JPP    : Creation
//*----------------------------------------------------------------------------

#ifndef eb40_h
#define eb40_h

#include    "r40807.h"      /* library definition */

/*---------------------------------------*/
/* AT91EB40 External Memories Definition */
/*---------------------------------------*/

/* Flash Memory : AT29LV1024 64k*16 */
#define FLASH_BASE      ((u_int *)0x01000000)

/* SRAM : size is depending on the devices fitted on the board */
#define SRAM_BASE       ((u_int *)0x02000000)

/*--------------------------------*/
/* AT91E40 Interfaces Definition */
/*--------------------------------*/

#define LED1        (1<<1)          /* Red Led */
#define LED2        (1<<4)          /* Amber Led */
#define LED3        (1<<2)          /* Green Led */
#define LED_MASK    (LED1|LED2|LED3)

#define SW3_MASK    (1<<12)     /* SW3 Push Button FIQ */
#define SW4_MASK    (1<<5)      /* SW4 Push Button */
#define SW5_MASK    (1<<9)      /* SW5 Push Button IRQ0 */

#define SW_MASK     (SW3_MASK|SW4_MASK|SW5_MASK)
#define PIO_SW3     (1<<12)
#define PIO_SW4     (1<<5)
#define PIO_SW5     (1<<9)

#define IRQ_SW3     0               /* SW3 Push Button FIQ */
#define IRQ_SW5     16              /* SW5 Push Button IRQ0 */

/*--------------*/
/* Master Clock */
/*--------------*/

#define MCK         32768000
#define MCKMHz      (MCK/1000000)

#endif /* eb40_h */
