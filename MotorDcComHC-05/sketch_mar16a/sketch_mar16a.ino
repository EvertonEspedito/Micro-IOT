#include <SoftwareSerial.h>

// Configuração do Bluetooth (RX no 10, TX no 11)
SoftwareSerial bluetooth(10, 11); 

// Pinos do Motor
int ENA = 3;  // Velocidade (PWM)
int IN1 = 4;  // Sentido 1
int IN2 = 5;  // Sentido 2

void setup() {
  // Inicializa Comunicação
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  // Configura Pinos do Motor
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.println("Sistema Pronto!");
}

void loop() {
  // Verifica se chegou algo pelo Bluetooth ou Serial
  if (bluetooth.available() || Serial.available()) {
    char c;
    
    // Lê de onde vier o dado
    if (bluetooth.available()) c = bluetooth.read();
    else c = Serial.read();

    // Se o comando for 'F', executa Função Frente
    if (c == 'F') {
      frente();
    }

  }
}

// Função Frente
void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  // Sequência de velocidades
  analogWrite(ENA, 100);
}