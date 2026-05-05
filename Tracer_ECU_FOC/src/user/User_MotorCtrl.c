/***********************************************************************************************************************
* File Name    : User_MotorCtrl.c
* Version      : 0.0.1
* Device(s)    : R5F572TFAxFP
* Description  : 
* Creation Date: 2025-12-07
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "User_MotorCtrl.h"
#include "r_cg_macrodriver.h"
#include "mathf.h"
#include "Config_S12AD0.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
void User_Motor_Ctrl_Current(void);
void User_Motor_Ctrl_Speed(void);
void User_3rd_Harmonic_Add(void);


drv_status_t e_drv_status = DRV_STS_INV_OFF;

uint16_t u16_an000 		= 0;
uint16_t u16_an001 		= 0; 
uint16_t u16_an002 		= 0; 

float	fl_iu = 0.0;
float	fl_iv = 0.0;
float	fl_iw = 0.0;

float	fl_iu_offset = 0.00;
float   fl_iv_offset = 0.00;
float   fl_iw_offset = 0.00;

float   R1f = 0.307f;  				// 巻線抵抗R1/相[Ω]
float	Ldf = 0.000000f; 			// d軸インダクタンス[H] 未測定
float	Lqf	= 0.000062f; 			// q軸インダクタンス[H]
float	Kef	= 0.011785f; 			// Ke発電定数（絶対変換）

float	fl_ia0		= 0.0;			// a軸電流
float	fl_ib0 		= 0.0;			// b軸電流
float	fl_id0 		= 0.0;			// d軸電流
float	fl_iq0 		= 0.0;			// q軸電流
float	fl_vd0 		= 0.0;   		// d軸電圧指令
float	fl_vq0 		= 1.0;   		// q軸電圧指令
float	fl_vd1 		= 0.0;   		// d軸電圧指令
float	fl_vq1 		= 0.0;   		// q軸電圧指令
float	fl_va0 		= 0.0;   		// a軸電圧指令
float	fl_vb0 		= 0.0;   		// b軸電圧指令
float	fl_va0_t 	= 0.0;   		// a軸電圧指令（計算用テンポラリ）
float	fl_vb0_t 	= 0.0;   		// b軸電圧指令（計算用テンポラリ）
float	fl_vu0 		= 0.0;			// U相電圧指令
float	fl_vv0 		= 0.0;			// V相電圧指令
float	fl_vw0 		= 0.0;			// W相電圧指令
float	fl_vu1 		= 0.0;			// U相修正後電圧指令
float	fl_vv1 		= 0.0;			// V相修正後電圧指令
float	fl_vw1 		= 0.0;			// W相修正後電圧指令

/* 電流制御 */
float	fl_i_refl_asr 	= 0.0;		// ASRの出力
float	I_refl_q_ini 	= 0.0;		// ASR初期値

float	fl_id_ref		= 0.0;		// d軸電流指令	
float	fl_iq_ref		= 0.0;		// d軸電流指令

float	fl_id_err 		= 0.0;		// d軸電流偏差
float	fl_iq_err 		= 0.0;		// q軸電流偏差

float	fl_kp_acr 	= 0.01116 * 4;	// 比例ゲイン 800[rad/s] ( Rline=0.26ohm, Lline=13.95mH )
float	fl_ki_acr 	= 0.01040 * 4;	// 積分ゲイン 800[rad/s] ( Rline=0.26ohm, Lline=13.95mH )

float	fl_s_kid_acr 	= 0.0; 		// 積分値の中身
float	fl_s_kiq_acr 	= 0.0; 		// 積分値の中身

float	fl_s_lpf_id0 	= 0.0;		// 一次遅れフィルタ
float	fl_k_lpfl_id0 	= 0.05; 	// =Ts/Tf, Ts=0.00005,Tf=0.001
float	fl_s_lpf_iq0 	= 0.0;		// 一次遅れフィルタ
float	fl_k_lpfl_iq0 	= 0.05; 	// =Ts/Tf, Ts=0.00005,Tf=0.001

float	fl_k_ad_2_curr	= 1.0 / 124.121;

/* 速度制御 */
float	fl_n_rpm_err 	= 0.0;				// 速度誤差
float	fl_kp_asr 		= 0.000844;			// 比例ゲイン 10[rad/s]
float	fl_ki_asr 		= 0.0000000844;		// 積分ゲイン 10[rad/s]

float	fl_s_ki_asr 	= 0.0; 				// 積分器中身
float	fl_n_rpm_ref 	= 0.0; 				// 速度指令[r/min]

