/***********************************************************************************************************************
* File Name    : main.c
* Version      : 1.0.0
* Device(s)    : R5F572TEAxFM
* Description  : main file.
* Creation Date: 2026-05-02
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "machine.h"
#include "stdint.h"
#include "iodefine.h"
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"

#include "Config_PORT.h"
#include "Config_ICU.h"
#include "Config_MTU1.h"
#include "Config_MTU2.h"
#include "Config_MTU3_MTU4.h"
#include "Config_MTU6_MTU7.h"
#include "Config_RSPI0.h"
#include "Config_S12AD0.h"
#include "Config_S12AD1.h"
#include "Config_S12AD2.h"
#include "Config_WDT.h"
#include "Config_GPT0.h"
#include "Config_GPT1.h"
#include "Config_GPT2.h"
#include "Config_GPT3.h"
#include "Config_MTU0.h"
#include "Config_MTU9.h"
#include "Config_SCI12.h"
#include "Config_CMT0.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
void main(void)
{
	// init peripheral
	R_Config_PORT_Create();
	R_Config_ICU_Create();
	R_Config_MTU1_Create();
	R_Config_MTU2_Create();
	R_Config_MTU3_MTU4_Create();
	R_Config_MTU6_MTU7_Create();
	R_Config_RSPI0_Create();	
	R_Config_S12AD0_Create();
	R_Config_S12AD1_Create();
	R_Config_S12AD2_Create();
	R_Config_WDT_Create();
	R_Config_GPT0_Create();
	R_Config_GPT1_Create();
	R_Config_GPT2_Create();
	R_Config_GPT3_Create();
	R_Config_MTU0_Create();
	R_Config_MTU9_Create();
	R_Config_SCI12_Create();
	R_Config_CMT0_Create();
	
	// start peripheral
	R_Config_WDT_Create();
	
	while(1)
	{
		R_Config_WDT_Restart();
	}
}