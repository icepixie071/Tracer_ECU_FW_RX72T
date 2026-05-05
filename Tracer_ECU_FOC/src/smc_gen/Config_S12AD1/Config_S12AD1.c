/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_S12AD1.c
* Component Version: 1.13.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_S12AD1.
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
#include "Config_S12AD1.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_S12AD1_Create
* Description  : This function initializes the S12AD1 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD1_Create(void)
{
    uint16_t w_count;

    /* Cancel S12AD1 module stop state */
    MSTP(S12AD1) = 0U;

    /* Disable and clear interrupt flags of S12AD1 module */
    S12AD1.ADCSR.BIT.ADIE = 0U;
    S12AD1.ADCMPCR.BIT.CMPAIE = 0U;
    S12AD1.ADCMPCR.BIT.CMPBIE = 0U;

    /* Set S12AD1 control registers */
    S12AD1.ADCSR.WORD = _0000_AD_SYNCASYNCTRG_DISABLE | _4000_AD_CONTINUOUS_SCAN_MODE;
    S12AD1.ADDISCR.BYTE = _00_AD_DISCONECT_UNUSED;

    /* Set channels and sampling time */
    S12AD1.ADSSTR0 = _1B_AD1_SAMPLING_STATE_0;
    S12AD1.ADSSTR1 = _1B_AD1_SAMPLING_STATE_1;
    S12AD1.ADANSA0.WORD = _0001_AD_ANx00_USED | _0002_AD_ANx01_USED;
    S12AD1.ADADS0.WORD = _0001_AD_ANx00_ADD_USED | _0002_AD_ANx01_ADD_USED;
    S12AD1.ADSHCR.WORD = _0100_AD_DSH_ANx00_SELECT | _0200_AD_DSH_ANx01_SELECT;

    /* Set AN100 amplifier */
    S12AD1.ADPGADCR0.BIT.P100DEN = 0U;
    S12AD1.ADPGAGS0.BIT.P100GAIN = _0000_AD_GAIN_2_000;
    S12AD1.ADPGACR.BIT.P100CR = _000E_AD_PATH_Px_ANx_Px;

    /* Set AN101 amplifier */
    S12AD1.ADPGADCR0.BIT.P101DEN = 0U;
    S12AD1.ADPGAGS0.BIT.P101GAIN = _0000_AD_GAIN_2_000;
    S12AD1.ADPGACR.BIT.P101CR = _000E_AD_PATH_Px_ANx_Px;

    /* Wait for stabilization of the PGA(s) */
    /* WAIT_LOOP */
    for (w_count = 0U; w_count < _00C9_AD_PGA_STABLE_WAIT_COUNT; w_count++)
    {
        nop();
    }

    S12AD1.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_SELFTDIAGST_DISABLE | _0000_AD_RIGHT_ALIGNMENT;
    S12AD1.ADELCCR.BYTE = _02_ALL_SCAN_COMPLETION;
    S12AD1.ADCSR.WORD |= _0000_AD_SCAN_END_INTERRUPT_DISABLE;
    S12AD1.ADADC.BYTE = _01_AD_2_TIME_CONVERSION | _80_AD_AVERAGE_MODE;

    /* Set compare control register */
    S12AD1.ADCMPCR.WORD = _0000_AD_WINDOWB_DISABLE | _0000_AD_WINDOWA_DISABLE | _0000_AD_WINDOWFUNCTION_DISABLE;

    /* Set PGAVSS1 pin */
    PORTH.PMR.BYTE &= 0xEFU;
    PORTH.PDR.BYTE &= 0xEFU;
    MPC.PH4PFS.BYTE = 0x80U;

    /* Set AN100 pin */
    PORT4.PMR.BYTE &= 0xEFU;
    PORT4.PDR.BYTE &= 0xEFU;
    MPC.P44PFS.BYTE = 0x80U;

    /* Set AN101 pin */
    PORT4.PMR.BYTE &= 0xDFU;
    PORT4.PDR.BYTE &= 0xDFU;
    MPC.P45PFS.BYTE = 0x80U;

    R_Config_S12AD1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD1_Start
* Description  : This function starts the AD1 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD1_Start(void)
{
    uint16_t w_count;

    S12AD1.ADSHMSR.BIT.SHMD = 1U;

    /* Wait for stabilization time, 750ns */
    /* WAIT_LOOP */
    for (w_count = 0U; w_count < _001F_CSH_STABLE_WAIT_COUNT; w_count++)
    {
        nop();
    }
    S12AD1.ADCSR.BIT.ADST = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD1_Stop
* Description  : This function stops the AD1 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD1_Stop(void)
{
    S12AD1.ADCSR.BIT.ADST = 0U;
    S12AD1.ADSHMSR.BIT.SHMD = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD1_Get_ValueResult
* Description  : This function gets result from the AD1 converter
* Arguments    : channel -
*                    channel of data register to be read
*                buffer -
*                    buffer pointer
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD1_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            *buffer = (uint16_t)(S12AD1.ADRD.WORD);
            break;
        }
        case ADCHANNEL0:
        {
            *buffer = (uint16_t)(S12AD1.ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            *buffer = (uint16_t)(S12AD1.ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            *buffer = (uint16_t)(S12AD1.ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            *buffer = (uint16_t)(S12AD1.ADDR3);
            break;
        }
        case ADCHANNEL4:
        {
            *buffer = (uint16_t)(S12AD1.ADDR4);
            break;
        }
        case ADCHANNEL5:
        {
            *buffer = (uint16_t)(S12AD1.ADDR5);
            break;
        }
        case ADCHANNEL6:
        {
            *buffer = (uint16_t)(S12AD1.ADDR6);
            break;
        }
        case ADCHANNEL7:
        {
            *buffer = (uint16_t)(S12AD1.ADDR7);
            break;
        }
        default:
        {
            break;
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
