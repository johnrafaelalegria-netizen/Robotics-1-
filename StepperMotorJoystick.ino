
/* stepper motor with joyatick
 Stepper Motor Control - speed control
 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int maxMotorSpeed = 15;       //Max speed in RPM
const int deadZoneMin = 490;         //minimal deadzone
const int deadZoneMax = 535;         //maximum deadzone
const int stepsToTake = 8;           // How many steps to take each loop (200 / 25)
// for your motor


/*initialize the stepper library on pins specifically 8,10,9,11 
to make sure stepper motor can go CCW*/ 
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);//communicate with serial monitor
}

void loop() {
  // read the sensor value:
  int valx = analogRead(A0);//read y value
  int motorSpeed = 0;       //create an int of motorSpeed to hold values 
  int stepDirection = 0;    //create an int of stepDirection to hold values

//CODE FOR CW
  if (valx > deadZoneMax){
    motorSpeed = map(valx, deadZoneMax, 1023, 0, maxMotorSpeed); //maps from 525 to 0 and 1023 to 15
    stepDirection = stepsToTake; // Positive direction (+8 steps)

    //Prints if motor is going CW while including bitvalue and its speed
    Serial.print("CW | Bit: ");
    Serial.print(valx);
    Serial.print(" | Speed: ");
    Serial.println(motorSpeed); 
  }
//CODE BLOCK FOR CCW
  else if (valx < deadZoneMin) {
    motorSpeed = map(valx, 0, deadZoneMin, maxMotorSpeed, 0); //maps from 0 to 15 and 490 to 0
    stepDirection = -stepsToTake; // Negative direction (-8 steps)
 
    //Prints if motor is going CCW while including bitvalue and its speed
    Serial.print("CCW | Bit: ");
    Serial.print(valx);
    Serial.print(" | Mapped Speed: ");
    Serial.println(motorSpeed); 
  }

//execute movement either CW or CCW
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed); //motor starts moving at the speed shown in serial monitor
    myStepper.step(stepDirection); //motor does +8 steps or -8 steps
  }
}

