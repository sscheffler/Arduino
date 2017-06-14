
const int ledRed =10;
const int ledGreen =11;
const int ledBlue =9;
const int ownDelay =1000;
int pirPin = 12;
int pirValue = 0;

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
    setStateAnalog(255,0,0);
    Serial.println("Sensor active");
  } else {
    setStateAnalog(0,0,255);
    Serial.println("Sensor not active");
  }
  delay(500);  
}


void setStateAnalog(int r, int g, int b){
  analogWrite(ledRed, r);
  analogWrite(ledGreen, g);
  analogWrite(ledBlue, b);
}

