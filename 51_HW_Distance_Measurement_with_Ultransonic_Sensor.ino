/*
This program is the homework assignment set in episode 51 of Paul McWhorter's course on the Ardunio Uno R4 Wifi.
The brief is to extend the code created during the episode so that the output on the serial monitor gives the distance
measured by the HC-SR04 ultrasonic sensor as opposed to the time in microseconds
*/

// Global Variables:
int echoPin = 3;
int trigPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pingTime;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pingTime = pulseIn(echoPin, HIGH); // pulseIn gives a result in microseconds.
  Serial.println(pingTime*343./2000000); // 343 is the speed of sound in m/s. It is necessary to divide this by 1000000 to convert to metres.
  delay(200);                            // Dividing by two is necessary as the pinTime is for the pulse to travel out to the object, and back to the sensor.
}                                        // There is also a small offset as the emitter and the detector do not lie in the same plane, however this is negligible.