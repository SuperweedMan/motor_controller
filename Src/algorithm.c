/*
 * algorithm.c
 *
 *  Created on: 2019年12月12日
 *      Author: wyz
 */
#include "algorithnm.h"
#include "main.h"
#include "stdio.h"
#include "string.h"

void decoupling(float forwardspeed,float rollspeed,decoulpe_TypeDef * decouple){
	decouple->Speed_L = forwardspeed*1+rollspeed*(-0.2050);
	decouple->Speed_R = forwardspeed*1+rollspeed*0.2050;
}

float fliter(float r,Filer_TypeDef *filer){
	static float A,B,C,u_return;
	A=(2*filer->tc-filer->ts)/(2*filer->tc+filer->ts);
	B=(2*filer->to+filer->ts)/(2*filer->tc+filer->ts);
	C=(filer->ts-2*filer->to)/(2*filer->tc+filer->ts);
	u_return = A*filer->u_last+B*r+C*r;
	filer->u_last = u_return;
	return u_return;
}

int PID_Inc(float SetValue, float ActualValue, PID_IncTypeDef *PID){
	PID->Ek = SetValue - ActualValue;
//	float Inc = (PID->Kp*(PID->Ek-PID->Ek1))+(PID->Ki*PID->Ek)+(PID->Kd*(PID->Ek+PID->Ek2-(PID->Ek1*2)));
	float Inc = (PID->Kp * PID->Ek) - (PID->Ki * PID->Ek1) + (PID->Kd * PID->Ek2);
	PID->Ek2 = PID->Ek1;
	PID->Ek1 = PID->Ek;
	PID->PWMvalue += (int)Inc;
	return PID->PWMvalue;
}

int saturation(int r,int uplimit,int downlimit){
	int result;
	if(r > uplimit){
		result = uplimit;
	}else{
		if(r < downlimit){
			result = downlimit;
		}else{
			result = r;
		}
	}
	return result;
}


int PID_R_motor(float r,float speed){
	static Transfer1_3_Parameters transfer_data = {{0.04541},{1,17.74,292.9}};
	static Final_Parameters Parameters_data = {5,15,1.5,0.005};
	float kpd = transfer_data.den[0]*Parameters_data.wo/(transfer_data.num[0]*Parameters_data.lam);
	static Filer_TypeDef Filter_data;
	static PID_IncTypeDef PID_data;
	Filter_data.ts = Parameters_data.ts;Filter_data.tc =1/Parameters_data.wc;
	Filter_data.to = 1/Parameters_data.wo;
	PID_data.Kp = kpd*(1+Parameters_data.wc*Parameters_data.lam);
	PID_data.Ki = kpd*Parameters_data.wc;
	PID_data.Kd = kpd*Parameters_data.lam;

	return saturation(PID_Inc(fliter(r,&Filter_data),speed,&PID_data),10000,-10000);

	//debug
//	float a = fliter(r,&Filter_data);
//	int b = PID_Inc(a,speed,&PID_data);
//	int c = saturation(b,10000,-10000);
//	sprintf(data,"d:%d,%d,%0.3f,",b,c,a);
//	HAL_UART_Transmit(&huart1, data, strlen(data), 0x03);
//	return c;
}

//static uint8_t data[20];
//extern UART_HandleTypeDef huart1;
int PID_L_motor(float r,float speed){
	static Transfer1_3_Parameters transfer_data = {{0.08475},{1,32.93,502.1}};
	static Final_Parameters Parameters_data = {5,15,1.5,0.005};
	float kpd = transfer_data.den[0]*Parameters_data.wo/(transfer_data.num[0]*Parameters_data.lam);
	static Filer_TypeDef Filter_data;
	static PID_IncTypeDef PID_data;
	Filter_data.ts = Parameters_data.ts;Filter_data.tc =1/Parameters_data.wc;
	Filter_data.to = 1/Parameters_data.wo;
	PID_data.Kp = kpd*(1+Parameters_data.wc*Parameters_data.lam);
	PID_data.Ki = kpd*Parameters_data.wc;
	PID_data.Kd = kpd*Parameters_data.lam;

	return saturation(PID_Inc(fliter(r,&Filter_data),speed,&PID_data),10000,-10000);

	//debug
//	float a = fliter(r,&Filter_data);
//	int b = PID_Inc(a,speed,&PID_data);
//	int c = saturation(b,10000,-10000);
//	sprintf(data,"d:%d,%d,%0.3f,",b,c,a);
//	HAL_UART_Transmit(&huart1, data, strlen(data), 0x03);
//	return c;
}
