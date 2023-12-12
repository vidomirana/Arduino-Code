#include <Wire.h>
#define pinoPH A0
float tensao;
float tensaobit;

void setup() {
  pinMode(pinoPH, INPUT);
  Serial.begin(9600);
}

void loop() {
  tensaobit = analogRead(pinoPH);
  tensao = (tensaobit * 5.0) / 1024.0;
  Serial.print("Tensão: ");
  Serial.print(tensao);
  Serial.println(" V");
  delay(1000);
}
