const int LED = D1;     // GPIO5 (seguro para saída)
const int BOTAO = D2;   // GPIO4 (seguro para entrada)

void setup() {
  pinMode(LED, OUTPUT);     
  pinMode(BOTAO, INPUT);
}

void loop() {
  int estadoBotao = digitalRead(BOTAO); // Lê o botão
  
  if (estadoBotao == LOW) {  // Botão pressionado (puxado para GND)
    digitalWrite(LED, HIGH); // Liga o LED
  } else {
    digitalWrite(LED, LOW);  // Desliga o LED
  }
}
