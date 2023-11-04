#include <Servo.h>
#define pot A0
Servo s1;
Servo s2;
int angs1;
int angs2;
int pos;

void setup()
{
  s1.attach(3);
  angs1=0;
  s1.write(angs1); //0 a 180
  
  s2.attach(2);
  angs2=0;
  s2.write(angs2);
  
  pos=0;
}

void loop()
{
  angs1=map(analogRead(pot), 0, 1023, 0, 180);
  s1.write(angs1);
  pos=s1.read(); //lê a posição do servo
  delay(100);
  
  angs2=180;
  s2.write(angs2);
  delay(2000);
  
  angs2=0;
  s2.write(pos);
  delay(2000);
}