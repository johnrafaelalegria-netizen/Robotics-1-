/*servo controlled by LDR*/
#include <Servo.h>

Servo myservo; //create servo object to control a servo

int potpin = 0; //analog pin used to connect to joystick
int val; //variable to read the value from analog pin

void setup() {  
  // put your main code here, to run repeatedly:
 myservo.attach(9); //attaches the servo on pin 9 to the servo object
 Serial.begin(9600); //communicate with serial monitor
}



void loop() {
 val = analogRead(potpin); //read value from A0
 int val2 = map(val, 60 , 120, 0, 180); //setting range from 60-120 to 0-180 (60 is when finger over LDR, 120 when class light)
 myservo.write(val);//val takes val from A0 instead of val2 making it immediately 0-180
 delay(15);
 Serial.print("BitValue = ");
 Serial.println(val);
}
