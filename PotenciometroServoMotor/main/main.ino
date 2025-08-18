#include <Servo.h>

Servo meuServo;       // Cria objeto do servo
int pinoPot = A0;     // Potenciômetro no A0
int valorPot;         // Guarda leitura do pot
int angulo;           // Ângulo para o servo

void setup() {
  meuServo.attach(9); // Servo conectado no pino 9
  Serial.begin(9600);
}

void loop() {
  // Lê valor do potenciômetro (0 a 1023)
  valorPot = analogRead(pinoPot);

  // Converte para ângulo (0 a 180 graus)
  angulo = map(valorPot, 0, 1023, 0, 180);

  // Move servo para o ângulo
  meuServo.write(angulo);

  // Mostra valores no monitor serial
  Serial.print("Pot: ");
  Serial.print(valorPot);
  Serial.print(" | Angulo: ");
  Serial.println(angulo);

  delay(15); // tempo para o servo se mover suavemente
}
