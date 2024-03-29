#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     frontleft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     frontright,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     backleft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     backright,     tmotorTetrix, openLoop)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int gain=5;
float pi = 3.14;
float ticksPerInches = 1440/Diameter * pi;
float instruction [25][2];


/*move forward funtion*/
void forward (int speed)
	{
		motor(frontleft)=speed;
		motor(frontright)=speed;
		motor(backleft)=speed;
		motor(backright)=speed;
		wait1Msec(10);
	}
/*move backward function*/
void backward (int speed)
	{
		motor(frontleft)=-speed;
		motor(frontright)=-speed;
		motor(backleft)=-speed;
		motor(backright)=-speed;
		wait1Msec(10);
	}
/*turn right funtion*/
void turnRight (int speed)
	{
		motor(frontleft)=speed;
		motor(backleft)=speed;
		wait1Msec(10);
	}
/*turn left funtion*/
void turnLeft (int speed)
	{
		motor(frontright)=speed;
		motor(backright)=speed;
		wait1Msec(10);
	}
/*right wheels movement*/
void rightWheels (int speed)
	{
		motor(frontright)=speed;
		motor(backright)=speed;
		wait1Msec(10);
	}
/*left wheels movement*/
void leftWheels (int speed)
	{
		motor(frontleft)=speed;
		motor(backleft)=speed;
		wait1Msec(10);
	}
void createArray(int btn){

	bool button1= false,button2= false,button3= false;
	int i=0;
	if (btn == 0){
		if (button1 == false){
			button1 = true;
			instruction [i][0]=1;
			i+=1;
		}
		if (button1 == true){
			button1 = false;
	}
	}
	if (btn == 1){
		if (button2 == false){
			button2 = true;
			instruction [i][0]=2;
			i+=1;
		}
		if (button2 == true){
			button2 = false;
		}
	}

	void printArray(){
		writeDebugStreamLine();
	}

}





task main()
{

}
