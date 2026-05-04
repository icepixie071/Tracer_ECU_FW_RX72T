/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_ICU.c
* Component Version: 2.3.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_ICU.
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
#include "Config_ICU.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ICU_Create
* Description  : This function initializes the ICU module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_Create(void)
{
    /* Disable IRQ interrupts */
    ICU.IER[0x08].BYTE = 0x00U;
    ICU.IER[0x09].BYTE = 0x00U;

    /* Disable software interrupt */
    IEN(ICU,SWINT) = 0U;
    IEN(ICU,SWINT2) = 0U;

    /* Disable IRQ digital filter */
    ICU.IRQFLTE0.BYTE &= ~(_01_ICU_IRQ0_FILTER_ENABLE | _10_ICU_IRQ4_FILTER_ENABLE | _20_ICU_IRQ5_FILTER_ENABLE);
    ICU.IRQFLTE1.BYTE &= ~(_80_ICU_IRQ15_FILTER_ENABLE);

    /* Set IRQ digital filter sampling clock */
    ICU.IRQFLTC0.BIT.FCLKSEL0 = _0003_ICU_IRQ_FILTER_PCLK_64;
    ICU.IRQFLTC0.BIT.FCLKSEL4 = _0003_ICU_IRQ_FILTER_PCLK_64;
    ICU.IRQFLTC0.BIT.FCLKSEL5 = _0003_ICU_IRQ_FILTER_PCLK_64;
    ICU.IRQFLTC1.BIT.FCLKSEL15 = _0003_ICU_IRQ_FILTER_PCLK_64;

    /* Set IRQ0 pin */
    MPC.P10PFS.BYTE = 0x40U;
    PORT1.PDR.BYTE &= 0xFEU;
    PORT1.PMR.BYTE &= 0xFEU;

    /* Set IRQ4 pin */
    MPC.P01PFS.BYTE = 0x40U;
    PORT0.PDR.BYTE &= 0xFDU;
    PORT0.PMR.BYTE &= 0xFDU;

    /* Set IRQ5 pin */
    MPC.P70PFS.BYTE = 0x40U;
    PORT7.PDR.BYTE &= 0xFEU;
    PORT7.PMR.BYTE &= 0xFEU;

    /* Set IRQ15 pin */
    MPC.P27PFS.BYTE = 0x40U;
    PORT2.PDR.BYTE &= 0x7FU;
    PORT2.PMR.BYTE &= 0x7FU;

    /* Set IRQ detection type */
    ICU.IRQCR[0].BYTE = _08_ICU_IRQ_EDGE_RISING;
    IR(ICU,IRQ0) = 0U;
    ICU.IRQCR[4].BYTE = _08_ICU_IRQ_EDGE_RISING;
    IR(ICU,IRQ4) = 0U;
    ICU.IRQCR[5].BYTE = _08_ICU_IRQ_EDGE_RISING;
    IR(ICU,IRQ5) = 0U;
    ICU.IRQCR[15].BYTE = _04_ICU_IRQ_EDGE_FALLING;
    IR(ICU,IRQ15) = 0U;

    /* Enable IRQ digital filter */
    ICU.IRQFLTE0.BYTE |= (_01_ICU_IRQ0_FILTER_ENABLE | _10_ICU_IRQ4_FILTER_ENABLE | _20_ICU_IRQ5_FILTER_ENABLE);
    ICU.IRQFLTE1.BYTE |= (_80_ICU_IRQ15_FILTER_ENABLE);

    /* Set IRQ priority level */
    IPR(ICU,IRQ0) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ4) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ5) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ15) = _0F_ICU_PRIORITY_LEVEL15;

    R_Config_ICU_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ0_Start
* Description  : This function enables IRQ0 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ0_Start(void)
{
    /* Enable IRQ0 interrupt */
    IEN(ICU,IRQ0) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ0_Stop
* Description  : This function disables IRQ0 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ0_Stop(void)
{
    /* Disable IRQ0 interrupt */
    IEN(ICU,IRQ0) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ4_Start
* Description  : This function enables IRQ4 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ4_Start(void)
{
    /* Enable IRQ4 interrupt */
    IEN(ICU,IRQ4) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ4_Stop
* Description  : This function disables IRQ4 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ4_Stop(void)
{
    /* Disable IRQ4 interrupt */
    IEN(ICU,IRQ4) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ5_Start
* Description  : This function enables IRQ5 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ5_Start(void)
{
    /* Enable IRQ5 interrupt */
    IEN(ICU,IRQ5) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ5_Stop
* Description  : This function disables IRQ5 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ5_Stop(void)
{
    /* Disable IRQ5 interrupt */
    IEN(ICU,IRQ5) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ15_Start
* Description  : This function enables IRQ15 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ15_Start(void)
{
    /* Enable IRQ15 interrupt */
    IEN(ICU,IRQ15) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ15_Stop
* Description  : This function disables IRQ15 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ15_Stop(void)
{
    /* Disable IRQ15 interrupt */
    IEN(ICU,IRQ15) = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
