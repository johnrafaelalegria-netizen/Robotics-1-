/* RGB Chaser Program
Turns on LED each LED one at a time. 
Making it look like they are following each other,
going back and forth.
Controlling digital output.
*/
void setup(){
 pinMode(13,OUTPUT); //set all pins to output 
 pinMode(12,OUTPUT);
 pinMode(8,OUTPUT);
}
int x = 300; //delay=300ms
void loop()
{
  digitalWrite(13, 1);  // GREEN LED ON
  digitalWrite(12, 0);
  digitalWrite(8, 0);
  delay(x);             // wait for 3s         
  digitalWrite(13, 0);  
  digitalWrite(12, 1);  // BLUE LED ON
  digitalWrite(8, 0);
  delay(x);             // wait for 3s
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(8,1);    // RED LED ON
  delay(x);             // wait for 3s
  digitalWrite(13, 1);  // WHITE LED ON
  digitalWrite(12, 1);
  digitalWrite(8, 1);
  delay(x);             // wait for 3s
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(8,1);    //RED LED ON
  delay(x);             // wait for 3s
  digitalWrite(13, 0);  // turn the LED off by making the voltage LOW
  digitalWrite(12, 1);  //BLUE LED ON
  digitalWrite(8, 0);
  delay(x);             // wait for 3s
  digitalWrite(13, 1);  // GREEN LED ON
  digitalWrite(12, 0);
  digitalWrite(8, 0);
  delay(x);             // wait for 3s
}