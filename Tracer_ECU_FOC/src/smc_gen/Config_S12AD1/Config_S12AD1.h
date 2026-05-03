/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_S12AD1.h
* Component Version: 1.13.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_S12AD1.
***********************************************************************************************************************/

#ifndef CFG_Config_S12AD1_H
#define CFG_Config_S12AD1_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_s12ad.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _00C9_AD_PGA_STABLE_WAIT_COUNT     (0x00C9U) /* PGA stabilization 5us wait time */
#define _001B_AD1_DSH_SAMPLING_STATE       (0x001BU) /* Dedicated sample-and-hold circuit sampling time setting */
#define _1B_AD1_SAMPLING_STATE_0           (0x1BU)   /* AN100 sampling time setting */
#define _1B_AD1_SAMPLING_STATE_1           (0x1BU)   /* AN101 sampling time setting */
#define _1B_AD1_SAMPLING_STATE_2           (0x1BU)   /* AN102 sampling time setting */
#define _1B_AD1_SAMPLING_STATE_3           (0x1BU)   /* AN103 sampling time setting */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_S12AD1_Create(void);
void R_Config_S12AD1_Create_UserInit(void);
void R_Config_S12AD1_Start(void);
void R_Config_S12AD1_Stop(void);
void R_Config_S12AD1_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
