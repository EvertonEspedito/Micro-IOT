const int BUTTON = D2;  
const int LED = D1;    

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);  // usa o resistor interno de pull-up
}

void loop() {
  if (digitalRead(BUTTON)) {  // botão pressionado (ativo em LOW)
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
  }

}
