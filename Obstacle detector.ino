# Obstacle Detector Using Arduino

## Project Overview
This project demonstrates an obstacle detection system using Arduino Uno and an ultrasonic sensor. When an obstacle comes within a specified distance, a buzzer is activated to alert the user.

## Arduino Code
const int trigPin = 6;
const int echoPin = 5;
const int buzzerPin = 2;

long duration;
int distance;
const int safetyDistance = 20; // 20 cm ke andar buzzer bajega

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance <= safetyDistance && distance > 0) {
    digitalWrite(buzzerPin, HIGH); 
  } else {
    digitalWrite(buzzerPin, LOW);  
  }
  delay(100);
}

## Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Buzzer
- Breadboard
- Jumper Wires
- USB Cable

## Project Video
https://youtu.be/UrymY0G8GrU?si=B0PSrwH61UtRX5oV

## Created By
Girish Patil
