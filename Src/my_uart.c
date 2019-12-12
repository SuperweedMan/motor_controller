/*
 * my_uart.c
 *
 *  Created on: Dec 11, 2019
 *      Author: wyz
 */
#include "main.h"
#include "my_uart.h"

extern UART_HandleTypeDef huart1;

static uint8_t rec_data_FIFO[20];
static uint8_t rec_data[10];
float ForwardSpeed = 0,RollSpeed = 0.5;
static FloatToUnsignedChar FTUC;
void my_uart_init(){
	HAL_UART_Receive_DMA(&huart1, rec_data_FIFO, 20);
}

void transfer_data(){
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

void HAL_UART_RxHalfCpltCallback  ( UART_HandleTypeDef *  huart ){
	if(huart->Instance == huart1.Instance){
		for(uint8_t i =0;i<10;i++){
			rec_data[i]=rec_data_FIFO[i];
			transfer_data();
		}
	}
}

void HAL_UART_RxCpltCallback  ( UART_HandleTypeDef *  huart ){
	if(huart->Instance == huart1.Instance){
		for(uint8_t i =0;i<10;i++){
			rec_data[i]=rec_data_FIFO[i+10];
			transfer_data();
		}
	}
}
