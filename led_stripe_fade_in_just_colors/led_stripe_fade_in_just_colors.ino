
const int ledRed =9;
const int ledGreen =11;
const int ledBlue =10;
const int ownDelay =1000;


const int d = 2000;

void setup() {
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledBlue,OUTPUT);
}


void loop() {
  setColor(200,0,0, d);
  setColor(0,50,0, d);
  setColor(0,0, 100, d);
  setColor(255,0,255, d);
  setColor(255, 20, 0, d);
  setColor(255, 15, 150, d);
  resetColor();
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




