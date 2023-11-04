//Função CONSTRAIN
//   constrain(valor_lido, saida_min, saida_max);
//Restringe a leitura numa faixa de valores
//Por exemplo só aceitas leituras analógicas entre 600 e 800

#define pot A0
int vpot=0;
void setup()
{
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  vpot=analogRead(pot);
  vpot=constrain(vpot, 500, 800);
  Serial.println(vpot);
  delay(750);
}