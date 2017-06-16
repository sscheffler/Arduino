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
#define NUMPIXELS      48

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define delayLed 50
#define delayShutdown 1000
#define sleep 3000


#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

boolean isUp=false;
int forceShutdown=0;
int forceBorder=10;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);
  
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      int rec = mySwitch.getReceivedValue();
      if(rec == 8 && !isUp){
        Serial.println("up");
        for(int i=0;i<NUMPIXELS;i++){
           // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
           pixels.setPixelColor(i, pixels.Color(255,0,0)); // Moderately bright green color.
           pixels.show(); // This sends the updated pixel color to the hardware.
           delay(delayLed); // Delay for a period of time (in milliseconds).
        }
        isUp=true;
       // delay(sleep);
      } else if(rec == 2 && isUp){
        Serial.println("down");
        for(int i=0;i<NUMPIXELS;i++){
           // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
           pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
           pixels.show(); // This sends the updated pixel color to the hardware.
        }
        isUp=false;
      } else {
        Serial.print("Skipping: ");
        Serial.print(rec);
        Serial.print("/");
        Serial.println(isUp);}
    } 
    forceShutdown = 0;
    mySwitch.resetAvailable();
  } else {
    Serial.println("|");
    /*if(forceShutdown < forceBorder){
            forceShutdown = forceShutdown+1;
            delay(delayShutdown);
          } else { 
            Serial.println("shut down");
            for(int i=0;i<NUMPIXELS;i++){
              // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
              pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
              pixels.show(); // This sends the updated pixel color to the hardware.
            }
            forceShutdown = 0;
          }*/
  }
}
