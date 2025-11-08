/*
 * Q01 - Even or Odd
 * Concepts: if/else, functions, Serial I/O
 * Task: Implement bool isEven(int n) and print "Even"/"Odd" for a user-entered number.
 */
 
// the % checks the remainders after divinding the given number by 2 if theres a remainder its an odd number
bool isEven(int n) {
  // TODO: return true if n is even, false otherwise
  return n % 2 == 0;// the % checks the remainders after divinding the given number by 2 if theres a remainder its an odd number
}

void setup() {
  //communicate with serial monitor
  Serial.begin(9600);
  //in loop till successful connection wth serial monitor
  while(!Serial) {}
  //print "Enter an integer:" in serial monitor
  Serial.println("Enter an integer:");
}

void loop() {
  //sets value to false just once instead of resetting every single time
  static bool done = false;

  if (!done && Serial.available()) { //verifies if a number has been entered once true stops reading other numbers entered
    long n = Serial.parseInt();  // reads whole number typed in
    if (isEven(n)) Serial.println("Even"); else Serial.println("Odd"); //calls n % 2 == 0 function to verify i its odd or even and prints even or odd depending on if theres a remainder or not
    done = true; // prevent repeating
  }
}
