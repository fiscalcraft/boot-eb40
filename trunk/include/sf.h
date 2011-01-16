//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : sf.h
//* Object              : Special Function Header File.
//*
//* 1.0 01/04/00 JCZ    : Creation
//*----------------------------------------------------------------------------

#ifndef sf_h
#define sf_h

#include    "std_c.h"

/*---------------------------------------------------------*/
/* Chip Identification User Interface Structure Definition */
/*---------------------------------------------------------*/

typedef struct
{
    at91_reg    SF_CIDR ;       /* Chip Identification Register */
    at91_reg    SF_EXID ;       /* Chip Identification Extension */
    at91_reg    SF_RSR ;		/* Reset Status Flag */
#ifndef AT91M40400
#ifndef AT91M63200
    at91_reg    SF_MMR ;		/* Memory Mode Register */
#endif
#endif
    at91_reg    Reserved0 ;
    at91_reg    Reserved1 ;
    at91_reg    Reserved2 ;
    at91_reg    SF_PMR ;        /* Protect Mode Register */
} StructSF ;

/*-------------------------------------------------------*/
/* SF_CIDR: Chip Identification Register Bits Definition */
/*-------------------------------------------------------*/

#define SF_VERSION          0x1F                 /* Version Number */
#define SF_NVPSIZ           0xF00                /* Non Volatile Program Memory Size */
#define SF_NVDSIZ           (0x0F<<12)           /* Non Volatile Data Memory Size */
#define SF_VDSIZ            (0x0F<<16)           /* Volatile Data Memory Size */
#define SF_ARCH             (0xFF<<20)           /* Architecture Code */
#define SF_NVPTYP           (0x07<<28)           /* Non Volatile Program Memory Type */
#define SF_EXT              ((u_int)0x01<<31)    /* Extension Flag */

/*--------------------------------------*/
/* SF_RSR: Reset Status Flag Definition */
/*--------------------------------------*/

#define SF_EXT_RESET       0x6C                 /* External pin Cause Reset */
#define SF_WD_RESET        0x53                 /* Internal WatchDog Cause Reset */

/*----------------------------------*/
/* SF_PMR: Protect Control Register */
/*----------------------------------*/

#define SF_AIC             (0x1<<5)


/*--------------------------------*/
/* Sspecial Function Base Address */
/*--------------------------------*/

#define SF_BASE            ((StructSF *)  0xFFF00000)

#endif /* sf_h */
