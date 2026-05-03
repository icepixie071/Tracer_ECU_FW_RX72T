/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_GPT0.c
* Component Version: 1.5.2
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_GPT0.
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
#include "Config_GPT0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_GPT0_Create
* Description  : This function initializes the GPT0 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT0_Create(void)
{
    /* Cancel GPTW0 module stop state */
    MSTP(GPTW0) = 0U;

    /* Disable GPTW0 control registers write protect */
    GPTW0.GTWP.LONG = 0x0000A500UL;

    /* Set GPTW0 mode */
    GPTW0.GTCR.LONG = _00050000_GPTn_MODE_TRIANGLE_WAVE_PWM_2;

    /* Set GPTW0 count direction and duty */
    GPTW0.GTUDDTYC.LONG = _00000000_GPTn_COUNT_DOWN | _00000002_GPTn_COUNT_DIR_FORCE | 
                          _00000000_GPTn_GTIOCnA_DUTYCYCLE_COMPARE | _00000000_GPTn_GTIOCnB_DUTYCYCLE_COMPARE;

    /* Clear GPTW0 count direction forcible set */
    GPTW0.GTUDDTYC.BIT.UDF = 0U;

    /* Set GPTW0 count clock and input capture at count stop */
    GPTW0.GTCR.LONG |= (_00000100_GPTn_NO_INPUTCAP_COUNT_STOP | _00000000_GPTn_COUNT_CLK_PCLKC);

    /* Set GPTW0 cycle */
    GPTW0.GTPR = _00002710_GPT0_CYCLE_VALUE;

    /* Set GPTW0 counter initial value */
    GPTW0.GTCNT = _00000000_GPT0_INIT_COUNT;

    /* Set GPTW0 count-up sources */
    GPTW0.GTUPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW0 count-down sources */
    GPTW0.GTDNSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW0 start sources */
    GPTW0.GTSSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _00000000_GPTn_SOFTWARE_SOURCE_DISABLE;

    /* Set GPTW0 stop sources */
    GPTW0.GTPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _00000000_GPTn_SOFTWARE_SOURCE_DISABLE;

    /* Set GPTW0 clear sources */
    GPTW0.GTCSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _00000000_GPTn_SOFTWARE_SOURCE_DISABLE;

    /* Set GPTW0 output stop detection */
    GPTW0.GTINTAD.LONG = _00000000_GPTn_OUTPUT_STOP_GROUPA | _00000000_GPTn_DEADTIME_OUTPUT_STOP_DISABLE | 
                         _00000000_GPTn_SIMHIGH_OUTPUT_STOP_DISABLE | _00000000_GPTn_SIMLOW_OUTPUT_STOP_DISABLE;

    /* Set GTIOC0A,GTIOC0B pin function */
    GPTW0.GTIOR.LONG = _00000000_GPTn_GTIOCA_COMP_MATCH_RETAIN | _00000000_GPTn_GTIOCA_CYCLE_END_RETAIN | 
                       _00000000_GPTn_GTIOCA_INIT_OUT_LOW | _00000000_GPTn_GTIOCA_OUTPUT_ON_STOP_0 | 
                       _00000000_GPTn_GTIOCA_OUTPUT_ON_START_SET | _00000000_GPTn_GTIOCnA_NEG_DISABEL | 
                       _00000000_GPTn_GTIOCB_COMP_MATCH_RETAIN | _00000000_GPTn_GTIOCB_CYCLE_END_RETAIN | 
                       _00000000_GPTn_GTIOCB_INIT_OUT_LOW | _00000000_GPTn_GTIOCB_OUTPUT_ON_STOP_0 | 
                       _00000000_GPTn_GTIOCB_OUTPUT_ON_START_SET | _00000000_GPTn_GTIOCnB_NEG_DISABEL;

    /* Enable GTIOC0A,GTIOC0B pin output */
    GPTW0.GTIOR.LONG |= (_00000100_GPTn_GTIOCnA_OUTPUT_ENABLE | _01000000_GPTn_GTIOCnB_OUTPUT_ENABLE);

    /* Set GPTW0 buffer operations */
    GPTW0.GTBER.LONG = _00000001_GPTn_GTCCR_BUF_OP_DISABLE | _00000002_GPTn_GTPR_BUF_OP_DISABLE | 
                       _00000004_GPTn_GTADTR_BUF_OP_DISABLE | _00000008_GPTn_GTDV_BUF_OP_DISABLE | 
                       _00000000_GPTn_GTCCRA_BUF_NONE | _00000000_GPTn_GTCCRB_BUF_NONE | _00000000_GPTn_GTPR_BUF_NONE;

    /* Set GPTW0 compare match value */
    GPTW0.GTCCRA = _00000064_GPT0_COMP_MATCH_A_VALUE;
    GPTW0.GTCCRC = _00000064_GPT0_COMP_MATCH_C_VALUE;
    GPTW0.GTCCRD = _00000064_GPT0_COMP_MATCH_D_VALUE;
    GPTW0.GTCCRE = _00000064_GPT0_COMP_MATCH_E_VALUE;
    GPTW0.GTCCRF = _00000064_GPT0_COMP_MATCH_F_VALUE;

    /* Set GPTW0 dead time setting */
    GPTW0.GTDTCR.LONG = _00000001_GPTn_DEAD_TIME_ENABLE | _00000000_GPTn_GTDVU_BUF_DISABLE | 
                        _00000100_GPTn_GTDVD_VALUE_AUTO;

    /* Set GPTW0 dead time value */
    GPTW0.GTDVU = _00000000_GPT0_DEADTIME_UP_VALUE;

    /* Set GPTW0 interrupt and A/D conversion request generation */
    GPTW0.GTINTAD.LONG |= (_00000000_GPTn_ADTRB_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRB_UPCOUNTING_DISABLE | 
                          _00000000_GPTn_ADTRA_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRA_UPCOUNTING_DISABLE | 
                          _00000000_GPTn_GTCIV_INTERRUPT_DISABLE | _00000000_GPTn_GTCIU_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCIF_INTERRUPT_DISABLE | _00000000_GPTn_GTCIE_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCID_INTERRUPT_DISABLE | _00000000_GPTn_GTCIC_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCIB_INTERRUPT_DISABLE | _00000000_GPTn_GTCIA_INTERRUPT_DISABLE);

    /* Set GPTW0 A/D converter start request signal monitoring */
    GPTW0.GTADSMR.LONG = _00000000_GPTn_AD_START_MONITOR0_DISABLE | _00000000_GPTn_AD_START_MONITOR1_DISABLE;

    /* Set GPTW0 interrupt and A/D conversion request skipping */
    GPTW0.GTITC.LONG = _00000000_GPTn_GTCI_SKIP_DISABLE | _00000000_GPTn_GTCI_SKIPPING_COUNT_0;

    /* Set GPTW0 extended interrupt skipping counter control */
    GPTW0.GTEITC.LONG = _00000000_GPTn_EXT1_SKIP_DISABLE | _00000000_GPTn_EXT2_SKIP_DISABLE;

    /* Disable rising and falling edge adjustment circuit */
    HRPWM.HROCR2.BIT.HRDIS0 = 1U;

    /* Set high resolution PWM waveform generation circuit */
    HRPWM.HROCR2.BIT.HRSEL0 = 0U;

    /* Set GTIOC0A pin */
    MPC.PD2PFS.BYTE = 0x15U;
    PORTD.PMR.BYTE |= 0x04U;

    /* Set GTIOC0B pin */
    MPC.PD1PFS.BYTE = 0x15U;
    PORTD.PMR.BYTE |= 0x02U;

    R_Config_GPT0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT0_Start
* Description  : This function starts the GPT0 channel counter. Note that this function is empty
*                if Count start sources setting is not enabled and no interrupt is configured for GPT0
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT0_Start(void)
{
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT0_Stop
* Description  : This function stops the GPT0 channel counter. Note that this function is empty
*                if Count stop sources setting is not enabled and no interrupt is configured for GPT0
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT0_Stop(void)
{
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
