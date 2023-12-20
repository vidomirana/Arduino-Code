#include <HCSR04.h>
#define triggerPin 4
#define echoPin 5
#define led 10
double* distances;
int valorLed=0;

void setup() {
  Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);
  pinMode(led, OUTPUT);
}

void loop() {
  distances = HCSR04.measureDistanceCm();
  
  Serial.print(distances[0]);
  Serial.println(" cm");
  Serial.println("---");
  if (distances[0] > 30.0){
    digitalWrite(led, 255);
  } else {
    valorLed = map(distances[0], 0, 30.0, 0, 255);
    //Serial.print("PWM: ");
    //Serial.println(valorLed);
    //digitalWrite(led, valorLed);
  }
  delay(1000);
}
