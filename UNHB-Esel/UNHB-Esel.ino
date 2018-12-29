// DotStarTest
// This example will cycle between showing four pixels as Red, Green, Blue, White
// and then showing those pixels as Black.
//
// There is serial output of the current state so you can confirm and follow along
//

#include <ESP8266WiFi.h>
#include <NeoPixelBus.h>
#include <NeoPixelBrightnessBus.h>
#include <FS.h>
#include "defaults.h"

char* filename = "/Blink_center_getAngry.c";

RgbColor *c[16];
RgbColor black(0);

const uint16_t PixelCount = 128; // Currently we have a 2x 8x8 matrix connected

// make sure to set this to the correct pins
// SPI Hardware Pins: CLK=GPIO14=Pin12=D5 (orange), MOSI=GPIO13=Pin13=D7 (yellow)
NeoPixelBrightnessBus<DotStarBgrFeature, DotStarSpiMethod> strip(PixelCount);
//NeoPixelBus<DotStarBgrFeature, DotStarSpiMethod> strip(PixelCount);

void setup() {
  Serial.begin(115200);
  while (!Serial); // wait for serial attach

  Serial.println();
  Serial.println("Initializing everything..."); Serial.flush();

  // this resets all the neopixels to an off state
  Serial.println("Switching off all LEDs");
  strip.Begin();
  strip.SetBrightness(brightness);
  strip.ClearTo(black);
  strip.Show();

  //Initialize File System
  if(SPIFFS.begin()) {
    Serial.println("SPIFFS Initialisierung....OK");
  } else {
    Serial.println("SPIFFS Initialisierung...Fehler!");
  }
 
  Serial.println();
  Serial.println("Loading default color map");
  loadColorMap(colorMap);
  
  Serial.println("\nSwitch to running...");

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
    for(int n=0; n<strip.PixelCount()/16; n++) {
       for(int i=0; i<8; i++) {
         if((anim[frame][n])&(1<<i)) {
            strip.SetPixelColor(i*8+n, RgbColor(brightness));
            strip.SetPixelColor(i*8+n+64, RgbColor(brightness));
         }
         else {
          strip.SetPixelColor(i*8+n, RgbColor(0));
          strip.SetPixelColor(i*8+n+64, RgbColor(0));
         }
       }
    }
    strip.Show(); delay(animDelay);
  }
}


void playMapAnimation(int animDelay, uint8_t anim[][32]) {
 for(int frame=0; frame<9; frame++) {
    for(int n=0; n<strip.PixelCount()/4; n++) {
      strip.SetPixelColor( 2*n  , *c[(anim[frame][n]>>4  )] );
      strip.SetPixelColor( 2*n+1, *c[(anim[frame][n]&0x0F)] );
      strip.SetPixelColor( 64+2*n  , *c[(anim[frame][n]>>4  )] );
      strip.SetPixelColor( 64+2*n+1, *c[(anim[frame][n]&0x0F)] );
    }
    strip.Show(); delay(animDelay);
  }
}

void loop() {  
  Serial.println("Entering loop ...");

  // turn off the pixels
  Serial.println("All off ...");
  strip.ClearTo(black);

  Serial.print("Framecounter of file: ");
  playFile("/Center.c",2000);
  playFile("/Blink_center.c", 100);
  playFile("/Move_left.c", 100);
  playFile("/Blink_left.c", 100);
  playFile("/Move_left_center.c", 100);
  playFile("/Blink_LSD_start.c", 100);
  playFile("/Blink_LSD.c", 100);
  playFile("/Blink_LSD.c", 100);
  playFile("/Blink_LSD_end.c", 100);
  playFile("/Blink_center.c", 100);
  playFile("/Move_right.c", 100);
  playFile("/Blink_right.c", 100);
  playFile("/Move_right_center.c", 100);
  playFile("/Blink_center_getAngry.c", 100);
  

/*  Serial.println("Animation test ...");
  playBwAnimation(50, eye_move_cr); delay(3000);
  playBwAnimation(50, eye_blink_r); delay(5000);
  playBwAnimation(50, eye_blink_r); delay(3000);
  playBwAnimation(50, eye_move_rc); delay(3000);
  playBwAnimation(50, eye_blink_c); delay(3000);
  playBwAnimation(50, eye_blink_c); delay(4000);
  playBwAnimation(50, eye_blink_c); delay(3000);
  playBwAnimation(50, eye_move_cl); delay(3000);
  playBwAnimation(50, eye_blink_l); delay(2000);
  playBwAnimation(50, eye_move_lc); delay(3000);*/

  /*playMapAnimation(150, terminator);delay(3000);*/

/*  for(int n=0; n<strip.PixelCount(); n++) {
    strip.SetPixelColor(n, 20 );
    strip.Show(); delay(100);
  }*/

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
