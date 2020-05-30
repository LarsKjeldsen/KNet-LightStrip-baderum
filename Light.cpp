#include "Light.h"
#include "FastLED.h"


#define NUM_LEDS 33

#define BUT_S 0
#define BUT_E 12
#define TOP_S 13
#define TOP_E 33

#define DATA_PIN D5  // 2 D5

CRGBArray<NUM_LEDS> leds;


void SetupLeds()
{
	Serial.println(F("Initialise LEDS - "));
	LEDS.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
//	LEDS.addLeds<TM1809, DATA_PIN>(leds, NUM_LEDS);
}


void SetLight(int Brightness_top)
{
		static uint8_t hue = 0;


		const CRGB cr = CRGB(255, 0, 0);
		const CRGB cg = CRGB(0, 255, 0);
		const CRGB cb = CRGB(0, 0, 255);

		leds(TOP_S, TOP_E).fill_solid(CHSV(255,255, Brightness_top));
			leds(30, 31).fill_solid(cg);
			leds(31, 32).fill_solid(cb);

		leds(24, 25).fill_solid(CRGB(0, 0, 0));

		leds(BUT_S, BUT_E).fill_rainbow(hue++);

		FastLED.delay(3);
}


void SetBrightness(int b)
{
	PowerON(b);
}


void PowerOFF(int b)
{
	for (int i = 0; i <= (BUT_E - BUT_S) / 2; i++) {
		leds[BUT_S + i] = CHSV(128, 0, 0);
		leds[BUT_E - i] = CHSV(128, 0, 0);
		LEDS.show();
		LEDS.delay(20);
	}
}


void PowerON(int b)
{
	for (int i = 0; i <= (BUT_E - BUT_S) / 2; i++) {
		leds[BUT_S + i] = CHSV(0, 60 + (i * (b / 50)), b);
		leds[BUT_E - i] = CHSV(0, 60 + (i * (b / 50)), b);
		LEDS.show();
		LEDS.delay(20);
	}
}

void SetFadeRed(int b)
{}