float	fl_sin_theta 	= 0.0;				// sinθ buffer
float	fl_cos_theta 	= 0.0;				// cosθ buffer

int16_t s16_enc1_cnt 	= 0;

float	fl_enc1_mech_ang 	= 0.0;
float	fl_enc1_elec_ang 	= 0.0;
float	fl_enc1_n_rpm		= 0.0;

float	fl_k_cnt_2_e_ang		= (TWOPI / 14) * POLE_PAIRS;
//float	fl_k_cnt_diffl_2_rpm	= (1.0 / ENC_CNT_PPR) * (60.0 / TS_SPEED);

/***********************************************************************************************************************
* Function Name: User_Motor_Ctrl
* Description  : 
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void User_Motor_Ctrl(void)
{
	PORT9.PODR.BIT.B6 = 1U;		// デバッグ用
	
//	User_Motor_Ctrl_Speed();
	
	User_Motor_Ctrl_Current();
	
	PORT9.PODR.BIT.B6 = 0U;		// デバッグ用
}

/***********************************************************************************************************************
* Function Name: User_Motor_Ctrl_Current
* Description  : 
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void User_Motor_Ctrl_Current(void)
{	
	/* Start ADC */
	S12AD.ADCSR.BIT.ADST 	= 1U;
	S12AD1.ADCSR.BIT.ADST 	= 1U;
	
	/* Wait for ADC */
	while (S12AD.ADCSR.BIT.ADST || S12AD1.ADCSR.BIT.ADST) { nop(); }
	
	/* Get ADC result */
	u16_an000 	= S12AD.ADDR0;
	u16_an001 	= S12AD.ADDR1;
	
	/* Iuvw -> Iab */
	fl_iw = (float) -((u16_an000 - 2048) * fl_k_ad_2_curr) - fl_iw_offset;
	fl_iv = (float) -((u16_an001 - 2048) * fl_k_ad_2_curr) - fl_iv_offset;
	fl_iu = -fl_iv - fl_iw;
	
	fl_ia0 = 0.8164965809280 * (fl_iu - 0.5 * (fl_iv + fl_iw));		// Ia = sqrt(2/3) * {Iu - (Iv + Iw) / 2}
	fl_ib0 = 0.7071067811866 * (fl_iv - fl_iw);						// Ib = sqrt(1/2) * (Iv - Iw)
	
	/* Calc Elec angle */
	s16_enc1_cnt 		= (MTU1.TCNT & 0x0FFF);
	fl_enc1_mech_ang	= (s16_enc1_cnt / ENC_CNT_PPR) * TWOPI;
	fl_enc1_elec_ang	= fmodf((fl_enc1_mech_ang * POLE_PAIRS), TWOPI);
	
	if (fl_enc1_elec_ang < 0.0f) fl_enc1_elec_ang += TWOPI;
	
	if (e_drv_status == DRV_STS_INV_ON_E_ANG_TUNE) 
	{
		MTU.TSTRA.BIT.CST1	= 0U;	// counter stop
		MTU1.TCNT 			= 0U;	// counter init
    	MTU.TSTRA.BIT.CST1	= 1U;	// counter start
		
		fl_enc1_elec_ang = 0.0;
	}
	
	/* Calc sinθ, cosθ */
	fl_sin_theta = sinf(fl_enc1_elec_ang);
	fl_cos_theta = cosf(fl_enc1_elec_ang);
	
	/* Iab -> Idq */
	fl_id0 =  fl_ia0 * fl_cos_theta + fl_ib0 * fl_sin_theta;
	fl_iq0 = -fl_ia0 * fl_sin_theta + fl_ib0 * fl_cos_theta;
	
	/* LPF(Id,Iq) */
	fl_s_lpf_id0 += (fl_id0 - fl_s_lpf_id0) * fl_k_lpfl_id0; 
    fl_s_lpf_iq0 += (fl_iq0 - fl_s_lpf_iq0) * fl_k_lpfl_iq0; 
	
	/* Current PI controller (ACR) */
	switch (e_drv_status)
	{
		case DRV_STS_INV_OFF:
			
			fl_id_ref 		= 0.0;
			fl_iq_ref 		= 0.0;
			fl_id_err 		= 0.0;
			fl_iq_err 		= 0.0;
			fl_s_kid_acr	= 0.0;
			fl_s_kiq_acr 	= 0.0;
			break;
			
		case DRV_STS_INV_ON_E_ANG_TUNE:
		
			fl_iq_ref 	= 0.0;
			fl_id_err 	= fl_id_ref - fl_s_lpf_id0;
			fl_iq_err 	= fl_iq_ref - fl_s_lpf_iq0;
			break;
		
		case DRV_STS_INV_ON_SPEED_CTRL:

			fl_id_ref	= 0.0;
			fl_iq_ref	= fl_i_refl_asr;
			fl_id_err 	= fl_id_ref - fl_s_lpf_id0;
			fl_iq_err 	= fl_iq_ref - fl_s_lpf_iq0;	
			break;
			
		case DRV_STS_INV_ON_CURRENT_CTRL:

			fl_id_err 	= fl_id_ref - fl_s_lpf_id0;
			fl_iq_err 	= fl_iq_ref - fl_s_lpf_iq0;	
			break;
	}
	
	/* Id ACR */
	if ((fl_vd0 >= V_REF_MAX) && (fl_id_err > 0))
	{
		/* do nothing */
	}
	else if ((fl_vd0 <= V_REF_MIN) && (fl_id_err < 0))
	{
		/* do nothing */		
	}
	else
	{
		fl_s_kid_acr += fl_ki_acr * fl_id_err; 					// Calc coeffl_I
	}

	if (fl_s_kid_acr > V_REF_MAX) fl_s_kid_acr = V_REF_MAX;		// Integral limitter (+)
	if (fl_s_kid_acr < V_REF_MIN) fl_s_kid_acr = V_REF_MIN;		// Integral limitter (-)
	
	fl_vd0 = fl_s_kid_acr + fl_kp_acr * fl_id_err;				// Calc coeffl_P and Vq_refarence
	
	if (fl_vd0 > V_REF_MAX)	fl_vd0 = V_REF_MAX;					// Vd_refarence limitter (+)
	if (fl_vd0 < V_REF_MIN)	fl_vd0 = V_REF_MIN;					// Vd_refarence limitter (-)
	
	/* Iq ACR */
	if ((fl_vq0 >= V_REF_MAX) && (fl_iq_err > 0))
	{
		/* do nothing */	
	}
	else if ((fl_vq0 <= V_REF_MIN) && (fl_iq_err < 0))
	{
		/* do nothing */		
	}
	else
	{
		fl_s_kiq_acr += fl_ki_acr * fl_iq_err; 					// Calc coeffl_I
	}

	if (fl_s_kiq_acr > V_REF_MAX) fl_s_kiq_acr = V_REF_MAX;		// Integral limitter (+)
	if (fl_s_kiq_acr < V_REF_MIN) fl_s_kiq_acr = V_REF_MIN;		// Integral limitter (-)
	
	fl_vq0 = fl_s_kiq_acr + fl_kp_acr * fl_iq_err; 				// Calc coeffl_P and Vq_refarence
	
	if (fl_vq0 > V_REF_MAX)	fl_vq0 = V_REF_MAX;					// Vq_refarence limitter (+)
	if (fl_vq0 < V_REF_MIN)	fl_vq0 = V_REF_MIN;					// Vq_refarence limitter (-)
	
    /* Vdq -> Vab */
    fl_va0 = fl_vd0 * fl_cos_theta - fl_vq0 * fl_sin_theta;
    fl_vb0 = fl_vd0 * fl_sin_theta + fl_vq0 * fl_cos_theta;

    /* Vab -> Vuvw */
    fl_va0_t = 0.40824892046 * fl_va0;
    fl_vb0_t = 0.70710678118 * fl_vb0;
	
    fl_vu0 = 2.0 * fl_va0_t;
    fl_vv0 = -fl_va0_t + fl_vb0_t;
    fl_vw0 = -fl_va0_t - fl_vb0_t;

	/* 3rd harmonic addition */
	User_3rd_Harmonic_Add();
	
	/* Offset negative amplitude for PWM */
	fl_vu1 += 1.0;
	fl_vv1 += 1.0;
	fl_vw1 += 1.0;
	
	if (fl_vu1 > 2.0) 	fl_vu1 = 2.0;
	if (fl_vu1 < 0.0) 	fl_vu1 = 0.0;
	
	if (fl_vv1 > 2.0) 	fl_vv1 = 2.0;
	if (fl_vv1 < 0.0) 	fl_vv1 = 0.0;
	
	if (fl_vw1 > 2.0) 	fl_vw1 = 2.0;
	if (fl_vw1 < 0.0) 	fl_vw1 = 0.0;
		
	MTU3.TGRB = (uint16_t) 3120.0 - (fl_vu1 * 1560.0);
    MTU3.TGRD = (uint16_t) 3120.0 - (fl_vu1 * 1560.0);
	
    MTU4.TGRA = (uint16_t) 3120.0 - (fl_vv1 * 1560.0);
    MTU4.TGRC = (uint16_t) 3120.0 - (fl_vv1 * 1560.0);
	
    MTU4.TGRB = (uint16_t) 3120.0 - (fl_vw1 * 1560.0);
    MTU4.TGRD = (uint16_t) 3120.0 - (fl_vw1 * 1560.0);
}

