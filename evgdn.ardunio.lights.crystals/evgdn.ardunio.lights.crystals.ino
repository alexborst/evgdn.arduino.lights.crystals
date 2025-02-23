#include "LPD8806.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

// Example to control LPD8806-based RGB LED Modules in a strip

/*****************************************************************************/

// Number of RGB LEDs in strand:
int nLEDs = 20;

// Set Clock and Data pins
int dataPin1  = 12;
int clockPin1 = 11;

int dataPin2  = 10;
int clockPin2 = 9;

int dataPin3  = 8;
int clockPin3 = 7;

int dataPin4  = 6;
int clockPin4 = 5;


// First parameter is the number of LEDs in the strand.  The LED strips
// are 32 LEDs per meter but you can extend or cut the strip.  Next two
// parameters are SPI data and clock pins:
LPD8806 strip1 = LPD8806(nLEDs, dataPin1, clockPin1);
LPD8806 strip2 = LPD8806(nLEDs, dataPin2, clockPin2);
LPD8806 strip3 = LPD8806(nLEDs, dataPin3, clockPin3);
LPD8806 strip4 = LPD8806(nLEDs, dataPin4, clockPin4);


// You can optionally use hardware SPI for faster writes, just leave out
// the data and clock pin parameters.  But this does limit use to very
// specific pins on the Arduino.  For "classic" Arduinos (Uno, Duemilanove,
// etc.), data = pin 11, clock = pin 13.  For Arduino Mega, data = pin 51,
// clock = pin 52.  For 32u4 Breakout Board+ and Teensy, data = pin B2,
// clock = pin B1.  For Leonardo, this can ONLY be done on the ICSP pins.
//LPD8806 strip = LPD8806(nLEDs);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  // Start up the LED strip
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();

  // Update the strip, to start they are all 'off'
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();  
}


void loop() {

  // Send a simple pixel chase in...
  // colorChase(1, strip1.Color(127, 127, 127), 50); // White
  // colorChase(2, strip2.Color(127, 127, 127), 50); // White
  // colorChase(3, strip3.Color(127, 127, 127), 50); // White
  // colorChase(4, strip4.Color(127, 127, 127), 50); // White

  // colorChase(1, strip1.Color(127,   0,   0), 50); // Red
  // colorChase(2, strip2.Color(127,   0,   0), 50); // Red
  // colorChase(3, strip3.Color(127,   0,   0), 50); // Red
  // colorChase(4, strip4.Color(127,   0,   0), 50); // Red

  // colorChase(1, strip1.Color(127, 127,   0), 50); // Yellow  
  // colorChase(2, strip2.Color(127, 127,   0), 50); // Yellow
  // colorChase(3, strip3.Color(127, 127,   0), 50); // Yellow  
  // colorChase(4, strip4.Color(127, 127,   0), 50); // Yellow

  // colorChase(1, strip1.Color(  0, 127,   0), 50); // Green
  // colorChase(2, strip2.Color(  0, 127,   0), 50); // Green
  // colorChase(3, strip3.Color(  0, 127,   0), 50); // Green
  // colorChase(4, strip4.Color(  0, 127,   0), 50); // Green

  // colorChase(1, strip1.Color(  0, 127, 127), 50); // Cyan
  // colorChase(2, strip1.Color(  0, 127, 127), 50); // Cyan  
  // colorChase(3, strip1.Color(  0, 127, 127), 50); // Cyan
  // colorChase(4, strip1.Color(  0, 127, 127), 50); // Cyan  

  // colorChase(1, strip1.Color(  0,   0, 127), 50); // Blue
  // colorChase(2, strip1.Color(  0,   0, 127), 50); // Blue
  // colorChase(3, strip1.Color(  0,   0, 127), 50); // Blue
  // colorChase(4, strip1.Color(  0,   0, 127), 50); // Blue

  colorChase(1, strip1.Color(127,   0, 127), 50); // Violet
  colorChase(2, strip1.Color(127,   0, 127), 50); // Violet
  colorChase(3, strip1.Color(127,   0, 127), 50); // Violet
  colorChase(4, strip1.Color(127,   0, 127), 50); // Violet

  rainbowCycle(1, 0);  // make it go through the cycle fairly fast
  rainbowCycle(2, 0);  // make it go through the cycle fairly fast
  rainbowCycle(3, 0);  // make it go through the cycle fairly fast
  rainbowCycle(4, 0);  // make it go through the cycle fairly fast

  // // Send a theater pixel chase in...
  // theaterChase(strip1.Color(127, 127, 127), 50); // White
  // theaterChase(strip1.Color(127,   0,   0), 50); // Red
  // theaterChase(strip1.Color(127, 127,   0), 50); // Yellow
  // theaterChase(strip1.Color(  0, 127,   0), 50); // Green
  // theaterChase(strip1.Color(  0, 127, 127), 50); // Cyan
  // theaterChase(strip1.Color(  0,   0, 127), 50); // Blue
  // theaterChase(strip1.Color(127,   0, 127), 50); // Violet

  // // Fill the entire strip with...
  // colorWipe(strip1.Color(127,   0,   0), 50);  // Red
  // colorWipe(strip1.Color(  0, 127,   0), 50);  // Green
  // colorWipe(strip1.Color(  0,   0, 127), 50);  // Blue

  // rainbow(1, 10);
  // rainbow(2, 10);
  // rainbow(3, 10);
  // rainbow(4, 10);




  // theaterChaseRainbow(50);
}

