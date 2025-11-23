/*Displaying distance of sensor to LCD display*/

// include the library code:
#include <LiquidCrystal.h>
#define trigPin 10
#define echoPin 13
float duration, distance;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Distance");
}

void loop() {
  //process of sending ultrasonic pulses
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  //measure the response from echoPin
  duration = pulseIn(echoPin,HIGH);

  //determine distance from duration
  //use 343 meters pers econd as speed of sound

  distance = (duration / 2) * 0.0343;
  //send results to Serial Monitor

  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2){
    Serial.println("Out of Range");}

  else {
    Serial.print(distance);
  Serial.println(" cm");
  delay(500);
  }
  delay (500);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(distance);
  lcd.print("cm");
  }


