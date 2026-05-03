/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_RSPI0_user.c
* Component Version: 1.10.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_RSPI0.
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
#include "Config_RSPI0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint16_t * gp_rspi0_tx_address;            /* RSPI0 transmit buffer address */
extern volatile uint16_t g_rspi0_tx_count;                 /* RSPI0 transmit data number */
extern volatile uint16_t * gp_rspi0_rx_address;            /* RSPI0 receive buffer address */
extern volatile uint16_t g_rspi0_rx_count;                 /* RSPI0 receive data number */
extern volatile uint16_t g_rspi0_rx_length;                /* RSPI0 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_RSPI0_Create_UserInit
* Description  : This function adds user code after initializing RSPI0
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RSPI0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_transmit_interrupt
* Description  : This function is SPTI0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_RSPI0_SPTI0
#pragma interrupt r_Config_RSPI0_transmit_interrupt(vect=VECT(RSPI0,SPTI0),fint)
#else
#pragma interrupt r_Config_RSPI0_transmit_interrupt(vect=VECT(RSPI0,SPTI0))
#endif
static void r_Config_RSPI0_transmit_interrupt(void)
{
    uint16_t frame_cnt;

    /* WAIT_LOOP */
    for (frame_cnt = 0U; frame_cnt < (_00_RSPI_FRAMES_1 + 1U); frame_cnt++)
    {
        if (g_rspi0_tx_count > 0U)
        {
            /* Write data for transmission */
            RSPI0.SPDR.WORD.H = (*(uint16_t*)gp_rspi0_tx_address);
            gp_rspi0_tx_address++;
            g_rspi0_tx_count--;
        }
        else
        {
            /* Disable transmit interrupt */
            RSPI0.SPCR.BIT.SPTIE = 0U;

            /* Enable idle interrupt */
            RSPI0.SPCR2.BIT.SPIIE = 1U;
            break;
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_receive_interrupt
* Description  : This function is SPRI0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_RSPI0_SPRI0
#pragma interrupt r_Config_RSPI0_receive_interrupt(vect=VECT(RSPI0,SPRI0),fint)
#else
#pragma interrupt r_Config_RSPI0_receive_interrupt(vect=VECT(RSPI0,SPRI0))
#endif
static void r_Config_RSPI0_receive_interrupt(void)
{
    uint16_t frame_cnt;

    /* WAIT_LOOP */
    for (frame_cnt = 0U; frame_cnt < (_00_RSPI_FRAMES_1 + 1U); frame_cnt++)
    {
        if (g_rspi0_rx_length > g_rspi0_rx_count)
        {
            *(uint16_t *)gp_rspi0_rx_address = RSPI0.SPDR.WORD.H;
            gp_rspi0_rx_address++;
            g_rspi0_rx_count++;

            if (g_rspi0_rx_length == g_rspi0_rx_count)
            {
                /* Disable receive interrupt */
                RSPI0.SPCR.BIT.SPRIE = 0U;
                r_Config_RSPI0_callback_receiveend();
                break;
            }
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_error_interrupt
* Description  : This function is SPEI0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_RSPI0_error_interrupt(void)
{
    uint8_t err_type;

    /* Disable RSPI function */
    RSPI0.SPCR.BIT.SPE = 0U;

    /* Disable transmit interrupt */
    RSPI0.SPCR.BIT.SPTIE = 0U;

    /* Disable receive interrupt */
    RSPI0.SPCR.BIT.SPRIE = 0U;

    /* Disable error interrupt */
    RSPI0.SPCR.BIT.SPEIE = 0U;

    /* Disable idle interrupt */
    RSPI0.SPCR2.BIT.SPIIE = 0U;

    /* Clear error sources */
    err_type = RSPI0.SPSR.BYTE;
    RSPI0.SPSR.BYTE = 0xA0U;

    if (0U != err_type)
    {
        r_Config_RSPI0_callback_error(err_type);
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_idle_interrupt
* Description  : This function is SPII0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_RSPI0_idle_interrupt(void)
{
    /* Disable RSPI function */
    RSPI0.SPCR.BIT.SPE = 0U;

    /* Disable idle interrupt */
    RSPI0.SPCR2.BIT.SPIIE = 0U;

    r_Config_RSPI0_callback_transmitend();
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_callback_transmitend
* Description  : This function is a callback function when RSPI0 finishes transmission
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_RSPI0_callback_transmitend(void)
{
    /* Start user code for r_Config_RSPI0_callback_transmitend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_callback_receiveend
* Description  : This function is a callback function when RSPI0 finishes reception
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_RSPI0_callback_receiveend(void)
{
    /* Start user code for r_Config_RSPI0_callback_receiveend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RSPI0_callback_error
* Description  : This function is a callback function when RSPI0 error occurs
* Arguments    : err_type -
*                    error type value
* Return Value : None
***********************************************************************************************************************/

static void r_Config_RSPI0_callback_error(uint8_t err_type)
{
    /* Start user code for r_Config_RSPI0_callback_error. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
