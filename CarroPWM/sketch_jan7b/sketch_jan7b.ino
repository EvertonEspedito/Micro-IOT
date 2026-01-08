// ==========================
// DEFINIÇÃO DOS PINOS
// ==========================
int ENA = 5;   // PWM Motor A
int IN1 = 6;
int IN2 = 7;

int ENB = 9;   // PWM Motor B
int IN3 = 10;
int IN4 = 11;

// Velocidade padrão (0 a 255)
int velocidade = 250;

// ==========================
// SETUP
// ==========================
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  parar(); // segurança
}

// ==========================
// FUNÇÕES DE MOVIMENTO
// ==========================

// Andar para frente
void frente() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Andar para trás
void tras() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Virar à esquerda
void esquerda() {
  analogWrite(ENA, velocidade / 2);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Virar à direita
void direita() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade / 2);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Parar o robô
void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ==========================
// LOOP – SEQUÊNCIA DE TESTE
// ==========================
void loop() {

  delay(4000);
  // Frente
  frente();
  delay(3000);

  // Parar
  parar();
  delay(1000);

  // Trás
  tras();
  delay(3000);

  // Parar
  parar();
  delay(1000);

  // Virar à esquerda
  esquerda();
  delay(2000);

  // Parar
  parar();
  delay(1000);

  // Virar à direita
  direita();
  delay(2000);

  // Parar
  parar();
  delay(3000);
}
