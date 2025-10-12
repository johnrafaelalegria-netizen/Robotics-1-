/* PB controlled RGB
RGB is white when PB not pressed,
RGB is OFF when PB is pressed
Controlling output with input component
*/

int pushButton = 8; //pin 8 is PB
void setup(){
//initialize communication with serial monitor
  Serial.begin(9600);
  pinMode (2,OUTPUT); //responsible for RED
  pinMode (4,OUTPUT); //responsible BLUE
  pinMode (12,OUTPUT); //responsible for GREEN
  pinMode (pushButton,INPUT_PULLUP); //PB is input_pullup
}

void loop()
{
  int buttonState = digitalRead(pushButton);//read PB
  //print out state of PB
  Serial.print("buttonState = ");
  Serial.print("\t") ;
  Serial.println(buttonState); 
  digitalWrite(12,buttonState); //pin for GREEN
  digitalWrite(4,buttonState);  //pin for BLUE
  digitalWrite(2,buttonState);  //pin for RED
  delay(1); //delay for read stability
}