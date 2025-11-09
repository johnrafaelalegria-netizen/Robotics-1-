/*
 * Q05 - Maximum in Array
 * Concepts: arrays, iteration, return values
 * Task: Implement int findMax(int arr[], int size) and print the max.
 */
 /*Setting parameters int arr[] holds all the values of array in line 17
 while int size holds how many values are there (10)*/
int findMax(int arr[], int size) {
  /*set max to first value (5)*/
  int max = arr[0];
  /*start looping starting from 2nd value (12)
  because we know the first value (5)*/
  for (int i = 1; i < size; i++){ 
    /*checks if the following number is bigger than current max.
    if yes, we take that number and set it as our current max*/
    if (arr[i] > max){
      max = arr[i];
    }
  }
  return max; //return max
}
//declare value of arrays
int dataArr[10] = {5, 12, 7, 19, 3, 22, 8, 14, 2, 11};

void setup() {
  //communicate with serial monitor
  Serial.begin(9600);
  /*calling function from line 8 and printing it out*/
  int m = findMax(dataArr, 10);
  Serial.print("Max = "); Serial.println(m);
}

void loop() {}