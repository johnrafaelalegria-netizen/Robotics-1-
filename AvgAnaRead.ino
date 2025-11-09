/*
 * Q07 - Average Sensor Readings
 * Concepts: arrays, loops, arithmetic, return float
 * Wire: Potentiometer or sensor on A0 (or leave floating for testing)
 * Task: Read 5 analog values, store in array, implement float getAverage(int arr[], int size).
 */

 /*loop gets average from arr[] which
 represents the reading from analogRead(A0)
 size represents how many values we are taking (5)*/
float getAverage(int arr[], int size) {
int sum = 0; //keeps track of values strating from 0

/*starts a loop checking values in position 0 all the way to five*/
  for(int i = 0;i < size; i++){
    /*adds the new value to the sum repeats
    this 5 times*/ 
   sum += arr[i];
  }
  return (float) sum/size;//divides the sum by 5 using float to see decimals
}

void setup() {
  //communicate with the serial monitor
  Serial.begin(9600);
  /*creates an empty array to contain 5 sensor readings*/
  int readings[5];
  /*loops 5 times, every cycle takes a new 
  value*/
  for (int i=0;i<5;i++) {
    /*stating that readings[i]
    represents analogRead(A0)*/
    readings[i] = analogRead(A0); 
    delay(10);
  }
  /*calls get average to execute average formula
  on the 5 first values it took*/
  float avg = getAverage(readings, 5);
  //prints outu average = val
  Serial.print("Average = "); Serial.println(avg);
}

void loop() {}