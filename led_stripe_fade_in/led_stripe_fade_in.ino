
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
boolean show = true;

void loop() {
  int red = 150;
    int green = 255;
    int blue = 30;
  if(Serial.available()){
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();
    show=true;
  }
  if(show){
    int i = 0;
    while(i <= 255){
      if(i<=red){
        analogWrite(ledRed, i);  
      }
      if(i<=green){
        analogWrite(ledGreen, i);  
      }
      if(i<=blue){
        analogWrite(ledBlue, i);  
      }
      

//      Serial.println(i);
      delay(30);
      i = i+1;
    }

    show=false;
  }
    
  //  setStateAnalog(red, green, blue);
  
}


void setStateAnalog(int r, int g, int b){
  analogWrite(ledRed, r);
  analogWrite(ledGreen, g);
  analogWrite(ledBlue, b);
}

