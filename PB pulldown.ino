/* PB pull down
serves to prevent having a floting pin
which can lead to noise. Pull down forces 
to read 5V or 0V
Controlling digital input
*/

int pushButton = 13; //pin 13 is PB
void setup(){
pinMode(pushButton, INPUT); //set PB as INPUT
//initialize communication with serial monitor
Serial.begin(9600);
}

void loop()
{
  int ButtonState = digitalRead(pushButton); //read input
  Serial.println (ButtonState);
}