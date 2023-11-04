#define led 3 
#define max 255
#define min 0
#define tempo 100

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  for (int i=min; i<max;i++){
    analogWrite(led, i);
    delay(500);
  }
  for (int i=max; i>min; i--){
    analogWrite(led, i);
    delay(tempo);
  }
}