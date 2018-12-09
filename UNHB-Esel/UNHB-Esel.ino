// DotStarTest
// This example will cycle between showing four pixels as Red, Green, Blue, White
// and then showing those pixels as Black.
//
// There is serial output of the current state so you can confirm and follow along
//

#include <ESP8266WiFi.h>
#include <NeoPixelBus.h>

#define colorSaturation 64

char test[][64] = { { 0, 0, 1, 1, 1, 1, 0, 0,
                      0, 1, 0, 0, 0, 0, 1, 0,
                      1, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 1, 1, 0, 1,
                      1, 0, 0, 0, 1, 1, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 1,
                      0, 1, 0, 0, 0, 0, 1, 0,
                      0, 0, 1, 1, 1, 1, 0, 0 },

                    { 0, 0, 1, 1, 1, 1, 0, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      1, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 1, 1, 0, 1,
                      1, 0, 0, 0, 1, 1, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 1,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 1, 1, 1, 1, 0, 0 },

                    { 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 1, 1, 1, 1, 0, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      1, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 1,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 1, 1, 1, 1, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0 },
                      
                    { 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      1, 1, 1, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 1,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0 },
                       
                    { 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      1, 1, 1, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 1,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0 } };

char test2[] =  { 0x01, 0x23, 0x45, 0x67,
                  0x89, 0xAB, 0xCD, 0xEF,
                  0x00, 0x11, 0x22, 0x33,
                  0x44, 0x55, 0x66, 0x77,
                  0x88, 0x99, 0xAA, 0xBB,
                  0xCC, 0xDD, 0xEE, 0xFF,
                  0xFE, 0xDC, 0xBA, 0x98,
                  0x76, 0x54, 0x32, 0x10 };

char colorMap[] = { 0x00, 0x00, 0x00,
                    0x19, 0x10, 0x28,
                    0x46, 0xaf, 0x45, 
                    0xa1, 0xd6, 0x85,
                    0x45, 0x3e, 0x78,
                    0x76, 0x64, 0xfe,
                    0x83, 0x31, 0x29,
                    0x9e, 0xc2, 0xe8,
                    0xdc, 0x53, 0x4b,
                    0xe1, 0x8d, 0x79,
                    0xd6, 0xb9, 0x7b,
                    0xe9, 0xd8, 0xa1,
                    0x21, 0x6c, 0x4b,
                    0xd3, 0x65, 0xc8,
                    0xaf, 0xaa, 0xb9,
                    0xf5, 0xf4, 0xeb };
                    
RgbColor[16] c;

for(char i=0; i<16; i++) {
  c[i] = new RgbColor(i*3; i*3+1; i*3+2);
}

// Define Pin for Sensor - I use GPIO0, wich is D3 on WEMOS
// #define DHTPIN 0

const uint16_t PixelCount = 64; // this example assumes 4 pixels, making it smaller will cause a failure

// make sure to set this to the correct pins
// D4 = Din
// D3 = Cin
const uint8_t DotClockPin = 5;
const uint8_t DotDataPin = 4;

// for software bit bang
NeoPixelBus<DotStarBgrFeature, DotStarMethod> strip(PixelCount, DotClockPin, DotDataPin);

// for hardware SPI (best performance but must use hardware pins)
//NeoPixelBus<DotStarBgrFeature, DotStarSpiMethod> strip(PixelCount);

// DotStars that support RGB color and a overall luminance/brightness value
// NeoPixelBus<DotStarLbgrFeature, DotStarMethod> strip(PixelCount, DotClockPin, DotDataPin);
// DotStars that support RGBW color with a seperate white element
//NeoPixelBus<DotStarWbgrFeature, DotStarMethod> strip(PixelCount, DotClockPin, DotDataPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

// for use with RGB DotStars when using the luminance/brightness global value
// note that its range is only 0 - 31 (31 is full bright) and
// also note that it is not useful for POV displays as it will cause more flicker
RgbwColor redL(colorSaturation, 0, 0, 16); // use white value to store luminance
RgbwColor greenL(0, colorSaturation, 0, 16); // use white value to store luminance
RgbwColor blueL(0, 0, colorSaturation, 16); // use white value to store luminance
RgbwColor whiteL(255, 255, 255, colorSaturation / 8); // luminance is only 0-31

void setup()
{
  Serial.begin(115200);
  while (!Serial); // wait for serial attach

  Serial.println();
  Serial.println("Initializing...");
  Serial.flush();

  // this resets all the neopixels to an off state
  strip.Begin();
  strip.ClearTo(black);
  strip.Show();

  Serial.println();
  Serial.println("Running...");
}


void loop()
{
  // turn off the pixels
  for (int n = 0; n < strip.PixelCount(); n++) {
    strip.SetPixelColor(n, black);
  }

  // set the colors,
  int brigtness = 32;
  
  for(int frame=0; frame<5; frame++) {
    for(int n=0; n<strip.PixelCount(); n++) {
       if(test[frame][n]) strip.SetPixelColor(n, RgbColor(brigtness));
       else strip.SetPixelColor(n, RgbColor(0));
    }
    strip.Show(); delay(20);
  }
  delay(100);
  for(int frame=3; frame>=0; frame--) {
    for(int n=0; n<strip.PixelCount(); n++) {
       if(test[frame][n]) strip.SetPixelColor(n, RgbColor(brigtness));
       else strip.SetPixelColor(n, RgbColor(0));
    }
    strip.Show(); delay(20);
  }
  delay(3000);

  Serial.println("Off ...");

  // turn off the pixels
  //for(int n=0; n<strip.PixelCount(); n++) {
  //  strip.SetPixelColor(n, black);
  // }
  // strip.Show();
}
