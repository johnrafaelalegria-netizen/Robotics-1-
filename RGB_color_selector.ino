/*Rgb color selector
Controlling outputs*/
// C++ code
//
void setup()
{
  pinMode(11, OUTPUT); //green pin
  pinMode(10,OUTPUT); //blue pin
  pinMode(9,OUTPUT); //red pin
}

void loop()
{//color selector
  analogWrite(11,106);  //green pin
  analogWrite(10,228); //blue pin
  analogWrite(9,35); //red pin
}
