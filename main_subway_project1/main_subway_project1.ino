// C++ code
//
#include <Servo.h>

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_2;

Servo servo_8;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  servo_2.attach(2, 500, 2500);
  pinMode(9, OUTPUT);
  servo_8.attach(8, 500, 2500);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(4, 4) < 100) {
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    servo_2.write(0);
  } else {
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    servo_2.write(90);
  }
  if (0.01723 * readUltrasonicDistance(7, 7) < 100) {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    servo_8.write(0);
  } else {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    servo_8.write(90);
  }
  delay(10); // Delay a little bit to improve simulation performance
}