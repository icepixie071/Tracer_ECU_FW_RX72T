/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_GPT2.h
* Component Version: 1.5.2
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_GPT2.
***********************************************************************************************************************/

#ifndef CFG_Config_GPT2_H
#define CFG_Config_GPT2_H

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
#define GPT2_PCLK_COUNTER_DIVISION                      (1)
#define _00002710_GPT2_CYCLE_VALUE                      (0x00002710UL) /* GPT2 cycle register value */
#define _00000000_GPT2_INIT_COUNT                       (0x00000000UL) /* GPT2 initial counter value */
#define _00000064_GPT2_COMP_MATCH_A_VALUE               (0x00000064UL) /* GPT2 compare match A value */
#define _00000064_GPT2_COMP_MATCH_C_VALUE               (0x00000064UL) /* GPT2 compare match C value */
#define _00000064_GPT2_COMP_MATCH_D_VALUE               (0x00000064UL) /* GPT2 compare match D value */
#define _00000064_GPT2_COMP_MATCH_E_VALUE               (0x00000064UL) /* GPT2 compare match E value */
#define _00000064_GPT2_COMP_MATCH_F_VALUE               (0x00000064UL) /* GPT2 compare match F value */
#define _00000000_GPT2_DEADTIME_UP_VALUE                (0x00000000UL) /* GPT2 upcount dead time value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_GPT2_Create(void);
void R_Config_GPT2_Create_UserInit(void);
void R_Config_GPT2_Start(void);
void R_Config_GPT2_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
