// C++ code
/* Blink
Turns an LED on for one second, then off for one second, 
repeatedly.
Controlling digital output
*/
void setup(){
 pinMode(13,OUTPUT); //set pin13 to output
}
int x = 100; //delay=100ms
void loop()
{ 
digitalWrite (13,1); //LED ON
delay(x);  //wait 100ms
digitalWrite (13,0); //LED OFF
delay(x);  //wait 100ms
}