/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_MTU9.c
* Component Version: 1.12.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_MTU9.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_MTU9.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU9_Create
* Description  : This function initializes the MTU9 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU9_Create(void)
{
    /* Release MTU channel 9 from stop state */
    MSTP(MTU9) = 0U;

    /* Stop MTU channel 9 counter */
    MTU.TSTRA.BIT.CST9 = 0U;

    /* Set A/D conversion signal output for ADSM0, ADSM1 pins */
    MTU.TADSTRGR0.BYTE = _00_MTU_TADSMEN_DISABLE;
    MTU.TADSTRGR1.BYTE = _00_MTU_TADSMEN_DISABLE;

    /* MTU channel 9 is used as PWM mode 1 */
    MTU.TSYRA.BIT.SYNC9 = 0U;
    MTU9.TCR.BYTE = _00_MTU_PCLK_1 | _00_MTU_CKCL_DIS;
    MTU9.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU9.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TGIEC_DISABLE | _00_MTU_TGIED_DISABLE | 
                     _00_MTU_TCIEV_DISABLE | _00_MTU_TTGE_DISABLE;
    MTU9.TIER2.BYTE = _00_MTU_TGIEE_DISABLE | _00_MTU_TGIEF_DISABLE | _00_MTU_TTGE2_DISABLE;
    MTU9.TMDR1.BYTE = _02_MTU_PWM1;
    MTU9.TIORH.BYTE = _03_MTU_IOA_LT | _50_MTU_IOB_HL;
    MTU9.TIORL.BYTE = _00_MTU_IOC_DISABLE;
    MTU9.TGRA = _0064_TGRA9_VALUE;
    MTU9.TGRB = _0064_TGRB9_VALUE;
    MTU9.TGRC = _0064_TGRC9_VALUE;
    MTU9.TGRD = _0064_TGRD9_VALUE;
    MTU9.TGRE = _0064_TGRE9_VALUE;
    MTU9.TGRF = _0064_TGRF9_VALUE;

    /* Set MTIOC9A pin */
    MPC.P00PFS.BYTE = 0x01U;
    PORT0.PMR.BYTE |= 0x01U;

    R_Config_MTU9_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU9_Start
* Description  : This function starts the MTU9 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU9_Start(void)
{
    /* Start MTU channel 9 counter */
    MTU.TSTRA.BIT.CST9 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU9_Stop
* Description  : This function stops the MTU9 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU9_Stop(void)
{
    /* Stop MTU channel 9 counter */
    MTU.TSTRA.BIT.CST9 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
