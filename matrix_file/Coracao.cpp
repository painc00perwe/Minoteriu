#include "Effect.h"
#define Num_Led 48

class Coracao : public Effect {

  private:
  
  public:
  Coracao( CRGB *leds, int LINHA, int COLUNA) : Effect(leds, LINHA, COLUNA){
  }

  int AnimacaoCoracao0[8][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };
  
  int AnimacaoCoracao1[8][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };
  
  int AnimacaoCoracao2[8][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };
  
  int AnimacaoCoracao3[8][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };
  void comecar() {
  for (int i = 0; i < LINHA; i++) {
    for (int j = 0; j < COLUNA; j++) {
        if (AnimacaoCoracao0[i][j] == 0){
          leds[i*j].setRGB(255,105,180);
          }
         else if (AnimacaoCoracao0[i][j] == 1) {
          leds[i*j].setRGB(178,34,34);
         }
      }    
  }
  FastLED.show();
  delay(1000);

  // Aparece a segunda animacao:
  for (int i = 0; i < LINHA; i++) {
    for (int j = 0; j < COLUNA; j++) {
        if (AnimacaoCoracao1[i][j] == 0){
          leds[i*j].setRGB(255,105,180);
          }
         else if (AnimacaoCoracao1[i][j] == 1) {
          leds[i*j].setRGB(178,34,34);
         }
      }
  }
  FastLED.show();
  delay(1000);

  // Aparece a terceira animacao:
  for (int i = 0; i < LINHA; i++) {
    for (int j = 0; j < COLUNA; j++) {
        if (AnimacaoCoracao2[i][j] == 0){
          leds[i*j].setRGB(255,105,180);
          }
         else if (AnimacaoCoracao2[i][j] == 1) {
          leds[i*j].setRGB(178,34,34);
         }
       }
    }
  FastLED.show();
  delay(1000);

  // Aparece a quarta e ultima animacao
  for (int i = 0; i < LINHA; i++) {
    for (int j = 0; j < COLUNA; j++) {
        if (AnimacaoCoracao3[i][j] == 0){
          leds[i*j].setRGB(255,105,180);
          }
         else if (AnimacaoCoracao3[i][j] == 1) {
          leds[i*j].setRGB(178,34,34);
         }
       }
    }
  FastLED.show();
  delay(1000);
  }
 };
