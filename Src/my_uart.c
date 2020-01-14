/*
 * my_uart.c
 *
 *  Created on: Dec 11, 2019
 *      Author: wyz
 */
#include "main.h"
#include "my_uart.h"
#include "motor.h"

extern UART_HandleTypeDef huart1;

static uint8_t rec_data_FIFO[20];
static uint8_t rec_data[10];
float ForwardSpeed = 0,RollSpeed = 0.5;
static FloatToUnsignedChar FTUC;
void my_uart_init(){
	HAL_UART_Receive_DMA(&huart1, rec_data_FIFO, 20);
}

void transfer_data_old(){
	if((rec_data[0]==0xff)&&(rec_data[9]==0xff)){
		FTUC.U8.low = rec_data[1];
		FTUC.U8.mlow = rec_data[2];
		FTUC.U8.mhigh = rec_data[3];
		FTUC.U8.high = rec_data[4];
		ForwardSpeed = FTUC.F32;
		FTUC.U8.low = rec_data[5];
		FTUC.U8.mlow = rec_data[6];
		FTUC.U8.mhigh = rec_data[7];
		FTUC.U8.high = rec_data[8];
		RollSpeed = FTUC.F32;
	}
}

void transfer_data(){
	static uint8_t flage = 0;
	static uint8_t a[8];
	uint8_t res;
	for(uint8_t i = 0;i<10;i++){
		res = rec_data[i];
		switch(flage)
		{
			case 0:
			{
				if(res==0xff)
					flage++;
				else
					flage=0;
				break;
			}
			case 1:
			{
				a[0]=res;
				flage++;
				break;
			}
			case 2:
			{
				a[1]=res;
				flage++;
				break;
			}
			case 3:
			{
				a[2]=res;
				flage++;
				break;
			}
			case 4:
			{
				a[3]=res;
				flage++;
				 break;
			}
			case 5:
			{
				a[4]=res;
				flage++;
				 break;
			}
			case 6:
			{
				a[5]=res;
				flage++;
				 break;
			}
			case 7:
			{
				a[6]=res;
				flage++;
				 break;
			}
			case 8:
			{
				a[7]=res;
				flage++;
				 break;
			}
			case 10:
			{
				if(res==0xff)
				{
					FTUC.U8.low = a[0];
					FTUC.U8.mlow = a[1];
					FTUC.U8.mhigh = a[2];
					FTUC.U8.high = a[3];
					ForwardSpeed = FTUC.F32;
					FTUC.U8.low = a[4];
					FTUC.U8.mlow = a[5];
					FTUC.U8.mhigh = a[6];
					FTUC.U8.high = a[7];
					RollSpeed = FTUC.F32;
					flage=0;
				}
				else
				{
					flage=0;
				}
				break;
				}
			}
	}
}

void HAL_UART_RxHalfCpltCallback  ( UART_HandleTypeDef *  huart ){
	if(huart->Instance == huart1.Instance){
		for(uint8_t i =0;i<10;i++){
			rec_data[i]=rec_data_FIFO[i];
			transfer_data_old();
		}
	}
}

void HAL_UART_RxCpltCallback  ( UART_HandleTypeDef *  huart ){
	if(huart->Instance == huart1.Instance){
		for(uint8_t i =0;i<10;i++){
			rec_data[i]=rec_data_FIFO[i+10];
			transfer_data_old();
		}
	}
}
