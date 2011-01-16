//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : ebi.h
//* Object              : External Bus Interface Definition File
//*
//* 1.0 01/04/00 JCZ    : Creation
//*----------------------------------------------------------------------------

#ifndef ebi_h
#define ebi_h

#include    "std_c.h"

/*-------------------------------------------------------*/
/* Memory Controller User Interface Structure Definition */
/*-------------------------------------------------------*/

typedef struct
{
    at91_reg        EBI_CSR[8] ;        /* Chip Select Register */
    at91_reg        EBI_RCR ;           /* Remap Control Register */
    at91_reg        EBI_MCR ;           /* Memory Control Register */
} StructEBI ;

/*--------------------------------*/
/* EBI_CSR: Chip Select Registers */
/*--------------------------------*/

#define EBI_DBW             0x3         /* Data Bus Width */
#define EBI_DBW_16          0x1         /* 16-bit Data Bus */
#define EBI_DBW_8           0x2         /* 8-bit Data Bus */

#define EBI_NWS             0x1C        /* Number of Wait States */
#define EBI_NWS_1           0x0         /* 1 wait state */
#define EBI_NWS_2           0x4         /* 2 wait state */
#define EBI_NWS_3           0x8         /* 3 wait state */
#define EBI_NWS_4           0xC         /* 4 wait state */
#define EBI_NWS_5           0x10        /* 5 wait state */
#define EBI_NWS_6           0x14        /* 6 wait state */
#define EBI_NWS_7           0x18        /* 7 wait state */
#define EBI_NWS_8           0x1C        /* 8 wait state */

#define EBI_WSE             0x20        /* Wait State Enable */

#define EBI_PAGES           0x180       /* Page size */
#define EBI_PAGES_1M        0x0         /* 1 Mbytes */
#define EBI_PAGES_4M        0x80        /* 4 Mbytes */
#define EBI_PAGES_16M       0x100       /* 16 Mbytes */
#define EBI_PAGES_64M       0x180       /* 64 Mbytes */

#define EBI_TDF             0xE00       /* Number of Data Float Output Time Clock Cycle */
#define EBI_TDF_0           0x0         /* 0 cycles added */
#define EBI_TDF_1           0x200       /* 1 cycles added */
#define EBI_TDF_2           0x400       /* 2 cycles added */
#define EBI_TDF_3           0x600       /* 3 cycles added */
#define EBI_TDF_4           0x800       /* 4 cycles added */
#define EBI_TDF_5           0xA00       /* 5 cycles added */
#define EBI_TDF_6           0xC00       /* 6 cycles added */
#define EBI_TDF_7           0xE00       /* 7 cycles added */

#define EBI_BAT             0x1000      /* Byte Access Type */
#define EBI_BAT_BYTE_WRITE  0x0         /* Byte Write Access Type */
#define EBI_BAT_BYTE_SELECT 0x1000      /* Byte Select Access Type */

#define EBI_CSE             0x2000      /* Chip Select Enable */

#define EBI_BA              0xFFF00000

/*---------------------------------*/
/* EBI_RCR: Remap Control Register */
/*---------------------------------*/

#define EBI_RCB             0x1         /* Remap Command Bit */

/*----------------------------------*/
/* EBI_MCR: Memory Control Register */
/*----------------------------------*/

#define EBI_ALE             0x7         /* Address Line Enable */
#define EBI_ALE_16M         0x0         /* Bank Size 16Mbytes */
#define EBI_ALE_8M          0x4         /* Bank Size 16Mbytes */
#define EBI_ALE_4M          0x5         /* Bank Size 16Mbytes */
#define EBI_ALE_2M          0x6         /* Bank Size 16Mbytes */
#define EBI_ALE_1M          0x7         /* Bank Size 16Mbytes */

#define EBI_DRP             0x10        /* Data Read Protocol */
#define EBI_DRP_STANDARD    0x0         /* Standard Read Protocol */
#define EBI_DRP_EARLY       0x10        /* Early Read Protocol */

/*------------------*/
/* EBI Base Address */
/*------------------*/
#define EBI_BASE            ((StructEBI *)0xFFE00000)

#endif /* ebi_h */
