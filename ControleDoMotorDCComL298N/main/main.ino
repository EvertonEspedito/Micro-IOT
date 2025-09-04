// Pinos do L298N
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10;   // PWM

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Define o sentido fixo (pra frente)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {
  int velocidade = 200; // 0 a 255 (PWM)
  
  analogWrite(ENA, velocidade); // Define a velocidade do motor
}
