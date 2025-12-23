int INA = 3; 
int IN1 = 4;
int IN2 = 5;
int INB = 6;
int IN3 = 7;
int IN4 = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(INA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(INB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  analogWrite(INA,100);
  analogWrite(INB,100);
  delay(2000);

  analogWrite(INA,0);
  analogWrite(INB,150);
  delay(1000);

  analogWrite(INA,150);
  analogWrite(INB,150);
  delay(3000);

  analogWrite(INA,0);
  analogWrite(INB,150);
  delay(1000);

  analogWrite(INA,250);
  analogWrite(INB,250);
  delay(1000);

  analogWrite(INA,0);
  analogWrite(INA,0);
  delay(6000);
}
