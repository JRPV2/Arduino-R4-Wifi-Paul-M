/*
This is the homework from episode 33 of Paul McWhorter's course on the Arduino Uno R4 Wifi.
The brief was to indicate the brightness detected by the photoresistor and display the information contained in the
voltage that is present when the photoresistor forms part of a voltage divider with a 10kOhm resistor connected between a 5V rail and GND.

I chose to have a servo angle represent this. The full scale deflection is 180°. The servo used is the SG90 micro servo as this course of lessons
uses the Sunfounder Elite Explorer kit and the servo comes supplied. Datasheet: http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf
I will also have the built in LED matrix of the R4 Wifi display the voltage measured at the analog pin to 2 d.p.
https://www.hackster.io/Klausj/three-digit-number-on-uno-r4-wifi-led-matrix-fe74cd
*/

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include "WifiMatrix3dig.h" // Manually place this in the same directory as this INO file.

#include <Servo.h>


// Global variables:
  // Servo:
int servoPin = 3;
int dt = 20;
Servo myServo;

  // Photoresistor:
int photoPin = A0;
int V;
int DT = 200;

  // Matrix:
ArduinoLEDMatrix matrix;
byte myframe[8][12]; // Don't call this 'frame' as there is a variable 'frame' in the WifiMatrix3dig.h library.

void setup() {
  // put your setup code here, to run once:
  pinMode(photoPin, INPUT);
  myServo.attach(servoPin);
  matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //myServo.write(180);
  V = analogRead(photoPin);
  show3dig(matrix, 500.*V/1023);
  myServo.write(180 - 180.*V/1023);
  delay(DT);
}
