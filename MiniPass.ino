/*
 * Q09 - Mini Password Lock
 * Concepts: arrays, loops, Serial I/O, bool return
 * Task: Store correct 4-digit code in an array. Read 4 digits from Serial and compare.
 */
 
 //declare array values for the correct code
int correct[4] = {1, 2, 3, 4};

/*compares enterd code with the correct code*/
bool checkPassword(int entered[], int size) {
  /*checking the value of each indexe position*/
  for (int i = 0; i < size;i++){
    /*compares checked values with correct code
    if entered code is wrong (!=) makes the if statement true
    and returns false*/
    if (entered[i] != correct[i]){
      return false;
    }
  }
  /*if the entered code is correct
  returns true*/
 return true;
}

void setup() {
  //communicate with serial monitor
  Serial.begin(9600);
  //makes sure serial monitor is connected
  while(!Serial) {}
  Serial.println("Enter 4 digits separated by spaces, then press Enter:");
}

void loop() {
  //checks if password has been checked
  static bool done = false;
  //makes it only run once
  if (!done && Serial.available()) {
    int entered[4]; //attempted code
    for (int i=0;i<4;i++) entered[i] = Serial.parseInt(); //reads the 4 numbers and sends it to an array
    if (checkPassword(entered, 4)) Serial.println("ACCESS GRANTED"); //if attempted code is correct than access is granted
    else Serial.println("ACCESS DENIED"); //if code is wrong access denied
    done = true;//checks only once and stops checking
  }
}