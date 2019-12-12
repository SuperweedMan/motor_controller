/*
 * my_uart.h
 *
 *  Created on: Dec 11, 2019
 *      Author: wyz
 */

#ifndef INC_MY_UART_H_
#define INC_MY_UART_H_

typedef union {
	struct {
		uint8_t low;
		uint8_t mlow;
		uint8_t mhigh;
		uint8_t high;
	}U8;
	float F32;
}FloatToUnsignedChar;

void my_uart_init();

extern float ForwardSpeed,RollSpeed;

#endif /* INC_MY_UART_H_ */
