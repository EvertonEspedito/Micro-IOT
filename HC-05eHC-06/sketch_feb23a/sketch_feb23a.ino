#include <SoftwareSerial.h> 

SoftwareSerial bluetooth(2, 3); 

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Pronto para testar!");
}

void loop() {
  if (bluetooth.available()) {
    Serial.print("Recebido: ");
    Serial.println(bluetooth.readString());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}