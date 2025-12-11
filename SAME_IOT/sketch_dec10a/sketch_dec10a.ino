  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClient.h>
  #include <DHT.h>

  #define DHTPIN D7      // D4
  #define DHTTYPE DHT11
  DHT dht(DHTPIN, DHTTYPE);

  const char* ssid = "F-IFSertao-PE-ALUNOS";
  const char* senha = "#ifsertao@aluno#";

  // SUBSTITUA PELO IP DO SEU COMPUTADOR
  const char* servidor = "http://10.103.34.163:8000/api/leitura/"; 

  void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, senha);
    dht.begin();

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nWiFi conectado!");
  }

  void loop() {
    float umidade = dht.readHumidity();
    float temperatura = dht.readTemperature();

    if (isnan(umidade) || isnan(temperatura)) {
      Serial.println("Erro ao ler DHT!");
      return;
    }

    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      HTTPClient http;

      http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
      http.begin(client, servidor);
      http.addHeader("Content-Type", "application/json");

      String json = "{\"temperatura\":" + String(temperatura) +
                    ", \"umidade\":" + String(umidade) + "}";

      int codigo = http.POST(json);
      Serial.println("Código HTTP: " + String(codigo));

      String resposta = http.getString();
      Serial.println("Resposta: " + resposta);

      http.end();
    }

    delay(5000);
  }
