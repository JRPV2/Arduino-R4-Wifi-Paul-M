/*
This is the homework set in episode 49 of Paul McWhorter's course on the Arduino Uno R4 Wifi.
the brief (including the "extra credit") is to have four buttons that make the stepper motor move the following amounts:
+1°, +10°, -1°, and +10°.
*/

#include <Stepper.h>
int STEPS = 2038;
int rpm = 15;
Stepper stepper(STEPS, 2, 3, 4, 5);
int pins[4] = {8, 9, 11, 12}; // pos10°, pos1°, neg1°, & neg10°.
int butVal[4] = {1, 1, 1, 1};
int butValOld[4] = {1, 1, 1, 1};


void setup() {
  // put your setup code here, to run once:
  for(int i = 8; i < 13 && i != 10; i++){
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.setSpeed(rpm);
  for(int i = 0; i < 4; i++){
    butVal[i] = digitalRead(pins[i]);
    if(butValOld[i] == 1 && butVal[i] == 0){
      rotate(i);
    }
    butValOld[i] = butVal[i];
    delay(5);
  }
  Serial.println("");
}

void rotate(int i){
  int rotAngle[4] = {10, 1, -1, -10};
  stepper.step(rotAngle[i]*STEPS/360);
  delay(5);
}