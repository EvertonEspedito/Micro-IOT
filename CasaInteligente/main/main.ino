#define BLYNK_TEMPLATE_ID "TMPL2fQ7ZAK6n"
#define BLYNK_TEMPLATE_NAME "Casa Inteligente"
#define BLYNK_AUTH_TOKEN "c7_2w23dZwytkeIjEzAKillf4xZE-zBA"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Credenciais Wi-Fi
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "F-IFSertao-PE-ALUNOS";
char pass[] = "#ifsertao@aluno#";

// Pinos dos LEDs
int ledSala   = D1;   // Sala
int ledCorr   = D2;   // Corredor
int ledSegAnd = D3;   // 2º andar
int ledVar    = D4;   // Varanda
int ledPriAnd = D5;   // 1º andar
int ledPriVar = D6;   // 1ª varanda

// --- Controle via Botões Virtuais do Blynk ---
// Cada função é chamada quando o botão correspondente muda no app

BLYNK_WRITE(V0) {   // Botão da Sala
  int valor = param.asInt();
  digitalWrite(ledSala, valor);
}

BLYNK_WRITE(V1) {   // Botão do Corredor
  int valor = param.asInt();
  digitalWrite(ledCorr, valor);
}

BLYNK_WRITE(V2) {   // Botão do 2º Andar
  int valor = param.asInt();
  digitalWrite(ledSegAnd, valor);
}

BLYNK_WRITE(V3) {   // Botão da Varanda
  int valor = param.asInt();
  digitalWrite(ledVar, valor);
}

BLYNK_WRITE(V4) {   // Botão do 1º Andar
  int valor = param.asInt();
  digitalWrite(ledPriAnd, valor);
}

BLYNK_WRITE(V5) {   // Botão da 1ª Varanda
  int valor = param.asInt();
  digitalWrite(ledPriVar, valor);
}

void setup() {
  Serial.begin(9600);

  // Configura os pinos como saída
  pinMode(ledSala, OUTPUT);
  pinMode(ledCorr, OUTPUT);
  pinMode(ledSegAnd, OUTPUT);
  pinMode(ledVar, OUTPUT);
  pinMode(ledPriAnd, OUTPUT);
  pinMode(ledPriVar, OUTPUT);

  // Conecta ao Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
