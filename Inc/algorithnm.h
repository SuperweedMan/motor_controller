/*
 * algorithnm.h
 *
 *  Created on: 2019年12月12日
 *      Author: wyz
 */

#ifndef INC_ALGORITHNM_H_
#define INC_ALGORITHNM_H_

typedef struct{
	float wc;
	float wo;
	float lam;
	float ts;
}Final_Parameters;

typedef struct{
	float num[1];
	float den[3];
}Transfer1_3_Parameters;

typedef struct
{
  float Kp;                       //比例系数Proportional
  float Ki;                       //积分系数Integral
  float Kd;                       //微分系数Derivative

  float Ek;                       //当前误差
  float Ek1;                      //前一次误差 e(k-1)
  float Ek2;                      //再前一次误差 e(k-2)

  int PWMvalue;
}PID_IncTypeDef;

typedef struct{
	float ts;
	float to;
	float tc;
	float u_last;
}Filer_TypeDef;

typedef struct{
	float Speed_L;
	float Speed_R;
}decoulpe_TypeDef;

int PID_R_motor(float r,float speed);
int PID_L_motor(float r,float speed);
void decoupling(float forwardspeed,float rollspeed,decoulpe_TypeDef * decouple);

#endif /* INC_ALGORITHNM_H_ */
