#include "Arduino.h"
#include "ClubPlayCode.h"

// Implementamos la clase Motor
Motor::Motor(int pin1, int pin2, int enablePin) {
  _pin1 = pin1;
  _pin2 = pin2;
  _enablePin = enablePin;
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, OUTPUT);
  pinMode(_enablePin, OUTPUT);
}

void Motor::adelante(int Velocidad) {
  digitalWrite(_pin1, HIGH);
  digitalWrite(_pin2, LOW);
  analogWrite(_enablePin, Velocidad);
}

void Motor::atras(int Velocidad) {
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, HIGH);
  analogWrite(_enablePin, Velocidad);
}

void Motor::detener() {
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);
  analogWrite(_enablePin, 0);
}

// Implementamos la clase Ultrasonico
Ultrasonico::Ultrasonico(int trigPin, int echoPin) {
  _trigPin = trigPin;
  _echoPin = echoPin;
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

long Ultrasonico::medirDistancia() {
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

  long duration = pulseIn(_echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Velocidad del sonido en el aire: 343 m/s
  return distance;
}