const int LED = ;     // PINOS
const int BOTAO = ;   // PINOS

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
