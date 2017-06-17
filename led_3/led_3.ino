// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

// < 20

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

#define delayLed 0
#define timeOffset 10000

boolean isUp=false;
int pirPin = 12;
int pirPin_2 = 11;
unsigned long startTime = 0;

//bright white: 255,172,68
// deeper: 200,42,10


void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(pirPin_2, INPUT);
  pinMode(13, OUTPUT);
  pixels.begin();
}

void loop() {
  int movingSensor = digitalRead(pirPin);
  int movingSensor_2 = digitalRead(pirPin_2);

/*if(movingSensor==HIGH && !isUp){
  Serial.print(movingSensor);
  Serial.print("-");
  Serial.println(movingSensor_2);
}*/
  
  
  //Serial.println(movingSensor);
  if(delayExceeded()){
   if ((movingSensor == HIGH || movingSensor_2 == HIGH) && !isUp) {
    Serial.print(movingSensor);
    Serial.print("-");
    Serial.println(movingSensor_2);
      startTime=millis();
      on();
      isUp=true;
    } else if(isUp) {
      digitalWrite(13, LOW);
      off();
      isUp=false;
    }
  } else if(movingSensor == HIGH || movingSensor_2 == HIGH) {
    startTime=millis();
  }
}

boolean delayExceeded(){
  return (millis() - startTime) > timeOffset;
}

void on(){
  Serial.println("up");
  digitalWrite(13, HIGH);
  for(int i=0;i<NUMPIXELS;i++){
     //pixels.setPixelColor(i, pixels.Color(255,172,68));
     pixels.setPixelColor(i, pixels.Color(200,42,10));
     delay(delayLed);
  }
  pixels.show();
}

void off(){
  Serial.println("down");
  digitalWrite(13, LOW);
    for(int i=0;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, pixels.Color(0,0,0));
     }
     pixels.show();
}


