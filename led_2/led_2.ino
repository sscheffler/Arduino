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
//48

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define delayLed 50
#define delayShutdown 1000
#define sleep 10000


boolean isUp=false;
int forceShutdown=0;
int forceBorder=10;
int pirPin = 12;
int pirPin_2 = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(pirPin_2, INPUT);
  pinMode(13, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  int movingSensor = digitalRead(pirPin);
  int movingSensor_2 = digitalRead(pirPin_2);
  Serial.print(movingSensor);
  Serial.print("-");
  Serial.println(movingSensor_2);
  
  if ((movingSensor == HIGH || movingSensor_2 == HIGH) && !isUp) {
    digitalWrite(13, HIGH);
        Serial.println("up");
        for(int i=0;i<NUMPIXELS;i++){
           // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
           //pixels.setPixelColor(i, pixels.Color(255,172,68)); // warm white
           pixels.setPixelColor(i, pixels.Color(200,42,10)); // more eye friendly
           pixels.show(); // This sends the updated pixel color to the hardware.
           delay(delayLed); // Delay for a period of time (in milliseconds).
        }
        isUp=true; 
        //delay(sleep);
  } else if(movingSensor == 0 && isUp) {
  //  delay(sleep);
    Serial.println("down");
    digitalWrite(13, LOW);
    for(int i=0;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
         pixels.show(); // This sends the updated pixel color to the hardware.
     }
     isUp=false;
  }
}
