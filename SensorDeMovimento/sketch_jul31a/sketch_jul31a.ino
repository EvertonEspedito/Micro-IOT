int pinoPIR = 2;
int pinoLED = 12;

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
  } else {
    digitalWrite(pinoLED, LOW);
  }

  delay(100);
}
