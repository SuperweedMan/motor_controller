 /*
 * motor.h
 *
 *  Created on: Dec 10, 2019
 *      Author: wyz
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_


#define CENTRAL_POINT 32765

#include "main.h"
enum MotorDirection{
		forward=0,
		backward,
};

enum RightOrLeft{
	right=0,
	left,
};

typedef union {
	struct {
		uint8_t low;
		uint8_t mlow;
		uint8_t mhigh;
		uint8_t high;
	}U8;
	float F32;
}FloatToUnsignedChar;

extern float x_position,y_position,theta;

void motor_init();
void my_one_step();

#endif /* INC_MOTOR_H_ */
