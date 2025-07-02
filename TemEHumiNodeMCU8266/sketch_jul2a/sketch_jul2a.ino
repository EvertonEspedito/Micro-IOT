#include "DHT.h"

#define DHTPIN D1         // Pino de dados do DHT11
#define DHTTYPE DHT11     // Tipo do sensor
#define ALERT_PIN D2      // Pino de alerta (ex: LED)
#define OK_PIN D3         // Pino de OK (ex: LED verde)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(ALERT_PIN, OUTPUT); // LED de alerta (vermelho)
  pinMode(OK_PIN, OUTPUT);    // LED de OK (verde)
}

void loop() {
  delay(5000);
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

  if (t >= 23.5) {
    digitalWrite(ALERT_PIN, HIGH);  // Liga LED vermelho
    digitalWrite(OK_PIN, LOW);      // Desliga LED verde
    Serial.println("⚠️ ALERTA: Temperatura alta!");
  } else {
    digitalWrite(ALERT_PIN, LOW);   // Desliga LED vermelho
    digitalWrite(OK_PIN, HIGH);     // Liga LED verde
  }
}
