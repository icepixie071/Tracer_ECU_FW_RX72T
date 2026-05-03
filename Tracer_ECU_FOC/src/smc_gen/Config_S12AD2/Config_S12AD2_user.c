/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_S12AD2_user.c
* Component Version: 1.13.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_S12AD2.
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
#include "Config_S12AD2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Create_UserInit
* Description  : This function adds user code after initializing the S12AD2 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_S12AD2_interrupt
* Description  : This function is S12ADI2 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_S12AD2_S12ADI2
#pragma interrupt r_Config_S12AD2_interrupt(vect=VECT(S12AD2,S12ADI2),fint)
#else
#pragma interrupt r_Config_S12AD2_interrupt(vect=VECT(S12AD2,S12ADI2))
#endif
static void r_Config_S12AD2_interrupt(void)
{
    /* Start user code for r_Config_S12AD2_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
