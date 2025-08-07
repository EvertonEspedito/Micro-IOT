int pinoPIR = 2;
int pinoLED = 13;

void setup() {
  pinMode(pinoPIR, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pinoPIR) == HIGH) {
    Serial.println("Movimento detectado!");
    digitalWrite(pinoLED, HIGH);
    delay(5000);
  } 
  if (digitalRead(pinoPIR) == LOW) {
    Serial.println("Nenhum Movimento Detectado!");
    digitalWrite(pinoLED, LOW);
  
  }

  delay(2000);
}
