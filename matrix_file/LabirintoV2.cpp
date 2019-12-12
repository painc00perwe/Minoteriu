#include "Effect.h"
#define Num_Led 48

// 
class LabirintoV2 : public Effect {
  private: 

  public:
  LabirintoV2(CRGB *leds, int LINHA, int COLUNA) : Effect(leds, LINHA, COLUNA){
  }

  int labirinto[8][6] = {
        {9, 9, 9, 9, 9, 9},
        {9, 0, 9, 0, 0, 9},
        {9, 0, 0, 0, 9, 9},
        {9, 0, 9, 9, 0, 9},
        {9, 0, 9, 0, 0, 9},
        {9, 0, 0, 9, 0, 9},
        {9, 9, 0, 0, 0, 9},
        {9, 9, 9, 9, 9, 9},
    };

    enum layout_labirinto {
  parede = 9,
  destino = 8,
  comeco = 7,
  naoPercorrido = 0,
  jaPercorrido = 1
};

    
  int x = 0;
  int y = 0;
  int xComeco = 0;
  int yComeco = 0;
  int xDestino = 0;
  int yDestino = 0;
  
  void comecar(){
    
   xComeco = Serial.read();
   yComeco = Serial.read();

    xDestino = Serial.read();
   yDestino = Serial.read();

   labirinto[xComeco][yComeco] = comeco;
   labirinto[xDestino][yDestino] = destino;

    for (int i = 0; i < LINHA; i++) {
      for (int j = 0; j < COLUNA; j++){
        if (labirinto[i][j] == parede) {
          leds[i*j].setRGB(0,0,255);
          FastLED.show();
        }
        else if (labirinto[i][j] == destino) {
          leds[i*j].setRGB(255,0,0);
          FastLED.show();
        } 
        else if (labirinto[i][j] == comeco) {
          leds[i*j].setRGB(0,255,0);
          FastLED.show();
        }
        else if (labirinto[i][j] == naoPercorrido) {
          leds[i*j].setRGB(255,255,0);
          FastLED.show();
        }
      }
    }
      resolvendo();
}

  
  // Funcao na qual procura a resolucao do labirinto
  int procurar(int x, int y){
    // Verifica se o proximo eh o detino final:
        if (labirinto[x][y] == destino) {
          return true;
        } // Caso nao seja:
        // Verifica se o proximo eh uma parede:
        else if (labirinto[x][y] == parede) {
          return false;
        } //Caso nao seja:
        // Verifica se o proximo ja foi um lugar visitado;
        else if (labirinto[x][y] == jaPercorrido) {
          return false;
        }
    
      // Marca como percorrido:
      labirinto[x][y] = 1;
      // Anda no painel de LED tambem na qual foi explorada:
      leds[x*y].setRGB(254,127,156);
      FastLED.show();
      delay(100000);
      }

  
  void resolvendo() {
    // Primeira condicao confere se nao eh o fim da matrix, em x e y:
    // Chama a funcao procurar somando um a mais em alguns de seus parametros
  if ((x < sizeof(labirinto) - 1 && procurar(x + 1, y)) ||
      (y > 0 && procurar(x, y - 1)) ||
      (x > 0 && procurar(x - 1, y)) ||
      (y > sizeof(labirinto) - 1 && procurar(x, y + 1))) {
        return true;
    } else {
        return false;
    }
  };
