/* 
  Ohmeter with Arduino displayed on LCD
  - Uses a voltage divider circuit to calculate resistance
*/
#include <LiquidCrystal.h>

// Initialize the library with the LCD interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Custom character for the Omega (Ohm) symbol
byte Ohm[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01010,
  0b11011,
  0b00000
};

// --- Define your circuit constants ---
const int SENSOR_PIN = A0; //set Ohmeter pin as A0

// This is the value of your KNOWN resistor in Ohms.
// For best accuracy, measure this resistor with a multimeter first.
// A 10k Ohm (10000.0) resistor is a good general-purpose choice.
const float R_KNOWN = 10000.0; //stating known resistor

void setup() {
  // Set up the LCD's number of columns and rows:

    lcd.begin(16, 2);
  // Create the custom Omega character
  lcd.createChar(0, Ohm);
  // Print a static message to the top line
  lcd.setCursor(0, 0);
  lcd.print("Resistance =");
  Serial.begin(9600);
}


void loop() {
  // --- Averaging Start ---
  int totalSensorValue = 0; //sets totalsensorValue as 0
  int numReadings = 20; // Number of samples to average
  //repeats the cycle of reading samples till 20 is acheived then restarts
  for (int i = 0; i < numReadings; i++) {
    totalSensorValue = totalSensorValue + analogRead(SENSOR_PIN);
    delay(1); // Small delay between readings
  }
  
  int sensorValue = totalSensorValue / numReadings; // Get the average
  // --- Averaging End ---

  // Variable to hold the calculated resistance
  float resistance_ohms; //states resistance as float to get decimals

  if (sensorValue == 1023) {
    lcd.setCursor(0, 1); //prints on bottom line
    lcd.print("Open Circuit    "); //if 5V sensor Value = 5V then it prints Open circuit
  }
  else {
    // Calculate resistance using the average value
    resistance_ohms = R_KNOWN * (sensorValue / (1023.0 - sensorValue)); //calculating for R_UNKNOWN

    lcd.setCursor(0, 1); //print resistance value to bottom line
    lcd.print(resistance_ohms);
    lcd.write(byte(0)); //prints omega symbol        
    lcd.print("      ");//clears old data
  } 
Serial.print("Resistance = "); //serial monitor for troubleshoot
Serial.println(resistance_ohms);
  delay(500); // Wait before the next averaged reading
}
