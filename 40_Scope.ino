/*
This code was written whilst taking lessons 38, 39 & 40 of paul McWhorter's course on the Arduino Uno R4 Wifi.
It is designed to familiarise the pupil with global and local scope variables and functions.
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potPin = A0;
  int LEDPin = 3;
  float potV = 0;
  float pinV = 0;
  while(1){
    readV(potPin, potV);
    convertV(potV, pinV);
    VtoLED(LEDPin, pinV);
    delay(5);
  )
}

void readV(int pin, float &potV){
  potV = analogRead(pin);
}

void convertV(float potV, float &pinV){
  pinV = pow(2, (potV/128.)) - 1;
}

void VtoLED(int pin, float V){
  analogWrite(pin, V);
}