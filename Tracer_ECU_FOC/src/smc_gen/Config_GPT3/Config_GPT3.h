/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_GPT3.h
* Component Version: 1.5.2
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_GPT3.
***********************************************************************************************************************/

#ifndef CFG_Config_GPT3_H
#define CFG_Config_GPT3_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_gpt.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define GPT3_PCLK_COUNTER_DIVISION                      (1)
#define _00004E1F_GPT3_CYCLE_VALUE                      (0x00004E1FUL) /* GPT3 cycle register value */
#define _00000000_GPT3_INIT_COUNT                       (0x00000000UL) /* GPT3 initial counter value */
#define _00000064_GPT3_COMP_MATCH_A_VALUE               (0x00000064UL) /* GPT3 compare match A value */
#define _00000064_GPT3_COMP_MATCH_B_VALUE               (0x00000064UL) /* GPT3 compare match B value */
#define _00000064_GPT3_COMP_MATCH_C_VALUE               (0x00000064UL) /* GPT3 compare match C value */
#define _00000064_GPT3_COMP_MATCH_D_VALUE               (0x00000064UL) /* GPT3 compare match D value */
#define _00000064_GPT3_COMP_MATCH_E_VALUE               (0x00000064UL) /* GPT3 compare match E value */
#define _00000064_GPT3_COMP_MATCH_F_VALUE               (0x00000064UL) /* GPT3 compare match F value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_GPT3_Create(void);
void R_Config_GPT3_Create_UserInit(void);
void R_Config_GPT3_Start(void);
void R_Config_GPT3_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
