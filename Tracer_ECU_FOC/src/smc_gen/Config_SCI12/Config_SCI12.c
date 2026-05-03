/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_SCI12.c
* Component Version: 1.12.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_SCI12.
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
#include "Config_SCI12.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t * gp_sci12_tx_address;               /* SCI12 transmit buffer address */
volatile uint16_t  g_sci12_tx_count;                  /* SCI12 transmit data number */
volatile uint8_t * gp_sci12_rx_address;               /* SCI12 receive buffer address */
volatile uint16_t  g_sci12_rx_count;                  /* SCI12 receive data number */
volatile uint16_t  g_sci12_rx_length;                 /* SCI12 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_SCI12_Create
* Description  : This function initializes SCI12
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_SCI12_Create(void)
{
    /* Cancel SCI12 module stop state */
    MSTP(SCI12) = 0U;

    /* Set interrupt priority */
    IPR(SCI12,TXI12) = _0F_SCI_PRIORITY_LEVEL15;
    IPR(SCI12,RXI12) = _0F_SCI_PRIORITY_LEVEL15;

    /* Clear the control register */
    SCI12.SCR.BYTE = 0x00U;

    /* Set clock enable */
    SCI12.SCR.BYTE |= _01_SCI_INTERNAL_SCK_OUTPUT;

    /* Clear the SIMR1.IICM */
    SCI12.SIMR1.BIT.IICM = 0U;

    /* Set control registers */
    SCI12.SPMR.BYTE = _00_SCI_SS_PIN_DISABLE | _00_SCI_SPI_MASTER | _00_SCI_CLOCK_NOT_INVERTED | 
                      _00_SCI_CLOCK_NOT_DELAYED;
    SCI12.SMR.BYTE = _80_SCI_CLOCK_SYNCHRONOUS_OR_SPI_MODE | _00_SCI_CLOCK_PCLK;
    SCI12.SCMR.BYTE = _00_SCI_SERIAL_MODE | _00_SCI_DATA_INVERT_NONE | _00_SCI_DATA_LSB_FIRST | 
                      _10_SCI_DATA_LENGTH_8_OR_7 | _62_SCI_SCMR_DEFAULT;
    SCI12.SEMR.BYTE = _00_SCI_BIT_MODULATION_DISABLE;

    /* Set bit rate */
    SCI12.BRR = 0x0CU;

    /* Set SMISO12 pin */
    MPC.P22PFS.BYTE = 0x0CU;
    PORT2.PMR.BYTE |= 0x04U;

    /* Set SMOSI12 pin */
    MPC.P23PFS.BYTE = 0x0CU;
    PORT2.PMR.BYTE |= 0x08U;

    /* Set SCK12 pin */
    MPC.P82PFS.BYTE = 0x0CU;
    PORT8.PMR.BYTE |= 0x04U;

    R_Config_SCI12_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_SCI12_Start
* Description  : This function starts SCI12
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_SCI12_Start(void)
{
    /* Enable TXI and TEI interrupt */
    IR(SCI12,TXI12) = 0U;
    IEN(SCI12,TXI12) = 1U;
    ICU.GENBL0.BIT.EN16 = 1U;

    /* Enable RXI interrupt */
    IR(SCI12,RXI12) = 0U;
    IEN(SCI12,RXI12) = 1U;

    /* Enable ERI interrupt */
    ICU.GENBL0.BIT.EN17 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SCI12_Stop
* Description  : This function stops SCI12
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_SCI12_Stop(void)
{
    /* Disable serial transmit and receive */
    SCI12.SCR.BYTE &= 0xCFU;

    /* Disable TXI and TEI interrupt */
    IEN(SCI12,TXI12) = 0U;
    ICU.GENBL0.BIT.EN16 = 0U;

    /* Disable RXI interrupt */
    IEN(SCI12,RXI12) = 0U;

    /* Disable ERI interrupt */
    ICU.GENBL0.BIT.EN17 = 0U;

    /* Clear interrupt flags */
    IR(SCI12,TXI12) = 0U;
    IR(SCI12,RXI12) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_SCI12_SPI_Master_Send_Receive
* Description  : This function sends and receives SCI12 data to and from slave device
* Arguments    : tx_buf -
*                    transfer buffer pointer (not used when data is handled by DMAC/DTC)
*                tx_num -
*                    transfer buffer size
*                rx_buf -
*                    receive buffer pointer (not used when data is handled by DMAC/DTC)
*                rx_num -
*                    receive buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/

MD_STATUS R_Config_SCI12_SPI_Master_Send_Receive(uint8_t * const tx_buf, uint16_t tx_num, uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (1U > tx_num)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_sci12_tx_count = tx_num;
        gp_sci12_tx_address = tx_buf;
        gp_sci12_rx_address = rx_buf;
        g_sci12_rx_count = 0U;
        g_sci12_rx_length = rx_num;

        /* Set TE, TIE, RE, RIE bits simultaneously */
        SCI12.SCR.BYTE |= 0xF0U;
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
