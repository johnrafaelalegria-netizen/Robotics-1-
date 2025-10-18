/*Light Chaser Program 1
controlling output*/

int x = 100;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT) ;
  pinMode(8,OUTPUT) ;
  pinMode(7,OUTPUT) ;
}

// the loop function runs over and over again forever
void loop() {
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
  delay(x); 
}
