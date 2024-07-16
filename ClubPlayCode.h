#ifndef ClubPlayCode_h
#define ClubPlayCode_h

#include "Arduino.h"

// Motor Class
class Motor {
  public:
    Motor(int pin1, int pin2, int enablePin);
    void adelante(int Velocidad);
    void atras(int Velocidad);
    void detener();
  private:
    int _pin1;
    int _pin2;
    int _enablePin;
};

// Ultrasonic Class
class Ultrasonico {
  public:
    Ultrasonico(int trigPin, int echoPin);
    long medirDistancia();
  private:
    int _trigPin;
    int _echoPin;
};

#endif