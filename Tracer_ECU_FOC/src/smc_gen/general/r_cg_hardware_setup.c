/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_hardware_setup.c
* Version          : 1.0.151
* Device(s)        : R5F572TFAxFP
* Description      : Initialization file for code generation configurations.
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
#include "Config_MTU3_MTU4.h"
#include "Config_MTU6_MTU7.h"
#include "Config_WDT.h"
#include "Config_PORT.h"
#include "Config_MTU1.h"
#include "Config_MTU2.h"
#include "Config_ICU.h"
#include "Config_S12AD0.h"
#include "Config_S12AD1.h"
#include "Config_S12AD2.h"
#include "Config_GPT0.h"
#include "Config_GPT1.h"
#include "Config_GPT2.h"
#include "Config_RSPI0.h"
#include "Config_MTU0.h"
#include "Config_MTU9.h"
#include "Config_SCI12.h"
#include "Config_GPT3.h"
#include "Config_CMT0.h"
#include "r_smc_cgc.h"
#include "r_smc_interrupt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_undefined_exception
* Description  : This function is undefined interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if BSP_CFG_BOOTLOADER_PROJECT == 0
/* Disable the following function in the bootloader project. */
void r_undefined_exception(void)
{
    /* Start user code for r_undefined_exception. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
#endif /* BSP_CFG_BOOTLOADER_PROJECT == 0 */

/***********************************************************************************************************************
* Function Name: R_Systeminit
* Description  : This function initializes every configuration
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Systeminit(void)
{
    /* Enable writing to registers related to operating modes, LPC, CGC and software reset */
    SYSTEM.PRCR.WORD = 0xA50BU;

    /* Enable writing to MPC pin function control registers */
    MPC.PWPR.BIT.B0WI = 0U;
    MPC.PWPR.BIT.PFSWE = 1U;

#if BSP_CFG_BOOTLOADER_PROJECT == 0
    /* Disable the following codes in the bootloader project. */
    /* Write 0 to the target bits in the POECR2 registers */
    POE.POECR2.WORD = 0x0000U;
#endif /* BSP_CFG_BOOTLOADER_PROJECT == 0 */

    /* Initialize clocks settings */
    R_CGC_Create();

    /* Set peripheral settings */
    R_Config_PORT_Create();
    R_Config_MTU3_MTU4_Create();
    R_Config_MTU6_MTU7_Create();
    R_Config_WDT_Create();
    R_Config_MTU1_Create();
    R_Config_MTU2_Create();
    R_Config_ICU_Create();
    R_Config_S12AD0_Create();
    R_Config_S12AD1_Create();
    R_Config_S12AD2_Create();
    R_Config_GPT0_Create();
    R_Config_GPT1_Create();
    R_Config_GPT2_Create();
    R_Config_RSPI0_Create();
    R_Config_MTU0_Create();
    R_Config_MTU9_Create();
    R_Config_SCI12_Create();
    R_Config_GPT3_Create();
    R_Config_CMT0_Create();

    /* Set interrupt settings */
    R_Interrupt_Create();

#if BSP_CFG_BOOTLOADER_PROJECT == 0
    /* Disable the following codes in the bootloader project. */
    /* Register undefined interrupt */
    R_BSP_InterruptWrite(BSP_INT_SRC_UNDEFINED_INTERRUPT,(bsp_int_cb_t)r_undefined_exception);
#endif /* BSP_CFG_BOOTLOADER_PROJECT == 0 */

    /* Register group AL0 interrupt SPII0 (RSPI0) */
    R_BSP_InterruptWrite(BSP_INT_SRC_AL0_RSPI0_SPII0,(bsp_int_cb_t)r_Config_RSPI0_idle_interrupt);

    /* Register group AL0 interrupt SPEI0 (RSPI0) */
    R_BSP_InterruptWrite(BSP_INT_SRC_AL0_RSPI0_SPEI0,(bsp_int_cb_t)r_Config_RSPI0_error_interrupt);

    /* Register group BL0 interrupt TEI12 (SCI12) */
    R_BSP_InterruptWrite(BSP_INT_SRC_BL0_SCI12_TEI12,(bsp_int_cb_t)r_Config_SCI12_transmitend_interrupt);

    /* Register group BL0 interrupt ERI12 (SCI12) */
    R_BSP_InterruptWrite(BSP_INT_SRC_BL0_SCI12_ERI12,(bsp_int_cb_t)r_Config_SCI12_receiveerror_interrupt);

    /* Disable writing to MPC pin function control registers */
    MPC.PWPR.BIT.PFSWE = 0U;
    MPC.PWPR.BIT.B0WI = 1U;

    /* Enable protection */
    SYSTEM.PRCR.WORD = 0xA500U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
