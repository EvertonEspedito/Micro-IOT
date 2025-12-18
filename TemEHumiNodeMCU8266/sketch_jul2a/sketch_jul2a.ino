#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"

#define DHTPIN D7
#define DHTTYPE DHT11

const char* ssid = "F-IFSertao-PE-ALUNOS";
const char* password = "#ifsertao@aluno#";

const char* servidor = "http://10.103.32.51:8000/api/leitura/";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.println(WiFi.localIP());

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) return;

  WiFiClient client;
  HTTPClient http;

  String json = "{\"temperatura\":" + String(t) +
                ",\"umidade\":" + String(h) + "}";

  http.begin(client, servidor);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.POST(json);

  Serial.print("Código HTTP: ");
  Serial.println(httpCode);

  http.end();

  delay(5000);
}
