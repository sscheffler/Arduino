// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
#define INPUT_PIN      9

#define NUMPIXELS     10
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define delayLed 50
#define delayShutdown 1000
#define sleep 3000

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  pixels.begin();
}

void loop() {
  int inputPin=digitalRead(INPUT_PIN);
  
  if(inputPin == HIGH){
    Serial.println(inputPin);
      for(int j=10;j>=0;j--){
        for(int i=0;i<NUMPIXELS;i++){
         pixels.setPixelColor(i, pixels.Color(5*j,4*j,j));
         
        }
        pixels.show();
         delay(30);  
      }
  }     
}
