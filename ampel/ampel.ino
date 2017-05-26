
const int ledGreen =9;
const int ledYellow =10;
const int ledRed =11;
const int ownDelay =1000;
void setup() {
  pinMode(ledGreen,OUTPUT);
  pinMode(ledYellow,OUTPUT);
  pinMode(ledRed,OUTPUT);
}

void loop() {
  setState(1, 0, 0);
  delay(ownDelay);
  setState(1, 1, 0);
  delay(ownDelay);
  setState(0, 0, 1);
  delay(ownDelay);
  setState(0, 1, 0);
  delay(ownDelay);
}

void setState(int r, int y, int g){
  digitalWrite(ledGreen, g);
  digitalWrite(ledYellow, y);
  digitalWrite(ledRed, r);
}