/***********************************************************************************************************************
* Function Name: User_Motor_Ctrl_Speed
* Description  : 
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void User_Motor_Ctrl_Speed(void)
{
	/* Calc motor speed */
//	fl_enc1_n_rpm = (float) (u16_enc1_cnt0 - u16_enc1_cnt1) * fl_k_cnt_diffl_2_rpm;

	fl_vd1	= fl_vd0;	// Set before value Vd0 to Vd1
	fl_vq1	= fl_vq0;	// Set before value Vq0 to Vq1
	
	/* Speed PI controller (ASR) */
	switch (e_drv_status)
	{
		case DRV_STS_INV_OFF:
			
			fl_n_rpm_ref 	= 0.0;
			fl_n_rpm_err 	= 0.0;
			fl_s_ki_asr		= 0.0;
			
			break;
			
		case DRV_STS_INV_ON_E_ANG_TUNE:
		
			fl_n_rpm_ref 	= 0.0;
			fl_n_rpm_err 	= 0.0;
			fl_s_ki_asr		= 0.0;
			break;
		
		case DRV_STS_INV_ON_SPEED_CTRL:
			
			fl_n_rpm_err = fl_n_rpm_ref - fl_enc1_n_rpm;	
			break;
	}
	
    fl_s_ki_asr += fl_ki_asr * fl_n_rpm_err;					// Calc coeffl_I
	
    if (fl_s_ki_asr > I_REF_MAX) fl_s_ki_asr = I_REF_MAX;		// Integral limitter (+)
	if (fl_s_ki_asr < I_REF_MIN) fl_s_ki_asr = I_REF_MIN;		// Integral limitter (-)

	fl_i_refl_asr = fl_s_ki_asr + fl_kp_asr * fl_n_rpm_err;		// Calc coeffl_P and Curr_refarence
    
	if (fl_i_refl_asr > I_REF_MAX) fl_i_refl_asr = I_REF_MAX;	// Curr_refarence limitter (+)
	if (fl_i_refl_asr < I_REF_MIN) fl_i_refl_asr = I_REF_MIN;	// Curr_refarence limitter (-)

