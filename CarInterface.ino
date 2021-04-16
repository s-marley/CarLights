/*
 Name:		CarInterface.ino
 Created:	3/17/2021 4:15:11 PM
 Author:	Scott Marley
 
 Code and schematic demonstrating how to interface an Arduino with 12V signals
 from a vehicle. This code is for educational purposes only, and should not be
 used on public roads unless you know it is legal where you live.
*/

#include <FastLED.h>

#define NUM_LEDS			    9
#define INDICATOR_MS      30
#define BRIGHTNESS        200

// Connections to the 12V signals from vehicle
#define BRAKE_INPUT			  4
#define L_INDICATOR_INPUT	3
#define R_INDICATOR_INPUT	2

// Connections to the LED strips
#define L_BRAKE_LED_PIN		  8
#define R_BRAKE_LED_PIN		  9
#define L_INDICATOR_LED_PIN	7
#define R_INDICATOR_LED_PIN	6

// LED arrays for the lights
CRGB l_brake_leds[NUM_LEDS];
CRGB r_brake_leds[NUM_LEDS];
CRGB l_indicator_leds[NUM_LEDS];
CRGB r_indicator_leds[NUM_LEDS];

// Used for indicator animation
uint8_t indicatorLEDsLit = 0;

void setup() {
	FastLED.addLeds<WS2812B, L_BRAKE_LED_PIN, GRB>(l_brake_leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<WS2812B, R_BRAKE_LED_PIN, GRB>(r_brake_leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<WS2812B, L_INDICATOR_LED_PIN, GRB>(l_indicator_leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<WS2812B, R_INDICATOR_LED_PIN, GRB>(r_indicator_leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(BRIGHTNESS;

	pinMode(BRAKE_INPUT, INPUT);
	pinMode(L_INDICATOR_INPUT, INPUT);
	pinMode(R_INDICATOR_INPUT, INPUT);
}

void loop() {

	// Read the state of the inputs
	bool brakeInput = digitalRead(BRAKE_INPUT);
	bool LIndicatorInput = digitalRead(L_INDICATOR_INPUT);
	bool RIndicatorInput = digitalRead(R_INDICATOR_INPUT);
	
	// Brake lights
	if (brakeInput) {
		fill_solid(l_brake_leds, NUM_LEDS, CRGB::Red);
		fill_solid(r_brake_leds, NUM_LEDS, CRGB::Red);
	}
	else {
		fill_solid(l_brake_leds, NUM_LEDS, CRGB::Black);
		fill_solid(r_brake_leds, NUM_LEDS, CRGB::Black);
	}

	// Indicators
	if (LIndicatorInput && !RIndicatorInput) {
		indicatorAnimation(l_indicator_leds);
	}
	
	else if (RIndicatorInput && !LIndicatorInput) {
		indicatorAnimation(r_indicator_leds);
	}
	
	// Hazards
	else if (LIndicatorInput && RIndicatorInput) {
		fill_solid(l_indicator_leds, NUM_LEDS, CRGB::Orange);
		fill_solid(r_indicator_leds, NUM_LEDS, CRGB::Orange);
	}
	
	else {
		fill_solid(l_indicator_leds, NUM_LEDS, CRGB::Black);
		fill_solid(r_indicator_leds, NUM_LEDS, CRGB::Black);
		indicatorLEDsLit = 0;
	}

	FastLED.show();
}

void indicatorAnimation(CRGB *leds) {
	for (int i = 0; i < indicatorLEDsLit; i++) {
		leds[i] = CRGB::Orange;
	}
	
	EVERY_N_MILLISECONDS(INDICATOR_MS) {
		indicatorLEDsLit++;
		if (indicatorLEDsLit > NUM_LEDS) indicatorLEDsLit = NUM_LEDS;
	}
}
