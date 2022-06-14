//https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/
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

  Serial.print("KeyPressed: ");
  if(GamePad.isUpPressed()){
    motor.forward();
    Serial.print("Up");
  }else if(GamePad.isDownPressed()){
    motor.backward();
    Serial.print("Down");
  }else if(GamePad.isLeftPressed()){
    motor.forwardB();
    motor.backwardA();
    Serial.print("Left");
  }else if(GamePad.isRightPressed()){
    motor.forwardA();
    motor.backwardB();
    Serial.print("Right");
  }else{
    motor.stop();
    Serial.print("NONE");
  }
  Serial.println();
  
}





