/*
This is the homework set in lesson 36 of Paul McWhorter's course on the Arduino Uno R4 Wifi.
Once the brief for lesson 35 was fulfilled, the brief for this homework was to sort the grades in descending order.
I have chosen to use a sorting method which involves find out how many grades are higher than each grade.
I.e. zero grades are higher than the highest, hence this goes in position 0 in the sorted array, numGrades - 1 grades are higher
than the lowest grade so this goes in position numGrades - 1 (the last position).
The sorting will be performed once all the grades have been entered.
Perhaps an upgrade to this would be to build a quicksort algorithm.
*/

// Global variables
int baud = 9600;
String promptStart = "How many grades do you have?";
String promptGrades = "Please enter grade number ";
String gradesResult = "The grades are:";
String desGradesResult = "The grades in descending order are:";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baud);
}

void loop() {
  // put your main code here, to run repeatedly:
  float tot = 0, low = 0, high = 0;
  int numGrades;
  Serial.println(promptStart); // "How many grades do you have?""
  while (Serial.available() == 0){

  } 
  numGrades = Serial.parseInt();
  float grades[numGrades];
  float desGrades[numGrades];
  for(int i = 0; i < numGrades; i++){
    Serial.print(promptGrades + String(i + 1) + ": "); // "Please enter grade number "
    while (Serial.available() == 0){
    
    }
    grades[i] = Serial.parseFloat();
    Serial.println(grades[i]);
    tot += grades[i];
    if (i == 0){
      low = grades[i];
      high = grades[i];
    }
    else{
      if(grades[i] > high){
        high = grades[i];
      }
      if(grades[i] < low){
        low = grades[i];
      }
    }
  }
  // Sorting:
  int pos[numGrades];
  for(int i = 0; i < numGrades; i++){
    pos[i] = 0; // Initiallises the pos[] array to all zeros before an element is modified.
    for(int j = 0; j < numGrades; j++){
      if(i != j && grades[j] > grades[i]){
        pos[i]++;
      }
    }
    desGrades[pos[i]] = grades[i];
  } // Sorting complete.
  Serial.println();
  Serial.println(gradesResult); // "The grades are:"
  for(int i = 0; i < numGrades; i++){
    Serial.print("Grade number " + String(i + 1) +": ");
    Serial.println(String(grades[i]));
  }
  Serial.println();
  Serial.println("The average is " + String(tot/numGrades) + ". The highest is " + String(high) + ", and the lowest is " + String(low) + ".");
  Serial.println();
  Serial.println(desGradesResult); // "The grades in descending order are:"
  for(int i = 0; i < numGrades; i++){
    Serial.print("Grade number " + String(i + 1) +": ");
    Serial.println(String(desGrades[i]));
  }
  Serial.println();
}
