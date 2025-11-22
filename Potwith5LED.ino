/*Potentiometer with 5 LEDS
when rotating potentiometer, LEDS start turning on one by one
controlling output with analog input
*/
int potentiometer = A0;
void setup() {
  // put your setup code here, to run once:
  //set LEDs to out put
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(4,OUTPUT);
 Serial.begin(9600); //communicate with serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
int potentiometerValue = analogRead(potentiometer); //read value of potentiometer
// setting parameters to gradually turn on LEDs
if (potentiometerValue > 150) digitalWrite(13,HIGH);
if (potentiometerValue > 350) digitalWrite(12,HIGH);
if (potentiometerValue > 550) digitalWrite(8,HIGH);
if (potentiometerValue > 700) digitalWrite(7,HIGH);
if (potentiometerValue > 900) digitalWrite(4,HIGH);
if (potentiometerValue < 150) digitalWrite(13,LOW);
if (potentiometerValue < 350) digitalWrite(12,LOW);
if (potentiometerValue < 550) digitalWrite(8,LOW);
if (potentiometerValue < 700) digitalWrite(7,LOW);
if (potentiometerValue < 900) digitalWrite(4,LOW);
Serial.print ("potentiometerValue = "); //print out value of potentiometer
Serial.println(potentiometerValue);
}
