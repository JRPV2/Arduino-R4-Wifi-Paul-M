/*
This program is the homework assignment from episode 53 of Paul McWhorter's course on the Arduino Uno R4 Wifi.
The brief is to have the HC-SR04 ultrasonic sensor triggered by a toggle button, and the distance calculated (in metres)
displayed on the SSD1306 OLED display. All components supplied in the Sunfounder Elite Explorer kit. 
*/

// Libraries:
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Global variables:

int screenWidth = 128;
int screenHeight = 64;
int oledReset = -1;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);

int butVal = 1, butValOld = 1;
int butPin = 13;
int echoPin = 11;
int trigPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(butPin, INPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  oled.clearDisplay(); // This does not clear the display, it clears the buffer.
  oled.display(); // This displays the contents of the buffer. These two lines reset the display after a reading.
  if(butVal == 0 && butValOld == 1){
    displayReading();
  }
  butValOld = butVal;
  delay(5);
}

float ping(int trigP, int echoP){
  digitalWrite(trigP, LOW);
  delayMicroseconds(2);
  digitalWrite(trigP, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP, LOW);
  return pulseIn(echoP, HIGH)*343./2000000;// 343./2000000 is the conversion to metres from MicroSeconds.
}

void displayReading(){
  oled.clearDisplay(); // This does not clear the display, it clears the buffer.
  oled.display(); // This displays the contents of the buffer.
  oled.setCursor(30,23);
  oled.setTextColor(WHITE);
  oled.setTextSize(3);
  oled.print(String(ping(trigPin, echoPin)));
  oled.display();
  delay(3000);
}






