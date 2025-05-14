/*
This is the homework set in lesson 35 of Paul McWhorter's course on the Arduino Uno R4 Wifi.
The brief was to have a program ask the user for a number of grades, and have the user input said grades in an array.
These grades were then to be displayed along with the average of the grades, the highest grade, and the lowest grade.
I will derive the average, highest and lowest from first principles as opposed to using inbuilt functions to keep to the spirit of the course.
*/

// Global variables
int baud = 9600;
String promptStart = "How many grades do you have?";
String promptGrades = "Please enter grade number ";
String gradesResult = "The grades are:";

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
  Serial.println();
  Serial.println(gradesResult); // "The grades are:"
  for(int i = 0; i < numGrades; i++){
    Serial.print("Grade number " + String(i + 1) +": ");
    Serial.println(String(grades[i]));
  }
  Serial.println();
  Serial.println("The average is " + String(tot/numGrades) + ". The highest is " + String(high) + ", and the lowest is " + String(low) + ".");
  Serial.println();
  Serial.println();
}
