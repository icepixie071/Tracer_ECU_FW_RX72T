/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_MTU6_MTU7.c
* Component Version: 1.11.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_MTU6_MTU7.
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
#include "Config_MTU6_MTU7.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU6_MTU7_Create
* Description  : This function initializes the MTU6 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU6_MTU7_Create(void)
{
    /* Release MTU channel 6 from stop state */
    MSTP(MTU6) = 0U;

    /* Enable read/write to MTU6, MTU7 registers */
    MTU.TRWERB.BIT.RWE = 1U;

    /* Stop MTU channel 6 counter */
    MTU.TSTRB.BIT.CST6 = 0U;
    MTU.TSTRB.BIT.CST7 = 0U;

    /* Set timer synchronous clear */
    MTU6.TSYCR.BYTE = _00_MTU6_CL0A_OFF | _00_MTU6_CL0B_OFF | _00_MTU6_CL0C_OFF | _00_MTU6_CL0D_OFF | 
                      _00_MTU6_CL1A_OFF | _00_MTU6_CL1B_OFF | _00_MTU6_CL2A_OFF | _00_MTU6_CL2B_OFF;

    /* Set A/D conversion signal output for ADSM0, ADSM1 pins */
    MTU.TADSTRGR0.BYTE = _00_MTU_TADSMEN_DISABLE;
    MTU.TADSTRGR1.BYTE = _00_MTU_TADSMEN_DISABLE;

    /* MTU channel 6 is used as complementary PWM mode 3 */
    MTU6.TIER.BYTE = 0x00U;
    MTU7.TIER.BYTE = 0x00U;
    MTU.TITCR1B.BIT.T6AEN = 0U;
    MTU.TITCR1B.BIT.T7VEN = 0U;
    MTU6.TCR.BYTE = _00_MTU_PCLK_1 | _60_MTU_CKCL_SYN;
    MTU7.TCR.BYTE = _00_MTU_PCLK_1;
    MTU6.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU7.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU.TGCRB.BYTE = _80_MTU_BDC_OUT;
    MTU6.TCNT = _000A_6TCNT_VALUE;
    MTU7.TCNT = 0x0000U;
    MTU.TSYRB.BIT.SYNC6 = 1U;
    MTU.TSYRB.BIT.SYNC7 = 1U;
    MTU6.TGRB = _09C5_6TGRB_VALUE;
    MTU6.TGRD = _09C5_6TGRB_VALUE;
    MTU7.TGRA = _09C5_7TGRA_VALUE;
    MTU7.TGRC = _09C5_7TGRA_VALUE;
    MTU7.TGRB = _09C5_7TGRB_VALUE;
    MTU7.TGRD = _09C5_7TGRB_VALUE;
    MTU.TDERB.BIT.TDER = 0U;
    MTU.TDDRB = 0x0001U;
    MTU.TCDRB = _1388_TCDRB_VALUE;
    MTU.TCBRB = _1388_TCDRB_VALUE;
    MTU6.TGRA = _1389_SUM_VALUE;
    MTU6.TGRC = _1389_SUM_VALUE;
    MTU.TOCR1B.BYTE = _00_MTU_PSYE_DISABLE | _08_MTU_TOCL_DISABLE | _04_MTU_TOCS_TOCR2;
    MTU.TOCR2B.BYTE = _C0_MTU_TOLBR_CT | _00_MTU_OLS3N_HL | _10_MTU_OLS3P_LH | _00_MTU_OLS2N_HL | _04_MTU_OLS2P_LH | 
                      _00_MTU_OLS1N_HL | _01_MTU_OLS1P_LH;
    MTU.TOLBRB.BYTE = MTU.TOCR2B.BYTE & 0x3FU;
    MTU6.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TTGE_DISABLE;
    MTU7.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TCIEV_DISABLE | _00_MTU_TTGE2_DISABLE;
    MTU.TITMRB.BIT.TITM = 0U;
    MTU6.TMDR1.BYTE = _0F_MTU_CMT3 | _10_MTU_BFA_BUFFER | _20_MTU_BFB_BUFFER;
    MTU.TOERB.BYTE = _E0_MTU_OE7D_ENABLE | _D0_MTU_OE7C_ENABLE | _C8_MTU_OE6D_ENABLE | _C4_MTU_OE7B_ENABLE | 
                     _C2_MTU_OE7A_ENABLE | _C1_MTU_OE6B_ENABLE;

    /* Disable read/write to MTU6, MTU7 registers */
    MTU.TRWERB.BIT.RWE = 0U;

    /* Set MTIOC6B pin */
    MPC.P95PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x20U;

    /* Set MTIOC6D pin */
    MPC.P92PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x04U;

    /* Set MTIOC7A pin */
    MPC.P94PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x10U;

    /* Set MTIOC7B pin */
    MPC.P93PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x08U;

    /* Set MTIOC7C pin */
    MPC.P91PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x02U;

    /* Set MTIOC7D pin */
    MPC.P90PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x01U;

    R_Config_MTU6_MTU7_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU6_MTU7_Start
* Description  : This function starts the MTU6 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU6_MTU7_Start(void)
{
    /* Start MTU6, MTU7 channel counter */
    MTU.TSTRB.BYTE |= (_40_MTU_CST6_ON | _80_MTU_CST7_ON);
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU6_MTU7_Stop
* Description  : This function stops the MTU6 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU6_MTU7_Stop(void)
{
    /* Stop MTU6, MTU7 channel counter */
    MTU.TSTRB.BIT.CST6 = 0U;
    MTU.TSTRB.BIT.CST7 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
