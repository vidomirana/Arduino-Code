#define motor 7
void setup()
{
  pinMode(motor, OUTPUT);
}

void loop()
{
  digitalWrite(motor, HIGH);
  delay(1000);
  digitalWrite(motor, LOW);
  delay(2000);
}