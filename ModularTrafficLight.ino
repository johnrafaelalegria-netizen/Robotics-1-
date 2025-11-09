/*
 * Q10 - Modular Traffic Light
 * Concepts: functions, sequencing, delays
 * Wire: Red=8, Yellow=9, Green=10 (each with resistor)
 * Task: Implement redLight(), yellowLight(), greenLight() and cycle them.
 */
 //declaring const values
const int RED_PIN = 8;
const int YEL_PIN = 9;
const int GRN_PIN = 10;

void allOff(){
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YEL_PIN, LOW);
  digitalWrite(GRN_PIN, LOW);
}
//define redlight ON for 2s
void redLight() {
  digitalWrite(RED_PIN, HIGH);
  delay(2000);
  digitalWrite(RED_PIN, LOW);
}
//define yellowlight ON for 2s
void yellowLight() {
  digitalWrite(YEL_PIN,HIGH);
  delay(1000);
  digitalWrite(YEL_PIN,LOW);
}
//define greenlight ON for 2s
void greenLight() {
   digitalWrite(GRN_PIN, HIGH);
   delay(2000);
   digitalWrite(GRN_PIN, LOW);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YEL_PIN, OUTPUT);
  pinMode(GRN_PIN, OUTPUT);
  allOff();
}
//calls all the definitions from above
void loop() {
  redLight();
  yellowLight();
  greenLight();
}