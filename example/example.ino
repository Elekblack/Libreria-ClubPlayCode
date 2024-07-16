#include <ClubPlayCode.h>

// Definimos los pines para los motores.
Motor motor1(2, 3, 4);
Motor motor2(7, 8, 9);

// Definimos los pines para el sensor ultrasonico.
Ultrasonico ultrasonico(12, 13);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Prueba de motores
  //avanzar hacia adelante por 2 segundos a velocidad 200
  motor1.adelante(200);
  motor2.adelante(200);
  delay(2000);
  //retroceder por 2 segundos a velocidad 200
  motor1.atras(200);
  motor2.atras(200);
  delay(2000);
  //detenerse durante 1 segundo a velocidad 200
  motor1.detener();
  motor2.detener();
  delay(1000);
  //girar hacia la derecha por 2 segundos a velocidad 200
  motor1.adelante(200);
  motor2.atras(200);
  delay(2000);
  //girar hacia la izquierda por 2 segundos a velocidad 200
  motor1.atras(200);
  motor2.adelante(200);
  delay(2000);
  

  // Prueba de sensor ultrasonico
  long distancia = ultrasonico.medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(1000);
}