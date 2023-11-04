#define ledR 2
#define ledG 4
#define ledB 3
#define btnPin 7

class Botao {
public:
  int btnclicado, btnsolto, pino;
  Botao(int p) : pino(p), btnclicado(0), btnsolto(0) {}
  bool press() {
    if (digitalRead(pino) == HIGH) {
      btnclicado = 1;
      btnsolto = 0;
    } else {
      btnsolto = 1;
    }
    if (btnclicado == 1 && btnsolto == 1) {
      btnclicado = 0;
      btnsolto = 0;
      return true;
    } else {
      return false;
    }
  }
};

class Cor {
public:
  int pinoR, pinoG, pinoB, ciclo, maximo;
  Cor(int pr, int pg, int pb) : pinoR(pr), pinoB(pb), pinoG(pg), ciclo(0), maximo(3) {}
  void trocaLed() {
    if (ciclo == 0) {
      corLed(1, 0, 0);
    } else if (ciclo == 1) {
      corLed(0, 1, 0);
    } else if (ciclo == 2) {
      corLed(0, 0, 1);
    }
    ciclo++;
    if (ciclo > maximo - 1) {
      ciclo = 0;
    }
  }

private:
  void corLed(int r, int g, int b) {
    digitalWrite(pinoR, r); // HIGH==1, LOW==0
    digitalWrite(pinoG, g);
    digitalWrite(pinoB, b);
  }
};

Botao btn(btnPin);
Cor core(ledR, ledG, ledB);

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(btnPin, INPUT);
}

void loop() {
  if (btn.press()) {
    core.trocaLed();
  }
}
