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

void setup()
{
  pinMode(13, OUTPUT);
  servo_2.attach(2, 500, 2500);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(4, 4) < 50) {
    digitalWrite(13, HIGH);
    servo_2.write(90);
  } else {
    digitalWrite(13, LOW);
    servo_2.write(0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}