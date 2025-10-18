/* Light Chaser Program
Turns on LED each LED one at a time. 
Making it look like they are following each other,
going back and forth.
Controlling digital output.
*/
void setup(){
 pinMode(13,OUTPUT); //set all pins to output 
 pinMode(12,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
}
int x = 100; //delay=100ms
void loop()
{
  digitalWrite(13, 1);  // Only pin13 is ON other LED are off
  digitalWrite(12, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  delay(x);             // wait for a second         
  digitalWrite(13, 0);  // Only pin12 is ON other LED are off
  digitalWrite(12, 1);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  delay(x);             // wait for a second
  digitalWrite(13, 0);  // Only pin8 is ON other LED are off
  digitalWrite(12, 0);
  digitalWrite(8,1);
  digitalWrite(7, 0);
  delay(x);             // wait for a second
  digitalWrite(13, 0);  //Only pin7 is ON other LED are off
  digitalWrite(12, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 1);
  delay(x);             // wait for a second
  digitalWrite(13, 0);  // Only pin8 is ON other LED are off
  digitalWrite(12, 0);
  digitalWrite(8, 1);
  digitalWrite(7, 0);
  delay(x);             // wait for a second
  digitalWrite(13, 0);  // Only pin12 is ON other LED are off
  digitalWrite(12, 1);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  delay(x);             // wait for a second
   digitalWrite(13, 1); //Only pin13 is ON other LED are off
  digitalWrite(12, 0);
  digitalWrite(8,0);
  digitalWrite(7, 0);
  delay(x);             // wait for a second 
}
