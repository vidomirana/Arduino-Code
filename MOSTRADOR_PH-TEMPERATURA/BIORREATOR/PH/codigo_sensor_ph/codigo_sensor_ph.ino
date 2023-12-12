#include <Wire.h>

//float valor_calibracao = 21.34 + 5.31;   // Fator de calibração

int contagem = 0;           // Variável de contagem
float soma_tensao = 0;      // Variável para soma de tensão
float media = 0;            // Variável que calcula a media
float entrada_A0;           // Variável de leitura do pino A0
float tensao;               // Variável para conversão em tensão
float valor_pH;             //Variável para receber o valor do Ph
unsigned long tempo;        // Float tempo

void setup() {
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  soma_tensao = 0;   // Inicia soma_tensão em 0
  contagem = 0;      // Inicia a contagem em 0

  while (contagem < 10) {                   // Executa enquanto contagem menor que 10
    tempo = millis();                       // Define o tempo em microssegundos
    entrada_A0 = analogRead(A0);            // Lê a entrada analógica
    tensao = (entrada_A0 * 5.0) / 1024.0;   // Converte em tensão, o valor lido
    soma_tensao = (soma_tensao + tensao);   // Soma a tensão anterior com a atual
    contagem++;                             // Soma 1 à variável de contagem
    delay(100);                             // Aguarda para próxima leitura
  }

  media = soma_tensao / 10.0;                 // Calcula a média das leituras

  //float valor_pH = -5.70 * media + valor_calibracao;    // Calcula valor de pH, essa fórmula é dos autores originais
  //valor_pH = map(media, 0.12, 5.0, 0.0, 13.66)   //mapeamento para calibrar o erro sistematico de 0.12V, porém apenas dá um PH inteiro
  valor_pH = (media - 0.12) * 13.66 / 4.88    //interpolação para contornar o erro sistemático de 0.12V

  Serial.println(valor_pH);

  delay(1000);                    // Aguarda para próxima leitura
}