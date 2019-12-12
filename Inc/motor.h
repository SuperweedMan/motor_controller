/*
 * motor.h
 *
 *  Created on: Dec 10, 2019
 *      Author: wyz
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_


#define CENTRAL_POINT 32765

enum MotorDirection{
		forward=0,
		backward,
};

enum RightOrLeft{
	right=0,
	left,
};

void motor_init();
void my_one_step();

#endif /* INC_MOTOR_H_ */
