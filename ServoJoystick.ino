/*servo controlled by joystick*/

#include <Servo.h>
Servo myservo; //create servo object to control a servo
int potpin = A0; //analog pin used to connect to joystick
int val; //variable to read the value from analog pin
void setup() {  
  // put your main code here, to run repeatedly:
 myservo.attach(9); //attaches the servo on pin 9 to the servo object
}


void loop() {
 val = analogRead(potpin); //declaring that val represents the reading of A0
 val = map(val, 0, 1023, 0, 180); //convertign bit value to angle
 myservo.write(val); //makes servo move to an precise angle
 delay(15);//15ms delay
}