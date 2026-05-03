/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_S12AD2.h
* Component Version: 1.13.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_S12AD2.
***********************************************************************************************************************/

#ifndef CFG_Config_S12AD2_H
#define CFG_Config_S12AD2_H

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
#define _1B_AD2_SAMPLING_STATE_0           (0x1BU)   /* AN200 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_1           (0x1BU)   /* AN201 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_2           (0x1BU)   /* AN202 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_3           (0x1BU)   /* AN203 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_6           (0x1BU)   /* AN206 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_7           (0x1BU)   /* AN207 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_8           (0x1BU)   /* AN208 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_9           (0x1BU)   /* AN209 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_10          (0x1BU)   /* AN210 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_11          (0x1BU)   /* AN211 sampling time setting */
#define _1B_AD2_SAMPLING_STATE_L           (0x1BU)   /* AN216-AN217 sampling time setting */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_S12AD2_Create(void);
void R_Config_S12AD2_Create_UserInit(void);
void R_Config_S12AD2_Start(void);
void R_Config_S12AD2_Stop(void);
void R_Config_S12AD2_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
