//*---------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*---------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*-----------------------------------------------------------------------------
//* File Name           : lib_m40800.h
//* Object              : AT91M40800 Definition File
//*
//* 1.0 01/04/00 JCZ    : Creation
//*---------------------------------------------------------------------------

#ifndef lib_m40800_h
#define lib_m40800_h

#include    "m40800.h"

/*----------------------------*/
/* Special Function Registers */
/*----------------------------*/
#include    "lib_sf.h"

/*------------------------*/
/* External Bus Interface */
/*------------------------*/
#include    "lib_ebi.h"

/*--------------------------*/
/* Power Saving Controller  */
/*--------------------------*/
#include    "lib_power_save.h"

/*-------------------------------*/
/* Advanced Interrupt Controller */
/*-------------------------------*/

#include    "lib_aic.h"
#include    "lib_ext_irq.h"

/* Descriptor */
extern const ExtIrqDesc     IRQ0_DESC ;  /* IRQ0 Descriptor */
extern const ExtIrqDesc     IRQ1_DESC ;  /* IRQ1 Descriptor */
extern const ExtIrqDesc     IRQ2_DESC ;  /* IRQ2 Descriptor */
extern const ExtIrqDesc     FIQ_DESC ;   /* FIQ Descriptor */

/*-------------------------*/
/* Parallel I/O Controller */
/*-------------------------*/
#include    "lib_pio.h"

/* Descriptor */
extern const PioCtrlDesc PIO_DESC ;         /* PIO Controller Descriptor */

/*--------*/
/* USARTs */
/*--------*/
/* Definition file */
#include    "lib_usart.h"

/* USART descriptor */
extern const UsartDesc USART0_DESC ;        /* USART 0 Descriptor */
extern const UsartDesc USART1_DESC ;        /* USART 1 Descriptor */


/*----------*/
/* Watchdog */
/*----------*/
/* Definition file */
#include    "lib_wd.h"

/*---------------*/
/* Timer Counter */
/*---------------*/
#include    "lib_tc.h"


/* Descriptor */
extern const TCDesc TC0_DESC ;          /* Timer Counter Channel 0 Descriptor */
extern const TCDesc TC1_DESC ;          /* Timer Counter Channel 2 Descriptor */
extern const TCDesc TC2_DESC ;          /* Timer Counter Channel 2 Descriptor */

#endif /* lib_m40800_h */
