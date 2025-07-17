#include "DHT.h"

#define DHTPIN 7          // Pino de dados do DHT11 (ajustado para pino 7 no Uno)
#define DHTTYPE DHT11     // Tipo do sensor DHT
#define ALERT_PIN 13      // Pino de alerta (LED vermelho)
#define OK_PIN 12         // Pino de OK (LED verde)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(ALERT_PIN, OUTPUT); // Configura LED de alerta
  pinMode(OK_PIN, OUTPUT);    // Configura LED de OK
}

void loop() {
  delay(5000); // Aguarda 5 segundos entre leituras

  float h = dht.readHumidity();      // Lê umidade
  float t = dht.readTemperature();   // Lê temperatura em Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Falha na leitura do sensor DHT!");
    return;
  }

  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");

  if (t >= 50.5) {
    digitalWrite(ALERT_PIN, HIGH);  // Liga LED vermelho
    digitalWrite(OK_PIN, LOW);      // Desliga LED verde
    Serial.println("⚠️ ALERTA: Temperatura alta!");
  } else {
    digitalWrite(ALERT_PIN, LOW);   // Desliga LED vermelho
    digitalWrite(OK_PIN, HIGH);     // Liga LED verde
  }
}
