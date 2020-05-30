// Light.h

#ifndef _LIGHT_h
#define _LIGHT_h

#define FASTLED_INTERNAL 

#define BUT false
#define TOP true

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void SetBrightness(int);
void PowerON(int);
void PowerOFF(int);
void SetFadeRed(int);
void SetupLeds();
void SetLight(int Brightness_But);

#endif

