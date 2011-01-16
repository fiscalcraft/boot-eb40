//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : at91eb40.h
//* Object              : AT91EB40 Features Definition File
//*
//* 1.0 06/04/00 JPP    : Creation
//*----------------------------------------------------------------------------

#ifndef at91eb40_h
#define at91eb40_h

/* peripheral control */
#define PERIPHERAL      ((1<<PIOTXD0) | (1<<PIORXD0) | (1<<PIOTXD1) | (1<<PIORXD1) | (1<<PIOFIQ) | (1<<PIOIRQ0))

/* PIO output control */
#define PIO_OUT         ((1<<PIOTIOA0) | (1<<PIOTIOB0) | (1<<PIOTIOA1))

#define LED1            (1<<PIOTIOA0)           /* LED 1 - Red */
#define LED2            (1<<PIOTIOA1)           /* LED 2 - Amber */
#define LED3            (1<<PIOTIOB0)           /* LED 3 - Green */
#define LED1_2          (LED1 | LED2)           /* LEDs 1 and 2 */
#define LED1_3          (LED1 | LED3)           /* LEDs 1 and 3 */
#define LED2_3          (LED2 | LED3)           /* LEDs 2 and 3 */
#define LED1_2_3        (LED1 | LED2 | LED3)    /* LEDs 1, 2 and 3 */
#define SW3             (1<<PIOFIQ)             /* SW3 button */
#define SW4             (1<<PIOTIOB1)           /* SW4 button */
#define SW5             (1<<PIOIRQ0)            /* SW5 button */

#endif /* at91eb40_h */
