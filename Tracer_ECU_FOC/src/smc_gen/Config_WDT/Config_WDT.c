/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_WDT.c
* Component Version: 1.11.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_WDT.
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
#include "Config_WDT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_WDT_Create
* Description  : This function initializes the WDT module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_WDT_Create(void)
{
    /* Set control registers */
    WDT.WDTCR.WORD = _0003_WDT_TIMEOUT_16384 | _00F0_WDT_CLOCK_DIV128 | _0300_WDT_WINDOW_END_0 | 
                     _3000_WDT_WINDOW_START_100;
    WDT.WDTRCR.BYTE = _80_WDT_RESET_OUTPUT;
    
    R_Config_WDT_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_WDT_Restart
* Description  : This function restarts WDT module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_WDT_Restart(void)
{
    /* Refreshed by writing 00h and then writing FFh */
    WDT.WDTRR = 0x00U;
    WDT.WDTRR = 0xFFU;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
