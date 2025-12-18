int INA = 5;
int IN1 = 6;
int IN2 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(INA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  analogWrite(INA,100);
  delay(1000);

  analogWrite(INA,150);
  delay(1000);


  analogWrite(INA,250);
  delay(1000);

  analogWrite(INA,0);
  delay(1000);
}
