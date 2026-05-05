/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_ICU_user.c
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
* Function Name: R_Config_ICU_Create_UserInit
* Description  : This function adds user code after initializing the ICU module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ICU_irq0_interrupt
* Description  : This function is IRQ0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ0
#pragma interrupt r_Config_ICU_irq0_interrupt(vect=VECT(ICU,IRQ0),fint)
#else
#pragma interrupt r_Config_ICU_irq0_interrupt(vect=VECT(ICU,IRQ0))
#endif
static void r_Config_ICU_irq0_interrupt(void)
{
    /* Start user code for r_Config_ICU_irq0_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ICU_irq4_interrupt
* Description  : This function is IRQ4 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ4
#pragma interrupt r_Config_ICU_irq4_interrupt(vect=VECT(ICU,IRQ4),fint)
#else
#pragma interrupt r_Config_ICU_irq4_interrupt(vect=VECT(ICU,IRQ4))
#endif
static void r_Config_ICU_irq4_interrupt(void)
{
    /* Start user code for r_Config_ICU_irq4_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ICU_irq5_interrupt
* Description  : This function is IRQ5 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ5
#pragma interrupt r_Config_ICU_irq5_interrupt(vect=VECT(ICU,IRQ5),fint)
#else
#pragma interrupt r_Config_ICU_irq5_interrupt(vect=VECT(ICU,IRQ5))
#endif
static void r_Config_ICU_irq5_interrupt(void)
{
    /* Start user code for r_Config_ICU_irq5_interrupt. Do not edit comment generated here */
	
	MTU.TSTRA.BIT.CST1	= 0U;		// MTU ch1 counter stop
	MTU1.TCNT 			= 0U;		// MTU ch1 counter init 	
    MTU.TSTRA.BIT.CST1	= 1U;		// MTU ch1 counter start
    
	/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ICU_irq15_interrupt
* Description  : This function is IRQ15 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ15
#pragma interrupt r_Config_ICU_irq15_interrupt(vect=VECT(ICU,IRQ15),fint)
#else
#pragma interrupt r_Config_ICU_irq15_interrupt(vect=VECT(ICU,IRQ15))
#endif
static void r_Config_ICU_irq15_interrupt(void)
{
    /* Start user code for r_Config_ICU_irq15_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

