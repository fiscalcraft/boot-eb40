//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : ps40400.h
//* Object              : Power Saving Header File.
//*
//* 1.0 01/04/00 JCZ    : Creation
//*----------------------------------------------------------------------------

#ifndef ps40400_h
#define ps40400_h

/*--------------------------------------------------*/
/* Power Saving User Interface Structure Definition */
/*--------------------------------------------------*/
typedef struct
{
    at91_reg    PS_CR ;     /* Control Register */

} StructPS ;

/*------------------------------------------------------*/
/* PS_CR: Power Saving Control Register Bits Definition */
/*------------------------------------------------------*/

#define PS_ARM7DIS          0x1

/*---------------------------*/ 
/* Power Saving Base Address */
/*---------------------------*/ 

#define PS_BASE         (( StructPS *) 0xFFFF4000)

#endif /* ps40400_h */
