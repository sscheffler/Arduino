#include <avr/wdt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
#define LIGHT_PIN      A0
#define PIN_STATUS     7

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      48
#define NUMPIXELS_STATUS      1
//48

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel statusPixels = Adafruit_NeoPixel(NUMPIXELS_STATUS, PIN_STATUS, NEO_GRB + NEO_KHZ800);

#define delayLed 30
#define timeOffset 10000

boolean isUp=false;
int pirPin = 12;
int pirPin_2 = 11;
unsigned long startTime = 0;

//bright white: 255,172,68
// deeper: 200,40,10


void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(pirPin_2, INPUT);
  pinMode(13, OUTPUT);
  pixels.begin();
  statusPixels.begin();
  digitalWrite(13, LOW);
  prepareTimer();
}

void loop() {
  int lightSensor = analogRead(LIGHT_PIN);
  int movingSensor = digitalRead(pirPin);
  int movingSensor_2 = digitalRead(pirPin_2);

  if(lightSensor < 25){
    Serial.println(lightSensor);
    
    
    // giving a range of 5 [see els if] to avoid alternating states 
    if(delayExceeded()){
      //statusPixels.setPixelColor(0, pixels.Color(0,0,10));
      statusPixels.setPixelColor(0, pixels.Color(0,0,0));
      statusPixels.show();
      if ((movingSensor == HIGH || movingSensor_2 == HIGH) && !isUp) {
        statusPixels.setPixelColor(0, pixels.Color(0,10,0));
        //statusPixels.setPixelColor(0, pixels.Color(0,0,0));
        statusPixels.show();
        Serial.print(movingSensor);
        Serial.print("-");
        Serial.println(movingSensor_2);
        startTime=millis();
        on();
        isUp=true;
      } else {
        statusPixels.setPixelColor(0, pixels.Color(0,0,0));
        statusPixels.show();
        if(isUp) {
          //statusPixels.setPixelColor(0, pixels.Color(0,10,0));
        //statusPixels.show();
        
        off();
        isUp=false;
      }
        
      }
    } else if(movingSensor == HIGH || movingSensor_2 == HIGH) {
      resetDelay();
    }    
  } else if(lightSensor > 30) {
    //statusPixels.setPixelColor(0, pixels.Color(10,0,0));
    statusPixels.setPixelColor(0, pixels.Color(0,0,0));
    statusPixels.show();
    if(isUp) {
      off();  
      isUp=false;
    }
    sleep(360);
    startTime = startTime - (timeOffset+1);
  }

/*if(movingSensor==HIGH && !isUp){
  Serial.print(movingSensor);
  Serial.print("-");
  Serial.println(movingSensor_2);
}*/
  
  
  //Serial.println(movingSensor);
  
}

void resetDelay(){
  startTime=millis();
}

boolean delayExceeded(){
  return (millis() - startTime) > timeOffset;
}

void on(){
  Serial.println("up");
  for(int j=1;j<=10;j++){
    for(int i=0;i<NUMPIXELS;i++){
     pixels.setPixelColor(i, pixels.Color(20*j,4*j,j));
    }
    pixels.show();
    delay(delayLed);  
  }
}

void off(){
  Serial.println("down");
  for(int j=10;j>=0;j--){
      for(int i=0;i<NUMPIXELS;i++){
       pixels.setPixelColor(i, pixels.Color(20*j,4*j,j));
      }
      pixels.show();
       delay(delayLed);  
    }
}

void prepareTimer() {
  MCUSR &= ~(1<<WDRF);
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  WDTCSR =  WDTO_1S;
  WDTCSR |= 1<<WDIE;
}

void sleep(int seconds){
  for (int i = 0; i < seconds; i ++){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    power_adc_disable();
    power_spi_disable();
    power_timer0_disable();
    power_timer2_disable();
    power_twi_disable();  
    sleep_cpu();
    power_all_enable();
    sleep_disable();
  }
  
}
 
ISR(WDT_vect)
{
  return;
}
