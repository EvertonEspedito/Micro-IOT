int pinoPot = A0;   // Pino do potenciômetro
int pinoLED = 6;    // Pino PWM do LED
int valorPot = 0;   // Para guardar leitura

void setup() {
  pinMode(pinoLED, OUTPUT)
}

void loop() {
  // Lê o potenciômetro (0 a 1023)
  valorPot = analogRead(pinoPot);

  // Converte para 0 a 255 (PWM do LED)
  int brilho = map(valorPot, 0, 1023, 0, 255);

  // Ajusta brilho do LED
  analogWrite(pinoLED, brilho);

  delay(10);  // Pequeno atraso
}
