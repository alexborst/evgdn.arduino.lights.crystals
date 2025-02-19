//#include <DMXSerial.h>
#include <Conceptinetics.h>
#include <SoftwareSerial.h>
#include "LPD8806.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif


///////////// VARIABLES /////////

// Number of RGB LEDs in strand:
int nLEDs = 20;

// Set Clock and Data pins

///// STRIP 1 /////
int stripNo1 = 1;
int dataPin1  = 12;
int clockPin1 = 11;
int dmxFunctionChannel1 = 1;
int dmxRColorChannel1 = 2;
int dmxGColorChannel1 = 3;
int dmxBColorChannel1 = 4;

///// STRIP 2 /////
int stripNo2 = 2;
int dataPin2  = 10;
int clockPin2 = 9;
int dmxFunctionChannel2 = 5;
int dmxRColorChannel2 = 6;
int dmxGColorChannel2 = 7;
int dmxBColorChannel2 = 8;

///// STRIP 3 /////
int stripNo3 = 3;
int dataPin3  = 8;
int clockPin3 = 7;
int dmxFunctionChannel3 = 9;
int dmxRColorChanne3 = 10;
int dmxGColorChannel3 = 11;
int dmxBColorChannel3 = 12;

///// STRIP 4 /////
int stripNo4 = 4;
int dataPin4  = 6;
int clockPin4 = 5;
int dmxFunctionChannel4 = 13;
int dmxRColorChannel4 = 14;
int dmxGColorChannel4 = 15;
int dmxBColorChannel4 = 16;


int lightFunction1 = 0;
int rColor1 = 0;
int gColor1 = 0;
int bColor1 = 0;


int lightFunction2 = 0;
int rColor2 = 0;
int gColor2 = 0;
int bColor2 = 0;

int lightFunction3 = 0;
int rColor3 = 0;
int gColor3 = 0;
int bColor3 = 0;

int lightFunction4 = 0;
int rColor4 = 0;
int gColor4 = 0;
int bColor4 = 0;

//#define SLAVE_CHANNELS 1

DMX_Slave dmx_slave(1);

LPD8806 strip1 = LPD8806(nLEDs, dataPin1, clockPin1);
LPD8806 strip2 = LPD8806(nLEDs, dataPin2, clockPin2);
LPD8806 strip3 = LPD8806(nLEDs, dataPin3, clockPin3);
LPD8806 strip4 = LPD8806(nLEDs, dataPin4, clockPin4);

///////////// END VARIABLES /////////



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


  // Enable DMX slave interface and start recording
  // DMX data
  dmx_slave.enable();

  // Set start address to 1, this is also the default setting
  // You can change this address at any time during the program
  dmx_slave.setStartAddress(1);
}

void loop() {
  ///// STRIP FUNCTIONS /////
  // 1. setWholeStrip
  // 2. rainbow
  // 3. rainbowCycle
  // 4. colorWipe 
  // 5. colorChase
  // 6. theaterChase
  // 7. theaterChaseRainbow


  callStripFuntion(2, 2, strip1.Color(0, 127, 0)); // Green
  callStripFuntion(3, 2, strip1.Color(0, 0, 127)); // Blue
  callStripFuntion(4, 2, strip1.Color(127,   0, 0)); // Red

    // Check if new DMX data has been received
    // ///// STRIP 1 /////
    lightFunction1 = dmx_slave.getChannelValue(dmxFunctionChannel1);
    rColor1 = dmx_slave.getChannelValue(dmxRColorChannel1);
    gColor1 = dmx_slave.getChannelValue(dmxGColorChannel1);
    bColor1 = dmx_slave.getChannelValue(dmxBColorChannel1);
    callStripFuntion(stripNo1, lightFunction1, strip1.Color(rColor1, gColor1, bColor1));

    // ///// STRIP 2 /////
    lightFunction2 = dmx_slave.getChannelValue(dmxFunctionChannel2);
    rColor2 = dmx_slave.getChannelValue(dmxRColorChannel2);
    gColor2 = dmx_slave.getChannelValue(dmxGColorChannel2);
    bColor2 = dmx_slave.getChannelValue(dmxBColorChannel2);
    callStripFuntion(stripNo2, lightFunction2, strip2.Color(rColor2, gColor2, bColor2));

    // ///// STRIP 3 /////


    // ///// STRIP 4 /////
    
}

void callStripFuntion(int stripNo, int lightFunction, uint32_t color)
{
  double wait = 50;

  switch (lightFunction) {
    case 1:
      setWholeStrip(stripNo, color);
      break;
    case 2:
      rainbow(stripNo, wait);
      break;
    case 3:
      rainbowCycle(stripNo, wait);
      break;
    case 4:
      colorWipe(stripNo, color, wait);
      break;
    case 5:
      colorChase(stripNo, color, wait);
      break;
    case 6:
      theaterChase(stripNo, color, wait);
      break;
    case 7:
      theaterChaseRainbow(stripNo, wait);
      break;
    default:
      // statements
      break;
  }
}

///// FUNCTION 1 /////
void setWholeStrip(int stripNo, uint32_t c) {
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }

  int i;

  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
  }
}

///// FUNCTION 2 /////
void rainbow(int stripNo, uint8_t wait) {
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }
  
  int i, j;
  for (j=0; j < 384; j++) {     // 3 cycles of all 384 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(stripNo, (i + j) % 384));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

///// FUNCTION 3 /////
// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(int stripNo, uint8_t wait) {
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }
  
  uint16_t i, j;
  for (j=0; j < 384 * 5; j++) {     // 5 cycles of all 384 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 384-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 384 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel(stripNo, ((i * 384 / strip.numPixels()) + j) % 384) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

///// FUNCTION 4 /////
// Fill the dots progressively along the strip.
void colorWipe(int stripNo, uint32_t c, uint8_t wait) {
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }
  
  int i;
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

///// FUNCTION 5 /////
// Chase one dot down the full strip.
void colorChase(int stripNo, uint32_t c, uint8_t wait) {
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }

  int i;
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

///// FUNCTION 6 /////
//Theatre-style crawling lights.
void theaterChase(int stripNo, uint32_t c, uint8_t wait) {
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }
 
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

///// FUNCTION 7 /////
//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(int stripNo, uint8_t wait) {
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }

  for (int j=0; j < 384; j++) {     // cycle all 384 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel(stripNo, (i+j) % 384));    //turn every third pixel on
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

void nonBlockingDelay(int milliseconds)
{
  unsigned long currentMillis = millis();
}


uint32_t Wheel(int stripNo, uint16_t WheelPos)
{
  LPD8806 strip = strip1;
  switch (stripNo) {
    case 1:
      strip = strip1;
      break;
    case 2:
      strip = strip2;
      break;
    case 3:
      strip = strip3;
      break;
    case 4:
      strip = strip4;
      break;
    default:
      // statements
      break;
  }

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

