// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
int LIGHT_PIN = A0;
#define NUMPIXELS     16

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
}

void loop() {
  //digitalWrite(13, HIGH);
  int val = analogRead(LIGHT_PIN);
  Serial.println(val);
  //pixels.setPixelColor(12, pixels.Color(0,255,255)); 
  /*if(val < 40){
    pixels.setPixelColor(0, pixels.Color(255, 0, 0)); 
  } 
  if(val < 30){
    pixels.setPixelColor(1, pixels.Color(255, 0, 0)); 
  }
  if(val < 20){
    pixels.setPixelColor(2, pixels.Color(255, 0, 0)); 
  }
  if(val < 10){
    pixels.setPixelColor(3, pixels.Color(255, 0, 0)); 
  }
  if(val >= 40){
    pixels.setPixelColor(5, pixels.Color(0, 255, 0)); 
  }
  pixels.show();*/

  pixels.setPixelColor(0, pixels.Color(255,172,68)); // Moderately bright green color.
  //pixels.setPixelColor(13, pixels.Color(255,172,68)); // Moderately bright green color.
  //pixels.setPixelColor(14, pixels.Color(255,172,68)); // Moderately bright green color.
  pixels.setPixelColor(15, pixels.Color(200,42,10)); // Moderately bright green color.
  pixels.show();
  for(int i=0;i<4;i++){
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
     //255,172,68
     pixels.setPixelColor(i, pixels.Color(200,42,10)); // Moderately bright green color.
     pixels.show(); // This sends the updated pixel color to the hardware.
     //delay(100);
  }
        
}
