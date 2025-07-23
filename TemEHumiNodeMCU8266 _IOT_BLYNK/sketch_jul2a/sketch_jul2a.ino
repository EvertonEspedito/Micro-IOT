#include "DHT.h"

// Define os pinos usando GPIO do NodeMCU
#define DHTPIN D7          // GPIO4
#define DHTTYPE DHT11

#define ALERT_PIN D5       // GPIO14 - LED vermelho
#define OK_PIN D6          // GPIO12 - LED verde

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(ALERT_PIN, OUTPUT);
  pinMode(OK_PIN, OUTPUT);
}

void loop() {
  delay(5000); // Aguarda 5 segundos

  float h = dht.readHumidity();
  float t = dht.readTemperature();

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
    digitalWrite(OK_PIN, LOW);
    Serial.println("⚠️ ALERTA: Temperatura alta!");
  } else {
    digitalWrite(ALERT_PIN, LOW);
    digitalWrite(OK_PIN, HIGH);     // Liga LED verde
  }
}
