//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : lib_power_save.h
//* Object              : Power Saving Function Prototyping File.
//*
//* 1.0 01/04/00 JCZ    : Creation
//*----------------------------------------------------------------------------
#ifndef lib_power_save_h
#define lib_power_save_h

#include    "std_c.h"
#include    "lib_err.h"

#ifdef AT91M40400
#include    "ps40400.h"
#endif

#ifdef AT91F40416
#include    "ps40400.h"
#endif

#ifdef AT91M40800
#include    "ps40800.h"
#endif

#ifdef AT91R40807
#include    "ps40800.h"
#endif

#ifdef AT91M63200
#include    "pmc63200.h"
#endif

#define     PS_MODE_IDLE            0x1
#define     PS_ALL_PERIPH_ACTIVE    0x2
#define     PS_ALL_PERIPH_INACTIVE  0x3

/* -----------------------*/ 
/* Function Prototyping   */ 
/* -----------------------*/ 

extern void at91_clock_set_mode ( u_int mode ) ;
extern void at91_clock_open ( u_int periph_id ) ;
extern void at91_clock_close ( u_int periph_id ) ;
extern u_int at91_clock_get_status ( u_int periph_id ) ;

#endif /* lib_power_save_h */
