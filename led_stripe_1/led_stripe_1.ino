
const int ledRed =10;
const int ledGreen =11;
const int ledBlue =9;
const int ownDelay =1000;




void setup() {
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter R G B (E.g. 255 100 200)");
}

const int s [3] ={0,0,1};

void loop() {
  if(Serial.available()){
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    
    setStateAnalog(red, green, blue);
  }
}


void setStateAnalog(int r, int g, int b){
  analogWrite(ledRed, r);
  analogWrite(ledGreen, g);
  analogWrite(ledBlue, b);
}

