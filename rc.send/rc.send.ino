#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int pirPin = 12;
int delayVal = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(10);  // Using Pin #10
  pinMode(pirPin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int movingSensor = digitalRead(pirPin);
  if(movingSensor == 1){
    Serial.println("led on");
    mySwitch.send("000000000000000000001000");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    delay(delayVal);  
    Serial.println("led off");
    mySwitch.send("000000000000000000000010");
    digitalWrite(LED_BUILTIN, LOW);
  }
}
