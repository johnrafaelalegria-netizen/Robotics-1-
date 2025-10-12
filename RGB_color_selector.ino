/*Color selector
color selector
controlling output with analog input
*/

int potentiometer = A0;
void setup(){
//initialize communication with serial monitor
  Serial.begin(9600);
  pinMode(3,OUTPUT); //pin3 is RED
  pinMode(5,OUTPUT); //pin5 is BLUE
  pinMode(6,OUTPUT); //pin6 is GREEN
  pinMode(A0,INPUT); //pinA0 is potentiometer
  
}

void loop()
{//Read potentiometer
  int colorSelector = analogRead(potentiometer); 
  //print out state of potentiometer
  Serial.print("colorSelector =");
  Serial.print("\t");
  Serial.println(colorSelector);
  
  analogWrite(3,colorSelector); //pin for RED
  analogWrite(5,colorSelector); //pin5 for BLUE
  analogWrite(6,colorSelector); //pin6 for GREEN
  delay(1); //delay for read stability
}