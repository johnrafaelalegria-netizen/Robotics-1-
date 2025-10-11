/* Light Chaser Program
Turns on LED each LED one at a time. 
Making it look like they are following each other.
Controlling digital output.
*/
void setup(){
 pinMode(13,OUTPUT); //set pin13 to outpu  pinMode(12,OUTPUT) 
 pinMode(12,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
}
int x = 100; //delay=100ms
void loop()
{
  digitalWrite(13, 1);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  delay(x);          // wait for a second         
  digitalWrite(13, 0);    // turn the LED off by making the voltage LOW
  digitalWrite(12, 1);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  delay(x);             // wait for a second
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(8,1);
  digitalWrite(7, 0);
  delay(x);             // wait for a second
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 1);
  delay(x);             // wait for a second
  digitalWrite(13, 0);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, 0);
  digitalWrite(8, 1);
  digitalWrite(7, 0);
  delay(x);          // wait for a second
  digitalWrite(13, 0);    // turn the LED off by making the voltage LOW
  digitalWrite(12, 1);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  delay(x);             // wait for a second
   digitalWrite(13, 1);
  digitalWrite(12, 0);
  digitalWrite(8,0);
  digitalWrite(7, 0);
  delay(x);             // wait for a second 
}