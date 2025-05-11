/*
This program is the homework set in lesson 31 of Paul McWhorter's course on the Arduino Uno R4 Wifi.
The breif is to have the string of text display across to built in LED matrix of the R4 and to have this
happen only when a button is pushed.
*/

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include <DHT.h>             // Find out more about these...
#define DHTPIN 3             //
#define DHTTYPE DHT11        //
DHT mydht(DHTPIN, DHTTYPE);  // DHT is the method we are calling mydht is the object name (can be whatever you choose).

//Global variables:
int butPin = 2;
int setupDelay = 1000;
String failMess = "Failed to read data from DHT11 Temp or Hum is nan";
String message;
ArduinoLEDMatrix matrix;

float tempC;
int hum;
float HIC; // Heat index in Centigrade.

void setup() {
  // put your setup code here, to run once:
  pinMode(butPin, INPUT_PULLUP);
  matrix.begin();
  mydht.begin();
  delay(setupDelay);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(butPin) == 0){
    tempC = mydht.readTemperature(false); // False means NOT in farenheight (i.e. in centigrade). Hence true would be in farenheight.
    hum = mydht.readHumidity();
    HIC = mydht.computeHeatIndex(tempC, hum, false);
    if(isnan(tempC) || isnan(hum) || isnan(HIC)){ //This checks that tempC and hum are numbers (i.e. niether of them has been assigned a value of nan, Not A Number).
      Serial.println(failMess);
      return; // This stops the loop from prgressing with a nan value(s) that would cause a crash.
    }
    message = "Temperature is " + String(tempC) + "ºC. Humidity is " + String(hum) + "%. Heat index is " + String(HIC) + "ºC.";
    matrix.beginDraw();
    matrix.textScrollSpeed(65);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 255, 0, 0);
    matrix.println(message);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
    return;
  }
}
  


















