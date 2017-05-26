
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


void loop() {
  int red = 255;
  int green = 255;
  int blue = 255;
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  while(i <= 255){
      analogWrite(ledRed, i);  
      delay(30);
      i = i+1;
  }

  while(j <= 255){
      analogWrite(ledBlue, j);  
      delay(30);
      j = j+1;
  }
  analogWrite(ledBlue, l);  
  while(k <= 255){
      analogWrite(ledGreen, k);  
      delay(30);
      k = k+1;
  }
  analogWrite(ledGreen, 0);  
  while(l <= 255){
      analogWrite(ledRed, l);  
      analogWrite(ledBlue, l);  
      delay(30);
      l = l+1;
  }
  analogWrite(ledRed, 0);  
  analogWrite(ledBlue, 0);  

  
  
}




