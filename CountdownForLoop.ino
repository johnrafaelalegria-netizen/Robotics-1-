/*
 * Q06 - Countdown Function
 * Concepts: for loop, functions
 * Task: Implement void countdown(int start) to print start..0 and then "Liftoff!".
 */

 /*declares new function called countdown
 start represents how many seconds we want
 the countdown to be example in line 20 */
void countdown(int start) { 
  /*Creates a loop where it takes the time
  written down in countdown(val) and
  substracting 1 every second*/
  for (int i = start; i >=0; i--){
    /*prints the substracted value (i)
    every second*/ 
    Serial.println(i); 
    delay(1000); //delays a second
  }
Serial.println("Liftoff!"); //prints Liftoff! in serial monitor
}

void setup() {
  Serial.begin(9600);//communicate with serial monitor
  countdown(10); //count down of 10 seconds
}

void loop() {}