void rainbow(int stripNo, uint8_t wait) {
  int i, j;

  LPD8806 strip = LPD8806(20);
  switch (stripNo) {
    case 1:
      strip.updatePins(dataPin1, clockPin1);
      break;
    case 2:
      strip.updatePins(dataPin2, clockPin2);
      break;
    case 3:
      strip.updatePins(dataPin3, clockPin3);
      break;
    case 4:
      strip.updatePins(dataPin4, clockPin4);
      break;
    default:
      strip.updatePins(dataPin1, clockPin1);
      break;
  }

   
  for (j=0; j < 384; j++) {     // 3 cycles of all 384 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 384));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(int stripNo, uint8_t wait) {
  uint16_t i, j;


  LPD8806 strip = LPD8806(20);
  switch (stripNo) {
    case 1:
      strip.updatePins(dataPin1, clockPin1);
      break;
    case 2:
      strip.updatePins(dataPin2, clockPin2);
      break;
    case 3:
      strip.updatePins(dataPin3, clockPin3);
      break;
    case 4:
      strip.updatePins(dataPin4, clockPin4);
      break;
    default:
      strip.updatePins(dataPin1, clockPin1);
      break;
  }

  for (j=0; j < 384 * 5; j++) {     // 5 cycles of all 384 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 384-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 384 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 384 / strip.numPixels()) + j) % 384) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// Fill the dots progressively along the strip.
void colorWipe(uint32_t c, uint8_t wait) {
  int i;

  LPD8806 strip = strip1;
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

// Chase one dot down the full strip.
void colorChase(int stripNo, uint32_t c, uint8_t wait) {
  int i;

  LPD8806 strip = LPD8806(20);
  switch (stripNo) {
    case 1:
      strip.updatePins(dataPin1, clockPin1);
      break;
    case 2:
      strip.updatePins(dataPin2, clockPin2);
      break;
    case 3:
      strip.updatePins(dataPin3, clockPin3);
      break;
    case 4:
      strip.updatePins(dataPin4, clockPin4);
      break;
    default:
      strip.updatePins(dataPin1, clockPin1);
      break;
  }

  // Start by turning all pixels off:
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);

  // Then display one pixel at a time:
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(i, 0); // Erase pixel, but don't refresh!
    delay(wait);
  }

  strip.show(); // Refresh to turn off last pixel
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  
  LPD8806 strip = strip1;
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip1.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  
  LPD8806 strip = strip1;
  for (int j=0; j < 384; j++) {     // cycle all 384 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 384));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}
/* Helper functions */

//Input a value 0 to 384 to get a color value.
//The colours are a transition r - g -b - back to r

uint32_t Wheel(uint16_t WheelPos)
{
  
  LPD8806 strip = strip1;
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128;   //Red down
      g = WheelPos % 128;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 127 - WheelPos % 128;  //green down
      b = WheelPos % 128;      //blue up
      r = 0;                  //red off
      break; 
    default:
      b = 127 - WheelPos % 128;  //blue down 
      r = WheelPos % 128;      //red up
      g = 0;                  //green off
      break; 
  }
  return(strip.Color(r,g,b));
}
