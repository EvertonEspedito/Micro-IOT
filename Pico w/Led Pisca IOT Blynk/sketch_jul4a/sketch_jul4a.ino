/*************************************************************
 * Código para Raspberry Pi Pico W usando Blynk IoT (novo)
 * Conecta ao Wi-Fi e controla um LED pelo botão V0
 *************************************************************/

#define BLYNK_TEMPLATE_ID "TMPL2m3TVsAAw"
#define BLYNK_TEMPLATE_NAME "Interruptor Pico w"
#define BLYNK_AUTH_TOKEN "FqYkBz-sa7UI1VnLv8m6aVrJtnIu4isl"

#include <WiFi.h>                // Pico W usa a stack WiFi do ESP32
#include <BlynkSimpleEsp32.h>   // Funciona com Pico W

char ssid[] = "DEUS E AMOR";     // Nome da sua rede Wi-Fi
char pass[] = "20304060";        // Senha da sua rede Wi-Fi

int ledPin = 13;  // Pino onde o LED está conectado

BlynkTimer timer;

// Quando o app escreve em V0
BLYNK_WRITE(V0)
{
  int value = param.asInt(); // Lê o valor do botão (0 ou 1)
  digitalWrite(ledPin, value);  // Liga ou desliga o LED
}

void setup()
{
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
  delay(1000);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
  timer.run();
}
