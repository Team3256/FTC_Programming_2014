float pie = 3.14159;
float track = 17.0;
float halfTrack = track / 2.0;
float wheelDiam = 3.88;
float wheelRadius = wheelDiam / 2.0;
float wheelCircumference = wheelDiam * PI;
float ticksPerInches = 2160 / wheelCircumference;
float ticksPerInchesNeveRest=1680/wheelCircumference;
float halfRobotCircumference = track*pie;
float robotCircumference = track*2*pie;
float j = 0;

void moveBackward(float feet, float motorSpeed)
{
	nMotorEncoder[backRightMotor] = 0;
	float inches= feet * 12;
	int nTicks= inches * ticksPerInchesNeveRest;
	while(abs(nMotorEncoder[backRightMotor]) < nTicks)
	{
			motor[frontRightMotor] = motorSpeed;
			motor[frontLeftMotor] = motorSpeed;
			motor[backRightMotor] = -motorSpeed;
			motor[backLeftMotor] = motorSpeed;
	}
	motor[frontLeftMotor] = 0;
	motor[frontRightMotor] = 0;
	motor[backRightMotor] = 0;
	motor[backLeftMotor] = 0;
}
void moveFoward(float feet, float motorSpeed)
{
	nMotorEncoder[backLeftMotor] = 0;
	float inches= 0.83 * feet * 12.0;
	//inches-=5;
	float nTicks=inches*ticksPerInchesNeveRest;
	while(abs(nMotorEncoder[backLeftMotor]) < nTicks)
	{

			motor[frontRightMotor] = -motorSpeed;
			motor[frontLeftMotor] = -motorSpeed;
			motor[backRightMotor] = motorSpeed;
			motor[backLeftMotor] = -motorSpeed;
			//writeDebugStreamLine("ticks: %d", nMotorEncoder[backLeftMotor]);
	}

	motor[frontLeftMotor] = 0;
	motor[frontRightMotor] = 0;
	motor[backRightMotor] = 0;
	motor[backLeftMotor] = 0;

}

	void rightTwoWheelTurn(float degreesMoved, float motorSpeed)
	{
		nMotorEncoder[backLeftMotor] = 0;
		float nTicks = abs((degreesMoved*halfTrack)/(wheelRadius));
		while(abs(nMotorEncoder[backLeftMotor]) < nTicks*4.9)
	{
			motor[frontRightMotor] = motorSpeed;
			motor[frontLeftMotor] = -motorSpeed;
			motor[backRightMotor] = -motorSpeed;
			motor[backLeftMotor] = -motorSpeed;
	}
}
	void leftTwoWheelTurn(float degreesMoved, float motorSpeed)
	{
		nMotorEncoder[backRightMotor] = 0;
		float nTicks = abs((degreesMoved*halfTrack)/(wheelRadius));
		while(abs(nMotorEncoder[backRightMotor]) < nTicks*5.5)
	{
			motor[frontRightMotor] = -motorSpeed;
			motor[frontLeftMotor] = motorSpeed;
			motor[backRightMotor] = motorSpeed;
			motor[backLeftMotor] = motorSpeed;
	}
}
void leftOneWheelTurn (float degrees, float power){
		nMotorEncoder[backRightMotor] = 0;
		float circum = pie*2*17;
		float percent = degrees/360;
		float nTicks = ticksPerInchesNeveRest* circum * percent;
		float motorSpeed = power;
		while(abs(nMotorEncoder[backRightMotor]) < nTicks*1.28)
	{
			motor[frontRightMotor] = -motorSpeed;
			motor[backRightMotor] = motorSpeed;
	}
}
void rightOneWheelTurn (float degrees, float power){
		nMotorEncoder[backLeftMotor] = 0;
		float circum = pie*2*17;
		float percent = degrees/360;
		float nTicks = ticksPerInchesNeveRest* circum * percent;
		float motorSpeed = power;
		while(abs(nMotorEncoder[backLeftMotor]) < nTicks*1.22)
	{
			motor[frontLeftMotor] = -motorSpeed;
			motor[backLeftMotor] = -motorSpeed;
	}
}
