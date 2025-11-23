/*DHT11 Celsius and Humidity*/

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

#define DHTPIN 7     // Digital pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT11     // DHT 11 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte degrees[8] = { //degrees
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
};

byte celsius[8] = { //celsius
  B00000,
  B00000,
  B01110,
  B10001,
  B10000,
  B10000,
  B10001,
  B01110
};

byte percentage[8] = { //percentage
  B11001,
  B11010,
  B00010,
  B00100,
  B00100,
  B01000,
  B01011,
  B10011
};

void setup() {
  //initalize LCD and set up the number of columns and rows
  lcd.begin(16, 2);

  //create new character (degrees)
  lcd.createChar(0, degrees);
  //create new character (celsius)
  lcd.createChar(1, celsius);
  //create new character (percentage)
  lcd.createChar(2, percentage);
  
  // set cursor to top left
  lcd.setCursor(0,0);
  lcd.print("Temp: ");//print "temp" in first line
  // set cursor to bottom left
  lcd.setCursor(0,1);
  lcd.print("Humidity: "); //print "Humidity" in first line

  
  Serial.begin(9600);
  
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    lcd.setCursor(0,0); // set cursor top line
    lcd.print("Temp:"); //print "Temp:" in top line
    lcd.print(event.temperature); //print temp value after "Temp:"
    lcd.write(byte(0)); //print degrees symbol
    lcd.write(byte(1)); //print Celsius (C)
    lcd.print(""); //clear data and refresh
    //print in serial monitor
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    lcd.setCursor(0,1); // set cursor top line bottom line
    lcd.print("Humidity:"); //print "humidity" in bottom line
    lcd.print(event.relative_humidity); //print humidity value after "humidity:"
    lcd.write(byte(2)); //print %
    lcd.print(""); //clear data and refresh
    //print serial monitor
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
