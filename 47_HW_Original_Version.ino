/*
This is the homework set in lesson 47 of Paul McWhorter's course on the Arduino Uno R4 Wifi.
The brief was to have the speed of a DC motor controlled by the voltage output of a potentiometer (bothe components from the
Sunfounder Elite Explorer kit). Paul's brief involved having the motor off when the potentiomter was fully turned anticlockwise
and fully on in one direction when the potentiometer was fully clockwise. The direction is controlled by a toggle switch that
also stopped the motor briefly before the direction is switched so as not to result in large angular acceleration.
*/

int butPin = 2;
int potPin = A0;
int BI = 10;
int FI = 9;
int butVal = 1;
int butValOld = 1;
int V;

void setup() {
  // put your setup code here, to run once:
  pinMode(butPin, INPUT);
  pinMode(BI, OUTPUT);
  pinMode(FI, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  V = analogRead(potPin);
  butVal = digitalRead(butPin);
  analogWrite(FI, V*255/1023);
  if(butValOld == 1 && butVal == 0){
    analogWrite(BI, 0);
    analogWrite(FI, 0);
    delay(750);
    int tmp = FI;
    FI = BI;
    BI = tmp;
    analogWrite(FI, V*255/1023);
    delay(20);
  }
  butValOld = butVal;
}