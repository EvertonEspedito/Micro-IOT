#define BLYNK_TEMPLATE_ID "TMPL2cqjtps42"
#define BLYNK_TEMPLATE_NAME "Acender LED"
#define BLYNK_AUTH_TOKEN "uqYbgLg7ez4kkCz6rhHIbO6KDFH4whkB"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Credenciais do Wi-Fi
char ssid[] = "F-IFSertao-PE-ALUNOS";            // 🔁 Troque aqui
char pass[] = "#ifsertao@aluno#";       // 🔁 Troque aqui

const int LED = D1;     // GPIO5
const int BOTAO = D2;   // GPIO4

bool estadoLED = false;
bool estadoBotaoAnterior = HIGH;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP); // Usa pull-up interno

  digitalWrite(LED, LOW);       // Garante LED desligado no início

  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Função chamada quando o botão virtual (V0) no app for usado
BLYNK_WRITE(V0) {
  int valor = param.asInt();
  estadoLED = valor;
  digitalWrite(LED, estadoLED);
}

void loop() {
  Blynk.run();

  // Controle local com botão físico (toggle)
  bool estadoBotaoAtual = digitalRead(BOTAO);

  if (estadoBotaoAnterior == HIGH && estadoBotaoAtual == LOW) {
    estadoLED = !estadoLED;
    digitalWrite(LED, estadoLED);
    Blynk.virtualWrite(V0, estadoLED); // Atualiza o app
    delay(200); // Debounce
  }

  estadoBotaoAnterior = estadoBotaoAtual;
}
