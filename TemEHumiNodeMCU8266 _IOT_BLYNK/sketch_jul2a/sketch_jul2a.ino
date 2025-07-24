// Blynk Credentials
#define BLYNK_TEMPLATE_ID "TMPL2WXlL8C8o"
#define BLYNK_TEMPLATE_NAME "HUMIDADE e TEMPERATURA"
#define BLYNK_AUTH_TOKEN "lR35gfOLrNQR883onr36ErcP5vQfq4q8"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

// Wi-Fi Credentials
char ssid[] = "F-IFSertao-PE-ALUNOS";       // Substitua pelo nome do seu Wi-Fi
char pass[] = "#ifsertao@aluno#";           // Substitua pela senha do seu Wi-Fi

// Sensor DHT
#define DHTPIN D7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  // Conecta ao Wi-Fi e ao Blynk
  dht.begin();
}

void loop() {
  Blynk.run();

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

  // Envia para o app Blynk
  Blynk.virtualWrite(V0, t);  // V0 = Temperatura
  Blynk.virtualWrite(V1, h);  // V1 = Umidade

  delay(5000);  // Aguarda 5 segundos
}
