#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define pinoPH A0           //sinal do sensor de PH
#define pinoTEMP 3          //sinal do sensor DS18B20

//Variáveis para o PH===============================================================================
int contagem;           // Variável de contagem
float soma_tensao;      // Variável para soma de tensão
float media;            // Variável que calcula a media
float entradaPH;        // Variável de leitura do pino A0
float tensao;           // Variável para conversão em tensão
float valor_PH;         //Variável para receber o valor do Ph
float PH;               //Variável para mostrar o PH no Serial
unsigned long tempo;    // Float tempo
//==================================================================================================
//Variáveis para a temperatura======================================================================
float TEMPERATURA;                //Variável para receber o valor da temperatura
//==================================================================================================
//Declaração de Objetos=============================================================================
OneWire oneWire(pinoTEMP);        //objeto one_wire
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;
// =================================================================================================
void setup() {
  Serial.begin(9600);
  
  sensors.begin();
  
  // Localiza e mostra enderecos dos sensores
  Serial.println("Localizando sensores DS18B20...");
  Serial.print("Foram encontrados ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" sensores.");
  
  if (!sensors.getAddress(sensor1, 0)) 
     Serial.println("Sensores nao encontrados !"); 
     
  // Mostra o endereco do sensor encontrado no barramento
  Serial.print("Endereco sensor: ");
  mostra_endereco_sensor(sensor1);
  Serial.println();
  Serial.println();
  delay(1500);
}
//Loop infinito=====================================================================================
void loop() {
  PH = le_PH();
  TEMPERATURA = le_temperatura();
  //Serial.print("PH: ");
  Serial.print(PH);
  Serial.print(",");
  //Serial.print("Temp: ");
  Serial.println(TEMPERATURA);
  delay(1000);                    // Aguarda para próxima leitura
}
//==================================================================================================

//Função para ler o PH~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

float le_PH() {
  soma_tensao = 0;   // Inicia soma_tensão em 0
  contagem = 0;      // Inicia a contagem em 0

  while (contagem < 10) {                   // Executa enquanto contagem menor que 10
    tempo = millis();                       // Define o tempo em microssegundos
    entradaPH = analogRead(pinoPH);            // Lê a entrada analógica
    tensao = (entradaPH * 5.0) / 1024.0;   // Converte em tensão, o valor lido
    soma_tensao = (soma_tensao + tensao);   // Soma a tensão anterior com a atual
    contagem++;                             // Soma 1 à variável de contagem
    delay(100);                             // Aguarda para próxima leitura
  }

  media = soma_tensao / 10.0;                 // Calcula a média das leituras

  valor_PH = (media - 0.12) * 13.66 / 4.88;    //interpolação para contornar o erro sistemático de 0.12V

  return valor_PH;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Função para ler a temperatura~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

float le_temperatura() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(sensor1); //Recebe a temperatura em °C
  return tempC;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Função para mostrar endereço do sensor~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mostra_endereco_sensor(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // Adiciona zeros se necessário
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}