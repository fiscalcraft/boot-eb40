//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : arm.h
//* Object              : Arm7TDMI Header File
//*
//* 1.0 01/04/00 JCZ    : Creation
//*----------------------------------------------------------------------------

#ifndef arm_h
#define arm_h

/*--------------------------*/
/* ARM Mode and Status Bits */
/*--------------------------*/

#define     ARM_MODE_USER       0x10
#define     ARM_MODE_FIQ        0x11
#define     ARM_MODE_IRQ        0x12
#define     ARM_MODE_SVC        0x13
#define     ARM_MODE_ABORT      0x17
#define     ARM_MODE_UNDEF      0x1B
#define     ARM_MODE_SYS        0x1F

#define     I_BIT               0x80
#define     F_BIT               0x40
#define     T_BIT               0x20

#endif /* arm_h */
