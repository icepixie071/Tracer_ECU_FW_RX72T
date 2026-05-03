/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_MTU1.c
* Component Version: 2.4.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_MTU1.
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
#include "Config_MTU1.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU1_Create
* Description  : This function initializes the MTU1 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU1_Create(void)
{
    /* Release MTU channel 1 from stop state */
    MSTP(MTU1) = 0U;

    /* Stop MTU channel 1 counter */
    MTU.TSTRA.BIT.CST1 = 0U;

    /* Set external clock noise filter */
    MTU0.NFCRC.BIT.NFAEN = 0U;
    MTU0.NFCRC.BIT.NFBEN = 0U;

    /* Set A/D conversion signal output for ADSM0, ADSM1 pins */
    MTU.TADSTRGR0.BYTE = _00_MTU_TADSMEN_DISABLE;
    MTU.TADSTRGR1.BYTE = _00_MTU_TADSMEN_DISABLE;

    /* MTU channel 1 is used as phase counting mode */
    MTU1.TMDR1.BYTE = _04_MTU_COT1;
    MTU1.TMDR3.BIT.PHCKSEL = 0U;
    MTU.TSYRA.BIT.SYNC1 = 0U;
    MTU1.TCR.BYTE = _00_MTU_CKCL_DIS;
    MTU1.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TCIEV_DISABLE | _00_MTU_TCIEU_DISABLE | 
                     _00_MTU_TTGE_DISABLE;
    MTU1.TIOR.BYTE = _00_MTU_IOA_DISABLE | _00_MTU_IOB_DISABLE;
    MTU1.TGRA = _0063_TGRA1_VALUE;
    MTU1.TGRB = _0063_TGRB1_VALUE;

    /* Set MTCLKA pin */
    MPC.P33PFS.BYTE = 0x02U;
    PORT3.PMR.BYTE |= 0x08U;

    /* Set MTCLKB pin */
    MPC.P32PFS.BYTE = 0x02U;
    PORT3.PMR.BYTE |= 0x04U;

    R_Config_MTU1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU1_Start
* Description  : This function starts the MTU1 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU1_Start(void)
{
    /* Start MTU channel 1 counter */
    MTU.TSTRA.BIT.CST1 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU1_Stop
* Description  : This function stops the MTU1 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU1_Stop(void)
{
    /* Stop MTU channel 1 counter */
    MTU.TSTRA.BIT.CST1 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
