/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_RSPI0.h
* Component Version: 1.10.0
* Device(s)        : R5F572TFAxFP
* Description      : This file implements device driver for Config_RSPI0.
***********************************************************************************************************************/

#ifndef CFG_Config_RSPI0_H
#define CFG_Config_RSPI0_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_rspi.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _31_RSPI0_DIVISOR               (0x31U) /* SPBR(RSPI bit rate) register value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_RSPI0_Create(void);
void R_Config_RSPI0_Create_UserInit(void);
void R_Config_RSPI0_Start(void);
void R_Config_RSPI0_Stop(void);
MD_STATUS R_Config_RSPI0_Send_Receive(uint16_t * const tx_buf, uint16_t tx_num, uint16_t * const rx_buf);
void r_Config_RSPI0_error_interrupt(void);
void r_Config_RSPI0_idle_interrupt(void);
static void r_Config_RSPI0_callback_transmitend(void);
static void r_Config_RSPI0_callback_receiveend(void);
static void r_Config_RSPI0_callback_error(uint8_t err_type);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
