#define led 3
#define btn 4

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
}

void loop()
{
  if(digitalRead(btn)==HIGH){
  	digitalWrite(led, HIGH);
  }else{
  	digitalWrite(led, LOW);
  }
}