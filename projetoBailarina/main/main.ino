// Pinos
const int pinLeds = 9;           
const int pinPotAllLeds = A0;    
const int pinBuzzerLeft = 2;     
const int pinBuzzerRight = 3;    
const int pinButtonOnOff = 13;   // Botão de liga/desliga

float luminosidadeLEDS = 0;

// Notas da música
int melody[] = { 262, 294, 330, 262, 262, 294, 330, 262, 330, 349, 392, 330, 349, 392 };
int noteDurations[] = { 4,4,4,4,4,4,4,4,4,4,4,4,4,4 };

// Controle da música
int noteIndex = 0;
unsigned long noteStartTime = 0;
bool tocando = false;

// Controle do sistema
bool sistemaLigado = false;      // começa desligado
bool ultimoEstadoBotao = HIGH;   // botão não pressionado (pull-up)

void setup() {
  pinMode(pinLeds, OUTPUT);
  pinMode(pinPotAllLeds, INPUT);
  pinMode(pinBuzzerLeft, OUTPUT);
  pinMode(pinBuzzerRight, OUTPUT);
  pinMode(pinButtonOnOff, INPUT_PULLUP); // usa resistor interno
}

void loop() {
  bool estadoBotao = digitalRead(pinButtonOnOff);

  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    sistemaLigado = !sistemaLigado;

    if (!sistemaLigado) {
      pararMusica();
      analogWrite(pinLeds, 0);
    }

    delay(200); // debounce
  }
  ultimoEstadoBotao = estadoBotao;

  if (!sistemaLigado) return;

  luminosidadeLEDS = map(analogRead(pinPotAllLeds), 0, 1023, 0, 255);
  analogWrite(pinLeds, luminosidadeLEDS);

  if (luminosidadeLEDS > 0) {
    if (!tocando) {
      noteIndex = 0;
      tocarNota();
      tocando = true;
    }
    avancarMusica();
  } else if (tocando) {
    pararMusica();
  }
}

void tocarNota() {
  int noteDuration = 1000 / noteDurations[noteIndex];
  tone(pinBuzzerLeft, melody[noteIndex]);
  tone(pinBuzzerRight, melody[noteIndex] + 20);
  noteStartTime = millis();
}

void avancarMusica() {
  int noteDuration = 1000 / noteDurations[noteIndex];
  if (millis() - noteStartTime >= noteDuration) {
    noTone(pinBuzzerLeft);
    noTone(pinBuzzerRight);

    if (millis() - noteStartTime >= noteDuration + 50) {
      noteIndex++;
      if (noteIndex >= 14) noteIndex = 0;
      tocarNota();
    }
  }
}

void pararMusica() {
  noTone(pinBuzzerLeft);
  noTone(pinBuzzerRight);
  tocando = false;
}
