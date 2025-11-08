/*
 * Q03 - Temperature Alert (simulated)
 * Concepts: if/else if/else, functions, random()
 * Task: Implement void checkTemp(int t) that prints Cold (<20), Normal (20-30), Hot (>30).
 */
 //decision making using if else
void checkTemp(int t) {
  //if value of t coming from line 24 is <20 print out "Cold"
  if (t < 20) {                   
    Serial.println("Cold"); 
    //if value of t coming from line 24 is <=30 print out "Normal"     
  } else if (t <= 30) {           
    Serial.println("Normal"); 
    //if value of t coming from line 24 is is other 0-30 than print out "Hot"
  } else {
    Serial.println("Hot");
  }
}


void setup() {
  //communicate with serial monitor
  Serial.begin(9600);
  randomSeed(analogRead(A0)); // simple seed 
}

void loop() {
  //giving random values to t continuously
  int t = random(15, 40);
  //print Temp: val C->
  Serial.print("Temp: "); Serial.print(t); Serial.print(" C -> ");
  
  checkTemp(t);
  delay(1000);
}
