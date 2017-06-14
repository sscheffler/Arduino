/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
  
}
#define INTERTECH_ON  "00000000000101010001010101010100" 
#define INTERTECH_OFF "00000000000101010001010001010100"
void loop() {
  mySwitch.send(INTERTECH_ON);
  delay(1000); 
  mySwitch.send(INTERTECH_OFF);
  delay(60000);
}
