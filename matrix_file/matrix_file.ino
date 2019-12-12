#include <FastLED.h>

#define LINHA 8
#define COLUNA 6
#define Num_Led 48
#define Led_Pin 3
#include "solucaoLabirintoV2.cpp"
#include "animacaoCoracao.cpp"


CRGB leds[Num_Led];


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, Led_Pin,RGB>(leds,Num_Led);
  Serial.begin(9600);
}

void loop() {
  animandoCoracao();


  resolvendoLabirinto();
}

void animandoCoracao(){
  Coracao animandoCoracao(leds, LINHA, COLUNA);
  animandoCoracao.comecar();
}

void resolvendo_Labirinto() {
  LabirintoV2 resolvendoLabirinto(leds, LINHA, COLUNA);
  resolvendoLabirinto.comecar();
}
