#define motor 3
#define pot A0
int vpot=0;
int vmotor=0;

void setup()
{
  pinMode(motor, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  vpot=analogRead(pot);
  vmotor=map(vpot, 0, 1023, 0, 255);
  analogWrite(motor, vmotor);
  Serial.println(vmotor);
  delay(400);
}