// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS     10

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define delayLed 50
#define delayShutdown 1000
#define sleep 3000

void setup() {
  Serial.begin(9600);
    pinMode(13, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
  for(int i=0;i<NUMPIXELS;i++){
       // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
       //255,172,68
       pixels.setPixelColor(i, pixels.Color(200,40,10)); // Moderately bright green color.
       
      }
      pixels.show();
}

void loop() {
  digitalWrite(13, HIGH);
  //pixels.setPixelColor(12, pixels.Color(0,255,255)); // Moderately bright green color.
    for(int j=10;j>=0;j--){
      for(int i=0;i<NUMPIXELS;i++){
       // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
       //255,172,68
       pixels.setPixelColor(i, pixels.Color(20*j,4*j,j)); // Moderately bright green color.
       
      }
      pixels.show(); // This sends the updated pixel color to the hardware.
       delay(30);  
    }

  
  
        
}
