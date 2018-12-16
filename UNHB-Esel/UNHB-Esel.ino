// DotStarTest
// This example will cycle between showing four pixels as Red, Green, Blue, White
// and then showing those pixels as Black.
//
// There is serial output of the current state so you can confirm and follow along
//

#include <ESP8266WiFi.h>
#include <NeoPixelBus.h>
#include <NeoPixelBrightnessBus.h>
#include "defaults.h"



char test2[] =  { 0x01, 0x23, 0x45, 0x67,
                  0x89, 0xAB, 0xCD, 0xEF,
                  0x00, 0x11, 0x22, 0x33,
                  0x44, 0x55, 0x66, 0x77,
                  0x88, 0x99, 0xAA, 0xBB,
                  0xCC, 0xDD, 0xEE, 0xFF,
                  0xFE, 0xDC, 0xBA, 0x98,
                  0x76, 0x54, 0x32, 0x10 };
                    
RgbColor *c[16];
RgbColor black(0);

const uint16_t PixelCount = 64; // Currently we have a 8x8 matrix connected

// make sure to set this to the correct pins
// SPI Hardware Pins: CLK=GPIO14=Pin12=D5 (orange), MOSI=GPIO13=Pin13=D7 (yellow)
NeoPixelBrightnessBus<DotStarBgrFeature, DotStarSpiMethod> strip(PixelCount);

void setup() {
  Serial.begin(115200);
  while (!Serial); // wait for serial attach

  Serial.println();
  Serial.println("Initializing..."); Serial.flush();

  // this resets all the neopixels to an off state
  strip.Begin();
  strip.SetBrightness(brightness);
  strip.ClearTo(black);
  strip.Show();

  Serial.println();

  loadColorMap(colorMap);
  
  Serial.println("Running...");

}

// loading ColorMap into color objects
void loadColorMap(uint8_t cmap[]) {
  for(int n=0; n<16; n++) {
     c[n] = new RgbColor(cmap[n*3], cmap[n*3+1], cmap[n*3+2]);
  }
}

// play a given sub-animation
void playBwAnimation(int animDelay, uint8_t anim[][8]) {
  
  for(int frame=0; frame<7; frame++) {
    for(int n=0; n<strip.PixelCount()/8; n++) {
       for(int i=0; i<8; i++) {
         if((anim[frame][n])&(1<<i)) strip.SetPixelColor(n*8+i, RgbColor(255));
         else strip.SetPixelColor(n*8+i, RgbColor(0));
       }
    }
    strip.Show(); delay(animDelay);
  }
}

void loop() {  
  Serial.println("Entering loop ...");

  // turn off the pixels
  Serial.println("All off ...");
  strip.ClearTo(black);

  Serial.println("Animation test ...");
  playBwAnimation(50, eye_move_cr); delay(3000);
  playBwAnimation(50, eye_blink_r); delay(5000);
  playBwAnimation(50, eye_blink_r); delay(3000);
  playBwAnimation(50, eye_move_rc); delay(3000);
  playBwAnimation(50, eye_blink_c); delay(3000);
  playBwAnimation(50, eye_blink_c); delay(4000);
  playBwAnimation(50, eye_blink_c); delay(3000);
  playBwAnimation(50, eye_move_cl); delay(3000);
  playBwAnimation(50, eye_blink_l); delay(2000);
  playBwAnimation(50, eye_move_lc); delay(3000);

/*  Serial.println("Colormap test ...");
  strip.ClearTo(black);
  for(int n=0; n<strip.PixelCount()/2; n++) {
    strip.SetPixelColor( 2*n  , *c[(test2[n]>>4  )] );
    strip.SetPixelColor( 2*n+1, *c[(test2[n]&0x0F)] );
    strip.Show(); delay(1000);
  }
  delay(10000);*/

  Serial.println("Loop end ...");
}
