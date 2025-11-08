//LED blink function
//declaring led pin is pin 13
const int LED_PIN = 13;
//defintion, makes LED link with the parameters of time and delayMs
void blinkLED(int times, int delayMs) {
  //for loop when i is lower than times which is indicated in void loop i becomes 1 till it finishes line 20, then proceeds with line 22
  for(int i = 0; i < times; i++){
    digitalWrite(LED_PIN, HIGH); //turn ON LED pin
    delay(delayMs); //delay it by amount stated in line 20 or 22
    digitalWrite(LED_PIN, LOW); //turn OFF LED pin
    delay(delayMs); //delay it by amount stated in line 20 or 22
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT); //set led pin to output 
}

void loop() {
  blinkLED(3, 300); //blinks LED 3 times with 300ms delay in between
  delay(1000); 
  blinkLED(5, 150); //blinks LED 5 times with 159ms delay in between
  delay(1500);
}
