#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); 
// Pino 10 = RX (recebe do TXD do módulo)
// Pino 11 = TX (envia para RXD do módulo)

void setup() {
  Serial.begin(9600);        // Monitor Serial
  bluetooth.begin(9600);     // Velocidade padrão HC-05/HC-06
  
  Serial.println("Bluetooth!");
}

void loop() {

  // Se receber algo do Bluetooth
  if (bluetooth.available()) {
    char c = bluetooth.read();
    if(c == 'a'){
      Serial.println("Resposta certa!");
    }

    Serial.write(c);   // Mostra no Monitor Serial
  }

  // Se digitar algo no Monitor Serial
  if (Serial.available()) {
    char c = Serial.read();

    if(c == '4'){
      Serial.println("Resposta certa!");
    }
    bluetooth.write(c);  // Envia para o Bluetooth
  }
}

