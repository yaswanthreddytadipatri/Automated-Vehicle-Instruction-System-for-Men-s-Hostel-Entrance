// C++ code
//
#include <Servo.h>

int var = 0;

Servo servo_7;

Servo servo_2;

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

void setup()
{
  servo_7.attach(7, 500, 2500);
  servo_2.attach(2, 500, 2500);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(10, 11) < 50) {
    servo_2.write(0);
    while (0.01723 * readUltrasonicDistance(3, 4) > 50) {
    }
    servo_2.write(90);
  } if (0.01723 * readUltrasonicDistance(8, 9) < 50) {
    servo_7.write(0);
    while (0.01723 * readUltrasonicDistance(5, 6) > 50) {
    }
    servo_7.write(90);
  }
  // servo_7.write(90);
  //delay(10); // Delay a little bit to improve simulation performance
}