/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_MTU6_MTU7.h
* Component Version: 1.11.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_MTU6_MTU7.
***********************************************************************************************************************/

#ifndef CFG_Config_MTU6_MTU7_H
#define CFG_Config_MTU6_MTU7_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_mtu3.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define MTU6_PCLK_COUNTER_DIVISION      (1)
#define _000A_6TCNT_VALUE               (0x000AU) /* MTU6.TCNT value */
#define _1388_TCDRB_VALUE               (0x1388U) /* MTU.TCDRB value */
#define _09C5_6TGRB_VALUE               (0x09C5U) /* MTU6.TGRB value */
#define _09C5_7TGRA_VALUE               (0x09C5U) /* MTU7.TGRA value */
#define _09C5_7TGRB_VALUE               (0x09C5U) /* MTU7.TGRB value */
#define _1389_SUM_VALUE                 (0x1389U) /* Timer General Register (TGR) value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_MTU6_MTU7_Create(void);
void R_Config_MTU6_MTU7_Create_UserInit(void);
void R_Config_MTU6_MTU7_Start(void);
void R_Config_MTU6_MTU7_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
