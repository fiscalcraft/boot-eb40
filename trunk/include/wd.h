//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : wd.h
//* Object              : Watch Dog Header File.
//*
//* 1.0 01/04/00 JCZ    : Creation
//*----------------------------------------------------------------------------

#ifndef wd_h
#define wd_h

#include    "std_c.h"
#include    "lib_aic.h"

/*------------------------------------------------*/
/*  Watch Dog User Interface Structure Definition */
/*------------------------------------------------*/
typedef struct
{
    at91_reg        WD_OMR ;        /* Overflow Mode Register */
    at91_reg        WD_CMR ;        /* Clock Mode Register */
    at91_reg        WD_CR ;         /* Control Register */
    at91_reg        WD_SR ;         /* Status Register */
    at91_reg        Reserved ;
    at91_reg        WD_TLR ;        /* Test Load Register : test purpose only */
} StructWD ;

/*-----------------------------------------------------------*/
/*  WD_OMR: Watch Dog Overflow Mode Register Bits Definition */
/*-----------------------------------------------------------*/

#define WD_WDEN             0x1         /* Watch Dog Enable */
#define WD_RSTEN            0x2         /* Internal Reset Enable */
#define WD_IRQEN            0x4         /* Interrupt Enable */
#define WD_EXTEN            0x8         /* External Signal Enable */
#define WD_OKEY             0x2340      /* Overflow Mode Register Access Key */

/*--------------------------------------------------*/
/* WD_CMR: Watch Dog Clock Register Bits Definition */
/*--------------------------------------------------*/

#define WD_WDCLKS           0x3         /* Clock Selection */
#define WD_WDCLKS_MCK8      0x0
#define WD_WDCLKS_MCK32     0x1
#define WD_WDCLKS_MCK128    0x2
#define WD_WDCLKS_MCK1024   0x3

#define WD_HPCV             0x3C        /* High Preload Counter Value */

#define WD_CKEY             (0x06E<<7)  /* Clock Register Access Key */

/*---------------------------------------------------*/
/* WD_CR: Watch Dog Control Register Bits Definition */
/*---------------------------------------------------*/

#define WD_RSTKEY           0xC071      /* Watch Dog Restart Key */

/*--------------------------------------------------*/
/* WD_SR: Watch Dog Status Register Bits Definition */
/*--------------------------------------------------*/

#define WD_WDOVF            0x1         /* WatchDog Overflow Status */

/*--------------------------------------------------*/
/* WD_TLR: Test Load Register for test purpose only */
/*--------------------------------------------------*/

#define WD_TMRKEY           0xD64A0000  /* Access Key */
#define WD_TESTEN           0x2         /* Test Mode Enable */


#endif /* wd_h */
