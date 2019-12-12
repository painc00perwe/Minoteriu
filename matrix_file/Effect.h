/*
 * The Effect abstract class for the GauntletII project.
 * Modified by Hamamoto, Felipe M.
 */

#ifndef Effect_h
#define Effect_h

#import <FastLED.h>

class Effect {

    protected:
        CRGB *leds;
        int LINHA, COLUNA;
    
        struct CRGB& pixel(int x, int y);
        bool inXRange(int x);
        bool inYRange(int y);
    
        void clearLeds();

    public:
        Effect(CRGB *leds, int LINHA, int COLUNA);

        virtual void comecar() {};

};

#endif
