#define velm1 3
#define velm2 11
#define m1a 2
#define m1b 4
#define m2a 12
#define m2b 13
int vel=255;

void setup()
{
  pinMode(velm1, OUTPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  
  pinMode(velm2, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  
  analogWrite(velm1, 0);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  
  analogWrite(velm2, 0);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  
}

void loop()
{
  //girar em um sentido
  analogWrite(velm1, vel);
  digitalWrite(m1a, HIGH);
  
  analogWrite(velm2, vel);
  digitalWrite(m2a, HIGH);
  delay(3000);
  
  //FREIAR!!!! MUITO RECOMENDADO PELA SEGURANÇA DO CIRCUITO
  analogWrite(velm1, 0);
  digitalWrite(m1a, LOW);
  
  analogWrite(velm2, 0);
  digitalWrite(m2a, LOW);
  delay(100);
  
  //girar no outro sentido
  analogWrite(velm1, vel);
  digitalWrite(m1b, HIGH);
  
  analogWrite(velm2, vel);
  digitalWrite(m2b, HIGH);
  delay(3000);
  
  //FREIAR!!!
  analogWrite(velm1, 0);
  digitalWrite(m1b, LOW);
  
  analogWrite(velm2, 0);
  digitalWrite(m2b, LOW);
  delay(100);
}