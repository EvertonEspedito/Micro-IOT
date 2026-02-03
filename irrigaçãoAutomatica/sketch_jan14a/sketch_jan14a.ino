#define pinDigital   13
#define pinAnalog    A0
#define pinRelay     7

float AnalogOutput = 0;
float voltage = 0;
int LeituraSensor = 0;

int soloSeco = 700;     // valor alto = seco
int soloUmido = 400;   // valor baixo = molhado

void setup() {
  pinMode(pinDigital, INPUT);
  pinMode(pinRelay, OUTPUT);
  Serial.begin(9600);

  digitalWrite(pinRelay, HIGH); // relé inicia desligado
}

void loop() {

  // Leitura analógica (0 a 1023)
  AnalogOutput = analogRead(pinAnalog);

  // Leitura digital (0 ou 1)
  LeituraSensor = digitalRead(pinDigital);

  // Converte para tensão
  voltage = AnalogOutput * (5.0 / 1023.0);

  Serial.println("------ Leitura do Sensor ------");
  Serial.print("Valor Analogico: ");
  Serial.println(AnalogOutput);

  Serial.print("Tensao: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Saida Digital: ");
  Serial.println(LeituraSensor);

  // PRIORIDADE: Usa a saída digital do sensor
  if (LeituraSensor == HIGH) {  
    Serial.println("Solo SECO → Irrigação LIGADA 💧");
    digitalWrite(pinRelay, LOW);   // ativa relé
  } 
  else {
    Serial.println("Solo UMIDO → Irrigação DESLIGADA");
    digitalWrite(pinRelay, HIGH);  // desativa relé
  }

  // Segurança extra usando a leitura analógica
  if (AnalogOutput > soloSeco) {
    Serial.println("Confirmado por analógico: SOLO SECO");
    digitalWrite(pinRelay, LOW);
  }
  else if (AnalogOutput < soloUmido) {
    Serial.println("Confirmado por analógico: SOLO UMIDO");
    digitalWrite(pinRelay, HIGH);
  }

  Serial.println("------------------------------");
  delay(2000);
}
