
const int ledRed =10;
const int ledGreen =11;
const int ledBlue =9;
const int ownDelay =1000;
int pirPin = 12;
int pirValue = 0;
int fadeDelay=30;
int r=0, g=0, b=0 ;

void setup() {
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

const int s [3] ={0,0,1};

void loop() {
  pirValue = digitalRead(pirPin);
  if(pirValue==1){
    Serial.println("Sensor active");
    fadeUp(0,10,255);
  } else {
    Serial.println("Sensor not active");
    fadeUp(100,0,255);
  }
  delay(100);  
}


void fadeUp(int red, int green, int blue){
  if(r!=red ||b!=blue||g!=green){
  analogWrite(ledRed, 0);
  analogWrite(ledGreen, 0);
  analogWrite(ledBlue, 0);
    
    Serial.print("r:");Serial.print(red);
    Serial.print("; g:");Serial.print(green);
    Serial.print("; b:");Serial.println(blue);
    for (int i=0; i <= 255; i++){
      if(i<=red){
        analogWrite(ledRed, i);  
      }
      if(i<=green){
        analogWrite(ledGreen, i);  
      }
      if(i<=blue){
        analogWrite(ledBlue, i);  
      }
      delay(fadeDelay);
    }  
  } else {
    Serial.println("Skip fading");
  }
  r=red;g=green;b=blue; 
}


void setStateAnalog(int r, int g, int b){
  analogWrite(ledRed, r);
  analogWrite(ledGreen, g);
  analogWrite(ledBlue, b);
}