//	u16_enc1_cnt1 = u16_enc1_cnt0;
}

/***********************************************************************************************************************
* Function Name: User_3rd_Harmonic_Add
* Description  : 
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void User_3rd_Harmonic_Add(void)
{
	float fl_hip_vmax 	= 0.0;	// Buffer for choise max voltage
	float fl_hip_vmin 	= 0.0;	// Buffer for choise min voltage
	float fl_hip_vzero 	= 0.0;	// Buffer correction phase zero voltage  
 
	if ( fl_vu0 > fl_vv0 )
	{
		if (fl_vu0 > fl_vw0 )			// Max = Vu
		{
			fl_hip_vmax = fl_vu0;
	
			if ( fl_vv0 > fl_vw0 )
			{
				fl_hip_vmin = fl_vw0;	// Min = Vw
			}
			else
			{
				fl_hip_vmin = fl_vv0;	// Min = Vv
			}
		}
		else
		{
			fl_hip_vmax = fl_vw0;		// Max = Vw
			fl_hip_vmin = fl_vv0;		// Min = Vv
		}	
	}
	else
	{
		if (fl_vv0 > fl_vw0 )			// Max = Vv
		{
			fl_hip_vmax = fl_vv0;
	
			if ( fl_vu0 > fl_vw0 )
			{
				fl_hip_vmin = fl_vw0;	// Min = Vw
			}
			else
			{
				fl_hip_vmin = fl_vu0;	// Min = Vu
			}
		}
		else
		{
			fl_hip_vmax = fl_vw0;		// Max = Vw
			fl_hip_vmin = fl_vu0;		// Min = Vu
		}
	}
  
	fl_hip_vzero = (fl_hip_vmax + fl_hip_vmin) * 0.5;	// Calc correction phase zero voltage
	
 	fl_vu1 = fl_vu0 - fl_hip_vzero;
	fl_vv1 = fl_vv0 - fl_hip_vzero;
	fl_vw1 = fl_vw0 - fl_hip_vzero;
}