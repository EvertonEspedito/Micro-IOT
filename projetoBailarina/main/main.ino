// Pinos
const int pinLeds = 9;           
const int pinPotAllLeds = A0;    
const int pinBuzzerLeft = 2;     
const int pinBuzzerRight = 3;    

float luminosidadeLEDS = 0;

// Notas da música
int melody[] = { 262, 294, 330, 262, 262, 294, 330, 262, 330, 349, 392, 330, 349, 392 };
int noteDurations[] = { 4,4,4,4,4,4,4,4,4,4,4,4,4,4 };

// Controle da música
int noteIndex = 0;
unsigned long noteStartTime = 0;
bool tocando = false;

void setup() {
  pinMode(pinLeds, OUTPUT);
  pinMode(pinPotAllLeds, INPUT);
  pinMode(pinBuzzerLeft, OUTPUT);
  pinMode(pinBuzzerRight, OUTPUT);
}

void loop() {
  // Lê potenciômetro
  luminosidadeLEDS = map(analogRead(pinPotAllLeds), 0, 1023, 0, 255);
  analogWrite(pinLeds, luminosidadeLEDS);

  if (luminosidadeLEDS > 0) {
    if (!tocando) { // Começa música só se ainda não estiver tocando
      noteIndex = 0;
      tocarNota();
      tocando = true;
    }
    avancarMusica();
  } else if (tocando) { // Para música uma vez
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

    // Pausa curta entre notas (50ms)
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
