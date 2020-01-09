 /*
 * motor.c
 *
 *  Created on: Dec 10, 2019
 *      Author: wyz
 */
#include "algorithnm.h"
#include "motor.h"
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "my_uart.h"

extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
static int LeftValueOfPulseNum;
static int RightValueOPulseNum;
static float speed_R,speed_L;

void motor_init(){
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	__HAL_TIM_SET_COUNTER(&htim3,CENTRAL_POINT);
	__HAL_TIM_SET_COUNTER(&htim4,CENTRAL_POINT);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4); //PWM
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4); //PWM
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,0);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
}

void set_motor_PWM(enum RightOrLeft side,int value){
	if(side == left){
		if (value >= 0) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,value);
		}else{//backward
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,-value);
		}
	}else{//right
		if (value >= 0) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,value);
		}else{//backward
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,-value);
		}
	}
}

void get_motor_speed(){
//	DirOfLeft = !(!((htim3.Instance->CR1) & (0x10)));
//	DirOfRight = !((htim4.Instance->CR1) & (0x10));
	LeftValueOfPulseNum = (uint32_t)(__HAL_TIM_GET_COUNTER(&htim3));
	RightValueOPulseNum = (uint32_t)(__HAL_TIM_GET_COUNTER(&htim4));
//	if(DirOfLeft != forward){//反转
//		LeftValueOfPulseNum = -(LeftValueOfPulseNum-CENTRAL_POINT);
//	}else{//正转
//		LeftValueOfPulseNum = CENTRAL_POINT-LeftValueOfPulseNum;
//	}
//	if(DirOfRight != forward){
//		RightValueOPulseNum = -(RightValueOPulseNum-CENTRAL_POINT );
//	}else{//正转
//		RightValueOPulseNum = CENTRAL_POINT - RightValueOPulseNum;
//	}
	RightValueOPulseNum = RightValueOPulseNum - CENTRAL_POINT ;
	LeftValueOfPulseNum = CENTRAL_POINT-LeftValueOfPulseNum;
	__HAL_TIM_SET_COUNTER(&htim3,CENTRAL_POINT);
	__HAL_TIM_SET_COUNTER(&htim4,CENTRAL_POINT);
	speed_R= ((float)RightValueOPulseNum)*200.0/2528.0*0.6283;
	speed_L= ((float)LeftValueOfPulseNum)*200.0/1685.0*0.6283;
}

//static uint8_t data[30];
//uint32_t counter;
//uint32_t PWM=0;
void my_one_step(){
	static uint32_t wakeup_counter = 0;
	int left_PWMvalue,right_PWMvalue;
//	int PWMvalue;
//	static uint32_t i = 0;
	get_motor_speed();
//	PWMvalue = PID_R_motor(ForwardSpeed,speed_R);
//	PWMvalue = PID_L_motor(ForwardSpeed,speed_L);
//	if(i<2000){i++;}else{PWMvalue+=3000;}
	static decoulpe_TypeDef decouple_speed;
	decoupling(ForwardSpeed, RollSpeed, &decouple_speed);
	left_PWMvalue = PID_L_motor(decouple_speed.Speed_L,speed_L);
	right_PWMvalue = PID_R_motor(decouple_speed.Speed_R,speed_R);
	set_motor_PWM(left,left_PWMvalue);
	set_motor_PWM(right,right_PWMvalue);
	if(left_PWMvalue <= 100 && left_PWMvalue>= -100 && right_PWMvalue <=100 && right_PWMvalue>= -100){
		if(wakeup_counter > 100){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
		}else{
			wakeup_counter++;
		}
	}else{
		wakeup_counter=0;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	}
//	sprintf(data,"%2.4f\n",speed_L);
//	HAL_UART_Transmit(&huart1, data, strlen(data), 0x05);


}



