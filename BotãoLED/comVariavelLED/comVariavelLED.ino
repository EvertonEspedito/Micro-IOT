//Com Conceito de Variavel
const int LED_PIN1 = ; //PINO LED
const int LED_PIN2 = ; //PINO LED

//Armazenar Valores
int estado1LED = HIGH;
int estado2LED = LOW;
int intervaloPisca = 300

void setup() {
  pinMode(LED_PIN1,OUTPUT);
  pinMode(LED_PIN2,OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN1,estado1LED);
  digitalWrite(LED_PIN1,estado2LED);
  delay(intervaloPisca);

  digitalWrite(LED_PIN2,estado1LED);
  digitalWrite(LED_PIN2,estado2LED); 
  delay(intervaloPisca);

}
