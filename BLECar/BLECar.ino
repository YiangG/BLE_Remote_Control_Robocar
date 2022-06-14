//https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/
//author: Yiang Gong
//06/14/2022
#include <L298NX2.h>
#include <L298N.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Pin definition-----------------
const unsigned int ENA = 32;
const unsigned int IN1 = 33;
const unsigned int IN2 = 27;
const unsigned int IN3 = 14;
const unsigned int IN4 = 12;
const unsigned int ENB = 13;

//variables-----------------------
int angle, radius;
float x_axis, y_axis;
float temp, result;
int motorSpeedA = 0;
int motorSpeedB = 0;

// Initialize both motors--------------------
L298NX2 motor(ENA, IN1, IN2, ENB, IN3, IN4);

void setup()
{
  // Used to display information
  Serial.begin(115200);
  //motor.setSpeed(50);
  motor.setSpeed(200);
  Dabble.begin("MyEsp32");       //set bluetooth name of your device
  motor.stop();
  // Wait for Serial Monitor to be opened
  while (!Serial){
  }
}

void loop(){
  Dabble.processInput();

  x_axis = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(x_axis);
  Serial.print('\t');
  y_axis = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(y_axis);
  Serial.println();

  motorSpeedA = mapRange(abs(y_axis),0,7,0,255);
  motorSpeedB = mapRange(abs(y_axis),0,7,0,255);

  //set motor direction by y_axis
  if (y_axis < 0) {
    motor.backward();
  }else if(y_axis > 0){
    motor.forward();
  }else{
    motor.stop();
  }
  
  // X-axis used for left and right control
  if (x_axis < 0) {
    motorSpeedA = motorSpeedA - 0.5*mapRange(abs(x_axis), 0,7, 0, 255);
    motorSpeedB = motorSpeedB + 0.5*mapRange(abs(x_axis), 0,7, 0, 255);
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }else if(motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if(motorSpeedB < 0) {
      motorSpeedB = 0;
    }else if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }else if(x_axis > 0){
    motorSpeedA = motorSpeedA + 0.5*mapRange(abs(x_axis), 0,7, 0, 255);
    motorSpeedB = motorSpeedB - 0.5*mapRange(abs(x_axis), 0,7, 0, 255);
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }else if(motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if(motorSpeedB < 0) {
      motorSpeedB = 0;
    }else if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }

  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  motor.setSpeedA(motorSpeedA);
  motor.setSpeedB(motorSpeedB);
}

int mapRange(float inValue, float minInRange, float maxInRange, float minOutRange, float maxOutRange){
  float x = (inValue - minInRange) / (maxInRange - minInRange);
  float result = minOutRange + (maxOutRange - minOutRange) * x;
  return (int)result;  
}
