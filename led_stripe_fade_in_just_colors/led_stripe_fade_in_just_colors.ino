
const int ledRed =10;
const int ledGreen =11;
const int ledBlue =9;
const int ownDelay =1000;




void setup() {
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledBlue,OUTPUT);
}


void loop() {
  analogWrite(ledRed, 255);  
  delay(50);
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 255);  
  delay(50);
  analogWrite(ledBlue, 0);
  analogWrite(ledGreen, 255);  
  delay(50);
  analogWrite(ledGreen, 0);
  analogWrite(ledRed, 255);
  analogWrite(ledBlue, 255);  
  delay(50);
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 0);  
  
}




