// map(valor_entrada, entrada_min, 
	//     entrada_max,saida_min, saida_max)     
// isso aqui é uma regra de três

#define led 3
#define pot A0
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
}

void loop()
{
  //Analógica = 0 a 1023
  //PWM~      = 0 a 255
  
  //analogWrite(led,analogRead(pot)/4);
  
  int saida_led = map(analogRead(pot), 0, 1023, 0, 255);
  analogWrite(led, saida_led);
}