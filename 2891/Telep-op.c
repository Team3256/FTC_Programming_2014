#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorB,          feedingMotorDos, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     backRightMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     frontRightMotor,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorJ, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorK,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorL, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorM,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     frontLeftMotor, 			 tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     backLeftMotor,        tmotorTetrix, openLoop)


#include "JoystickDriver.c"

void tankDrive()
	{
		motor[frontRightMotor] = ((-100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		motor[backRightMotor] = ((100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		//right two motors controlled by the left joystick in controller one
		motor[frontLeftMotor] = ((-100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
			motor[backLeftMotor] = ((-100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
	}

task main()
{
while(true){
	tankDrive();
}
}
