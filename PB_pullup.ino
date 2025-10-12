/*PB pullup
when PB not pressed its RED+YELLOW
when PB presed its BLUE+RED
Controlling output with input component
*/

int pushButton = 2; //pin 2 is PB
void setup(){
//initialize communication with serial monitor
  Serial.begin(9600);
  pinMode(pushButton,INPUT); //PB is set as input

}

void loop()
{
  int buttonState = digitalRead(pushButton); //read PB value
  Serial.println(buttonState); //print PB value
}