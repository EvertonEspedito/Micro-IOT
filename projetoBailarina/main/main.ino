// Pinos
const int pinLeds = 9;
const int pinPotAllLeds = A0;
const int pinBuzzerLeft = 2;
const int pinBuzzerRight = 3;
const int pinButtonOnOff = 13;

// Variáveis
int luminosidadeLEDS = 0;

bool sistemaLigado = false;
bool ultimoEstadoBotao = HIGH;

// Música
int melody[] = {
  262, 294, 330, 262,
  262, 294, 330, 262,
  330, 349, 392,
  330, 349, 392
};

int noteDurations[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,
  4,4,4
};

int noteIndex = 0;

unsigned long noteStartTime = 0;
bool tocandoNota = false;

void setup() {

  pinMode(pinLeds, OUTPUT);

  pinMode(pinBuzzerLeft, OUTPUT);
  pinMode(pinBuzzerRight, OUTPUT);

  pinMode(pinButtonOnOff, INPUT_PULLUP);
}

void loop() {

  // ===== BOTÃO =====
  bool estadoBotao = digitalRead(pinButtonOnOff);

  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {

    sistemaLigado = !sistemaLigado;

    if (!sistemaLigado) {

      noTone(pinBuzzerLeft);
      noTone(pinBuzzerRight);

      analogWrite(pinLeds, 0);
    }

    delay(200);
  }

  ultimoEstadoBotao = estadoBotao;

  if (!sistemaLigado) return;

  // ===== POTENCIÔMETRO =====
  luminosidadeLEDS =
    map(analogRead(pinPotAllLeds), 0, 1023, 0, 255);

  analogWrite(pinLeds, luminosidadeLEDS);

// ===== DESLIGA SOM SE FOR ZERO =====
if (luminosidadeLEDS <= 5) {

  if (tocandoNota) {

    noTone(pinBuzzerLeft);
    noTone(pinBuzzerRight);

    tocandoNota = false;

    // Reinicia música
    noteIndex = 0;
  }

  return;
}

  // ===== MÚSICA =====

  int noteDuration =
    1000 / noteDurations[noteIndex];

  // Quanto menor o potenciômetro,
  // menor o tempo do som
  int tempoSom =
    map(luminosidadeLEDS, 1, 255, 20, noteDuration);

  // Toca nota
  if (!tocandoNota) {

    tone(pinBuzzerLeft, melody[noteIndex]);
    tone(pinBuzzerRight, melody[noteIndex] + 20);

    noteStartTime = millis();

    tocandoNota = true;
  }

  // Desliga antes do fim para simular volume
  if (millis() - noteStartTime >= tempoSom) {

    noTone(pinBuzzerLeft);
    noTone(pinBuzzerRight);
  }

  // Próxima nota
  if (millis() - noteStartTime >= noteDuration) {

    noteIndex++;

    if (noteIndex >= 14) {
      noteIndex = 0;
    }

    tocandoNota = false;
  }
}