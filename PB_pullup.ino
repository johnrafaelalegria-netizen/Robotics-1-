/* PB input pull up
PB pull up uses internal resistor 
instead of having an external one
Controlling digital input
*/

int pushButton = 13; //pin 13 is PB
void setup(){
pinMode(pushButton, INPUT_PULLUP); //set PB as INPUT
//initialize communication with serial monitor
Serial.begin(9600);
}

void loop()
{
  int ButtonState = digitalRead(pushButton); //read input
  Serial.println (ButtonState);
}
