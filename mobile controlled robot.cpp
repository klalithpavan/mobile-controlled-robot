Mobile controlled Rover
#include<AFMotor.h>

#define MAX_SPEED 160

#define MAX_SPEED_OFFSET 40

AF_DCMotor leftMotor1(1, MOTOR12_1KHZ);

AF_DCMotor leftMotor2(2, MOTOR12_1KHZ);

AF_DCMotor rightMotor1(3, MOTOR34_1KHZ);

AF_DCMotor rightMotor2(4, MOTOR34_1KHZ);

String motorSet = "";

char state;

int speedSet = 0;

void setup() {

Serial.begin(9600);

}

void loop() {

while(Serial.available() > 0)

{

state = Serial.read();

Serial.println(state);

}

//----------FORWARD---------------------------

if(state == 'f')

{

motorSet = "FORWARD";

leftMotor1.run(FORWARD);

leftMotor2.run(FORWARD);

rightMotor1.run(FORWARD);

rightMotor2.run(FORWARD);

for(speedSet=0 ; speedSet

{

leftMotor1.setSpeed(speedSet);

leftMotor2.setSpeed(speedSet);

rightMotor1.setSpeed(speedSet);

rightMotor2.setSpeed(speedSet);

delay(5);

}

}

//---------------BACKWARD--------------------------------

else if(state == 'b')

{

motorSet = "BACKWARD";

leftMotor1.run(BACKWARD);

leftMotor2.run(BACKWARD);

rightMotor1.run(BACKWARD);

rightMotor2.run(BACKWARD);

for(speedSet=0 ; speedSet

{

leftMotor1.setSpeed(speedSet);

leftMotor2.setSpeed(speedSet);

rightMotor1.setSpeed(speedSet);

rightMotor2.setSpeed(speedSet);

delay(5);

}

}

//----------------------RIGHT----------------------------------

else if(state == 'r')

{

motorSet = "RIGHT";

leftMotor1.run(FORWARD);

leftMotor2.run(FORWARD);

rightMotor1.run(BACKWARD);

rightMotor2.run(BACKWARD);

rightMotor1.setSpeed(speedSet + MAX_SPEED_OFFSET);

rightMotor2.setSpeed(speedSet + MAX_SPEED_OFFSET);

delay(1500);

motorSet = "FORWARD";

leftMotor1.run(FORWARD);

leftMotor2.run(FORWARD);

rightMotor1.run(FORWARD);

rightMotor2.run(FORWARD);

}

//------------------------------LEFT-----------------------------

else if(state == '1')

{

motorSet = "LEFT";

leftMotor1.run(BACKWARD);

leftMotor2.run(BACKWARD);

leftMotor1.setSpeed(speedSet + MAX_SPEED_OFFSET);

leftMotor2.setSpeed(speedSet + MAX_SPEED_OFFSET);

rightMotor1.run(FORWARD);

rightMotor2.run(FORWARD);

delay(1500);

motorSet = "FORWARD";

leftMotor1.run(FORWARD);

leftMotor2.run(FORWARD);

rightMotor1.run(FORWARD);

rightMotor2.run(FORWARD);

}

//------------------------STOP-----------------------------

else if(state == 's')

{

motorSet = "STOP";

leftMotor1.run(RELEASE);

leftMotor2.run(RELEASE);

rightMotor1.run(RELEASE);

rightMotor2.run(RELEASE);

}

}