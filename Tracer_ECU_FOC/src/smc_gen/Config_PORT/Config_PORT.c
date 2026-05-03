/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_PORT.c
* Component Version: 2.4.1
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_PORT.
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
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_PORT_Create(void)
{
    /* Set PORT2 registers */
    PORT2.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORT2.ODR1.BYTE = _00_Pm7_CMOS_OUTPUT;
    PORT2.PCR.BYTE = _00_Pm4_PULLUP_OFF;
    PORT2.DSCR.BYTE = _00_Pm0_HIDRV_OFF | _00_Pm1_HIDRV_OFF | _00_Pm2_HIDRV_OFF | _00_Pm3_HIDRV_OFF | _00_Pm7_HIDRV_OFF;
    PORT2.PMR.BYTE = _00_Pm4_PIN_GPIO;
    PORT2.PDR.BYTE = _00_Pm4_MODE_INPUT | _60_PDR2_DEFAULT;

    /* Set PORT3 registers */
    PORT3.ODR0.BYTE = _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORT3.ODR1.BYTE = _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORT3.PCR.BYTE = _00_Pm0_PULLUP_OFF;
    PORT3.DSCR.BYTE = _00_Pm1_HIDRV_OFF | _00_Pm2_HIDRV_OFF | _00_Pm3_HIDRV_OFF;
    PORT3.PMR.BYTE = _00_Pm0_PIN_GPIO;
    PORT3.PDR.BYTE = _00_Pm0_MODE_INPUT | _30_PDR3_DEFAULT;

    /* Set PORT9 registers */
    PORT9.PODR.BYTE = _00_Pm6_OUTPUT_0;
    PORT9.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORT9.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT | _00_Pm5_CMOS_OUTPUT | _00_Pm6_CMOS_OUTPUT;
    PORT9.DSCR.BYTE = _00_Pm0_HIDRV_OFF | _00_Pm1_HIDRV_OFF | _00_Pm2_HIDRV_OFF | _00_Pm3_HIDRV_OFF | 
                      _00_Pm4_HIDRV_OFF | _00_Pm5_HIDRV_OFF | _00_Pm6_HIDRV_OFF;
    PORT9.DSCR2.BYTE = _00_Pm0_LARGECUR_OFF | _00_Pm1_LARGECUR_OFF | _00_Pm2_LARGECUR_OFF | _00_Pm3_LARGECUR_OFF | 
                       _00_Pm4_LARGECUR_OFF | _00_Pm5_LARGECUR_OFF;
    PORT9.PMR.BYTE = _00_Pm6_PIN_GPIO;
    PORT9.PDR.BYTE = _40_Pm6_MODE_OUTPUT;

    /* Set PORTB registers */
    PORTB.PODR.BYTE = _00_Pm2_OUTPUT_0 | _00_Pm4_OUTPUT_0;
    PORTB.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORTB.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT | _00_Pm5_CMOS_OUTPUT | _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORTB.DSCR.BYTE = _00_Pm0_HIDRV_OFF | _00_Pm1_HIDRV_OFF | _00_Pm2_HIDRV_OFF | _00_Pm3_HIDRV_OFF | 
                      _00_Pm4_HIDRV_OFF | _00_Pm5_HIDRV_OFF | _00_Pm6_HIDRV_OFF | _00_Pm7_HIDRV_OFF;
    PORTB.DSCR2.BYTE = _00_Pm5_LARGECUR_OFF;
    PORTB.PMR.BYTE = _00_Pm2_PIN_GPIO | _00_Pm4_PIN_GPIO;
    PORTB.PDR.BYTE = _04_Pm2_MODE_OUTPUT | _10_Pm4_MODE_OUTPUT;

    R_Config_PORT_Create_UserInit();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
