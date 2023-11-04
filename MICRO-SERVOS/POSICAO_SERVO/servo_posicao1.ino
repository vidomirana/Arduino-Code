#include <Servo.h>
Servo s1;
int angs1;
void setup()
{
  s1.attach(2);
  Serial.begin(9600);
}

void servoPos(){
	Serial.println("--------------------------");
  	Serial.println(s1.read());
  	Serial.print("--------------------------");
}

void p1(){
	s1.write(60);
}

void p2(){
	s1.write(120);
}

void p3(){
	s1.write(180);
}

void p0(){
	s1.write(0);
}

void loop()
{
  p0();
  servoPos();
  delay(1600);
  p1();
  servoPos();
  delay(1200);
  p2();
  servoPos();
  delay(1200);
  p3();
  servoPos();
  delay(1200);
}