/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Pin.c
* Version          : 1.0.2
* Device(s)        : R5F572TFAxFP
* Description      : This file implements SMC pin code generation.
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
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Pins_Create
* Description  : This function initializes Smart Configurator pins
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Pins_Create(void)
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set AN000 pin */
    PORT4.PMR.BYTE &= 0xFEU;
    PORT4.PDR.BYTE &= 0xFEU;
    MPC.P40PFS.BYTE = 0x80U;

    /* Set AN001 pin */
    PORT4.PMR.BYTE &= 0xFDU;
    PORT4.PDR.BYTE &= 0xFDU;
    MPC.P41PFS.BYTE = 0x80U;

    /* Set AN100 pin */
    PORT4.PMR.BYTE &= 0xEFU;
    PORT4.PDR.BYTE &= 0xEFU;
    MPC.P44PFS.BYTE = 0x80U;

    /* Set AN101 pin */
    PORT4.PMR.BYTE &= 0xDFU;
    PORT4.PDR.BYTE &= 0xDFU;
    MPC.P45PFS.BYTE = 0x80U;

    /* Set AN200 pin */
    PORT5.PMR.BYTE &= 0xFBU;
    PORT5.PDR.BYTE &= 0xFBU;
    MPC.P52PFS.BYTE = 0x80U;

    /* Set AN201 pin */
    PORT5.PMR.BYTE &= 0xF7U;
    PORT5.PDR.BYTE &= 0xF7U;
    MPC.P53PFS.BYTE = 0x80U;

    /* Set AN202 pin */
    PORT5.PMR.BYTE &= 0xEFU;
    PORT5.PDR.BYTE &= 0xEFU;
    MPC.P54PFS.BYTE = 0x80U;

    /* Set AN203 pin */
    PORT5.PMR.BYTE &= 0xDFU;
    PORT5.PDR.BYTE &= 0xDFU;
    MPC.P55PFS.BYTE = 0x80U;

    /* Set AN206 pin */
    PORT6.PMR.BYTE &= 0xFEU;
    PORT6.PDR.BYTE &= 0xFEU;
    MPC.P60PFS.BYTE = 0x80U;

    /* Set AN207 pin */
    PORT6.PMR.BYTE &= 0xFDU;
    PORT6.PDR.BYTE &= 0xFDU;
    MPC.P61PFS.BYTE = 0x80U;

    /* Set AN208 pin */
    PORT6.PMR.BYTE &= 0xFBU;
    PORT6.PDR.BYTE &= 0xFBU;
    MPC.P62PFS.BYTE = 0x80U;

    /* Set AN209 pin */
    PORT6.PMR.BYTE &= 0xF7U;
    PORT6.PDR.BYTE &= 0xF7U;
    MPC.P63PFS.BYTE = 0x80U;

    /* Set AN210 pin */
    PORT6.PMR.BYTE &= 0xEFU;
    PORT6.PDR.BYTE &= 0xEFU;
    MPC.P64PFS.BYTE = 0x80U;

    /* Set AN211 pin */
    PORT6.PMR.BYTE &= 0xDFU;
    PORT6.PDR.BYTE &= 0xDFU;
    MPC.P65PFS.BYTE = 0x80U;

    /* Set AN216 pin */
    PORT2.PMR.BYTE &= 0xFEU;
    PORT2.PDR.BYTE &= 0xFEU;
    MPC.P20PFS.BYTE = 0x80U;

    /* Set AN217 pin */
    PORT2.PMR.BYTE &= 0xFDU;
    PORT2.PDR.BYTE &= 0xFDU;
    MPC.P21PFS.BYTE = 0x80U;

    /* Set GTIOC0A pin */
    MPC.PD2PFS.BYTE = 0x15U;
    PORTD.PMR.BYTE |= 0x04U;

    /* Set GTIOC0B pin */
    MPC.PD1PFS.BYTE = 0x15U;
    PORTD.PMR.BYTE |= 0x02U;

    /* Set GTIOC1A pin */
    MPC.PD0PFS.BYTE = 0x15U;
    PORTD.PMR.BYTE |= 0x01U;

    /* Set GTIOC1B pin */
    MPC.PB7PFS.BYTE = 0x14U;
    PORTB.PMR.BYTE |= 0x80U;

    /* Set GTIOC2A pin */
    MPC.PB6PFS.BYTE = 0x14U;
    PORTB.PMR.BYTE |= 0x40U;

    /* Set GTIOC2B pin */
    MPC.PB5PFS.BYTE = 0x14U;
    PORTB.PMR.BYTE |= 0x20U;

    /* Set GTIOC3A pin */
    MPC.PE5PFS.BYTE = 0x14U;
    PORTE.PMR.BYTE |= 0x20U;

    /* Set GTIOC3B pin */
    MPC.P11PFS.BYTE = 0x14U;
    PORT1.PMR.BYTE |= 0x02U;

    /* Set IRQ0 pin */
    MPC.P10PFS.BYTE = 0x40U;
    PORT1.PMR.BYTE &= 0xFEU;
    PORT1.PDR.BYTE &= 0xFEU;

    /* Set IRQ4 pin */
    MPC.P01PFS.BYTE = 0x40U;
    PORT0.PMR.BYTE &= 0xFDU;
    PORT0.PDR.BYTE &= 0xFDU;

    /* Set IRQ5 pin */
    MPC.P70PFS.BYTE = 0x40U;
    PORT7.PMR.BYTE &= 0xFEU;
    PORT7.PDR.BYTE &= 0xFEU;

    /* Set IRQ15 pin */
    MPC.P27PFS.BYTE = 0x40U;
    PORT2.PMR.BYTE &= 0x7FU;
    PORT2.PDR.BYTE &= 0x7FU;

    /* Set MISOA pin */
    MPC.PA5PFS.BYTE = 0x0DU;
    PORTA.PMR.BYTE |= 0x20U;

    /* Set MOSIA pin */
    MPC.PB0PFS.BYTE = 0x0DU;
    PORTB.PMR.BYTE |= 0x01U;

    /* Set MTCLKA pin */
    MPC.P33PFS.BYTE = 0x02U;
    PORT3.PMR.BYTE |= 0x08U;

    /* Set MTCLKB pin */
    MPC.P32PFS.BYTE = 0x02U;
    PORT3.PMR.BYTE |= 0x04U;

    /* Set MTCLKC pin */
    MPC.PE4PFS.BYTE = 0x02U;
    PORTE.PMR.BYTE |= 0x10U;

    /* Set MTCLKD pin */
    MPC.PE3PFS.BYTE = 0x02U;
    PORTE.PMR.BYTE |= 0x08U;

    /* Set MTIOC0A pin */
    MPC.P31PFS.BYTE = 0x01U;
    PORT3.PMR.BYTE |= 0x02U;

    /* Set MTIOC0C pin */
    MPC.PB1PFS.BYTE = 0x01U;
    PORTB.PMR.BYTE |= 0x02U;

    /* Set MTIOC3B pin */
    MPC.P71PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x02U;

    /* Set MTIOC3D pin */
    MPC.P74PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x10U;

    /* Set MTIOC4A pin */
    MPC.P72PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x04U;

    /* Set MTIOC4B pin */
    MPC.P73PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x08U;

    /* Set MTIOC4C pin */
    MPC.P75PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x20U;

    /* Set MTIOC4D pin */
    MPC.P76PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x40U;

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

    /* Set MTIOC9A pin */
    MPC.P00PFS.BYTE = 0x01U;
    PORT0.PMR.BYTE |= 0x01U;

    /* Set PGAVSS0 pin */
    PORTH.PMR.BYTE &= 0xFEU;
    PORTH.PDR.BYTE &= 0xFEU;
    MPC.PH0PFS.BYTE = 0x80U;

    /* Set PGAVSS1 pin */
    PORTH.PMR.BYTE &= 0xEFU;
    PORTH.PDR.BYTE &= 0xEFU;
    MPC.PH4PFS.BYTE = 0x80U;

    /* Set RSPCKA pin */
    MPC.PB3PFS.BYTE = 0x0DU;
    PORTB.PMR.BYTE |= 0x08U;

    /* Set RXD6 pin */
    MPC.P80PFS.BYTE = 0x0AU;
    PORT8.PMR.BYTE |= 0x01U;

    /* Set SCK12 pin */
    MPC.P82PFS.BYTE = 0x0CU;
    PORT8.PMR.BYTE |= 0x04U;

    /* Set SMISO12 pin */
    MPC.P22PFS.BYTE = 0x0CU;
    PORT2.PMR.BYTE |= 0x04U;

    /* Set SMOSI12 pin */
    MPC.P23PFS.BYTE = 0x0CU;
    PORT2.PMR.BYTE |= 0x08U;

    /* Set SSLA0 pin */
    MPC.PA3PFS.BYTE = 0x0DU;
    PORTA.PMR.BYTE |= 0x08U;

    /* Set SSLA1 pin */
    MPC.PA2PFS.BYTE = 0x0DU;
    PORTA.PMR.BYTE |= 0x04U;

    /* Set SSLA2 pin */
    MPC.PE0PFS.BYTE = 0x0DU;
    PORTE.PMR.BYTE |= 0x01U;

    /* Set SSLA3 pin */
    MPC.PE1PFS.BYTE = 0x0DU;
    PORTE.PMR.BYTE |= 0x02U;

    /* Set TXD6 pin */
    PORT8.PODR.BYTE |= 0x02U;
    MPC.P81PFS.BYTE = 0x0AU;
    PORT8.PDR.BYTE |= 0x02U;
    // PORT8.PMR.BIT.B1 = 1U; // Please set the PMR bit after TE bit is set to 1.

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

