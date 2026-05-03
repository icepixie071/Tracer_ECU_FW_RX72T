/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_SCI12_user.c
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
extern volatile uint8_t * gp_sci12_tx_address;               /* SCI12 transmit buffer address */
extern volatile uint16_t  g_sci12_tx_count;                  /* SCI12 transmit data number */
extern volatile uint8_t * gp_sci12_rx_address;               /* SCI12 receive buffer address */
extern volatile uint16_t  g_sci12_rx_count;                  /* SCI12 receive data number */
extern volatile uint16_t  g_sci12_rx_length;                 /* SCI12 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_SCI12_Create_UserInit
* Description  : This function adds user code after initializing the SCI12 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_SCI12_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI12_transmit_interrupt
* Description  : This function is TXI12 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_SCI12_TXI12
#pragma interrupt r_Config_SCI12_transmit_interrupt(vect=VECT(SCI12,TXI12),fint)
#else
#pragma interrupt r_Config_SCI12_transmit_interrupt(vect=VECT(SCI12,TXI12))
#endif
static void r_Config_SCI12_transmit_interrupt(void)
{
    if (0U < g_sci12_tx_count)
    {
        SCI12.TDR = *gp_sci12_tx_address;
        gp_sci12_tx_address++;
        g_sci12_tx_count--;
    }
    else
    {
        SCI12.SCR.BIT.TIE = 0U;
        SCI12.SCR.BIT.TEIE = 1U;
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI12_transmitend_interrupt
* Description  : This function is TEI12 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_SCI12_transmitend_interrupt(void)
{
    SCI12.SCR.BIT.TIE = 0U;
    SCI12.SCR.BIT.TEIE = 0U;

    /* Clear TE and RE bits */
    if(0U == SCI12.SCR.BIT.RIE)
    {
        SCI12.SCR.BYTE &= 0xCFU;
    }

    r_Config_SCI12_callback_transmitend();
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI12_receive_interrupt
* Description  : This function is RXI12 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_SCI12_RXI12
#pragma interrupt r_Config_SCI12_receive_interrupt(vect=VECT(SCI12,RXI12),fint)
#else
#pragma interrupt r_Config_SCI12_receive_interrupt(vect=VECT(SCI12,RXI12))
#endif
static void r_Config_SCI12_receive_interrupt(void)
{
    if (g_sci12_rx_length > g_sci12_rx_count)
    {
        *gp_sci12_rx_address = SCI12.RDR;
        gp_sci12_rx_address++;
        g_sci12_rx_count++;

        if (g_sci12_rx_length == g_sci12_rx_count)
        {
            SCI12.SCR.BIT.RIE = 0;

            /* Clear TE and RE bits */
            if((0U == SCI12.SCR.BIT.TIE) && (0U == SCI12.SCR.BIT.TEIE))
            {
                SCI12.SCR.BYTE &= 0xCFU;
            }

            r_Config_SCI12_callback_receiveend();
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI12_receiveerror_interrupt
* Description  : This function is ERI12 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_SCI12_receiveerror_interrupt(void)
{
    uint8_t err_type;

    r_Config_SCI12_callback_receiveerror();

    /* Clear overrun error flag */
    err_type = SCI12.SSR.BYTE;
    err_type &= 0xDFU;
    err_type |= 0xC0U;
    SCI12.SSR.BYTE = err_type;
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI12_callback_transmitend
* Description  : This function is a callback function when SCI12 finishes transmission
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI12_callback_transmitend(void)
{
    /* Start user code for r_Config_SCI12_callback_transmitend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI12_callback_receiveend
* Description  : This function is a callback function when SCI12 finishes reception
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI12_callback_receiveend(void)
{
    /* Start user code for r_Config_SCI12_callback_receiveend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI12_callback_receiveerror
* Description  : This function is a callback function when SCI12 reception encounters error
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI12_callback_receiveerror(void)
{
    /* Start user code for r_Config_SCI12_callback_receiveerror. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
