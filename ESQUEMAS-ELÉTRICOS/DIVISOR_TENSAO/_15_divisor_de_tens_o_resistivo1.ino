#define analog A0
void setup()
{
  pinMode(analog, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(analog));
  delay(800);
}