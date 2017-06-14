#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int pirPin = 12;
int delayVal = 3000;

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(10);  // Using Pin #10
  pinMode(pirPin, INPUT);
}

void loop() {
  int movingSensor = digitalRead(pirPin);
  if(movingSensor == 1){
    Serial.println("led on");
    mySwitch.send("000000000000000000001000");
  } else {
    delay(delayVal);  
    Serial.println("led off");
    mySwitch.send("000000000000000000000010");
  }
}
