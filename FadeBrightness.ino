/*
 * Q08 - LED Brightness Levels (PWM)
 * Concepts: analogWrite, functions with ranges
 * Wire: LED + resistor on pin 9 (PWM)
 * Task: Implement void fade(int start, int end, int step) to change brightness gradually.
 */
const int PWM_PIN = 9;
/*creates definition called fade which 
consists of 3 parameters, start, end, step
start represents the start value of LED
end represents end value of LED
step is how big of jumps do we wanna go up or down*/
void fade(int start, int end, int step) {

  /*if step is above 0, LED gets brighter*/
  if (step > 0) {
    for (int i = start; i <= end; i += step){
      analogWrite(PWM_PIN, i); //sets LED to current value of i
      delay(50);//how long does it fade
    }
  }
  /*if step is not positive, LED gets dimmer*/
  else {
    for (int i = start; i >= end; i += step){
      analogWrite(PWM_PIN, i);
      delay(50);//how long does it fade
    }
  }
}

void setup() {
  pinMode(PWM_PIN, OUTPUT);//set pin to output
}

void loop() {
  fade(0, 255, 5);   // fade up
  delay(300);
  fade(255, 0, -5);  // fade down
  delay(600);
}

