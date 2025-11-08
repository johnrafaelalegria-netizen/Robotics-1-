/*
 * Q04 - LED Pattern Using Array
 * Concepts: arrays, for loops, functions
 * Wire: LEDs + resistors on pins 2,3,4,5
 * Task: Fill ledChase() to turn each LED on then off with 300 ms delay.
 */
//declaring value of array pins
const int LEDS[] = {2,3,4,5}; 
/*N represents the division between total size of bytes used by all 4 pins 
and how much bytes is used by one element (pin), calculating 
the total of pins/elements (4pins)*/
const int N = sizeof(LEDS)/sizeof(LEDS[0]); 

void ledChase() {
  /*for loop to blink LEDs in a loop
  by statign i=0, this continues a cycle of +1 till it reaches 4 
  and resets till LEDs blink*/
  for (int i = 0; i < N; i++) {
    digitalWrite(LEDS[i], HIGH); //LED turns ON
    delay(300); //300ms delay
    digitalWrite(LEDS[i],LOW); //LED turns OFF
 }
}

void setup() {
  //for loop settign each pin from the array to OUTPUT
  for (int i=0;i<N;i++) pinMode(LEDS[i], OUTPUT); 
}

void loop() {
  ledChase(); //calls definition from line 18 to blink LEDs
}
