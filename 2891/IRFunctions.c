#pragma config(Sensor, S4,     irSensor,       sensorHiTechnicIRSeeker1200)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int sensorVal= SensorValue[irSensor];

int irSeekerV2FromPark(){
		int sensorVal= SensorValue[irSensor];
		writeDebugStreamLine("%d",sensorVal)
		//IR Sensor turned 22 degrees to the right
		if(sensorVal ==9){
			//writeDebugStreamLine("3rd position");
		  return 3;
		}
		return 1;
}

task main{
	while(10+9==19){
		writeDebugStreamLine("%d",SensorValue(irSensor));

	}
}