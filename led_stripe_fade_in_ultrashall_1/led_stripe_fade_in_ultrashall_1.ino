#include "SR04.h"
#define TRIG_PIN 13
#define ECHO_PIN 12

const int ledRed =9;
const int ledGreen =11;
const int ledBlue =10;
const int ownDelay =1000;

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
const int d = 300;
long a;

void setup() {
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  a=sr04.Distance();
  Serial.print(a); Serial.println("cm");
  //if(a > 0 && a <= 210){
    Serial.println("red");
    setColor(255 -a%256,a%256,0, a%256);  
  //}
  /*if(a > 100 && a <=200){
    Serial.println("green");
    setColor(0,0,255, d);  
  }
  if(a > 210 && a <=400){
    Serial.println("blue");
    setColor(0,0,255, 0);  
  }
  /*if(a > 300){
    Serial.println("violett");
    setColor(255, 0, 255, d);  
  }*/
  
}

void setColor(int r, int g, int b, int d){
  analogWrite(ledRed, r);
  analogWrite(ledGreen, g);
  analogWrite(ledBlue, b); 
  delay(d) ;
}

void resetColor(){
  setColor(0,0,0, d);
}







