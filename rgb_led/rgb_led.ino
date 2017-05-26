
const int ledGreen =9;
const int ledYellow =10;
const int ledRed =11;
const int ownDelay =1000;

const int states [][3] = {
  {1,0,0},
  {1,1,0},
  {0,0,1},
  {0,1,0}};
const int totalSteps=4;
int actualStep=0;

void setup() {
  pinMode(ledGreen,OUTPUT);
  pinMode(ledYellow,OUTPUT);
  pinMode(ledRed,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter R G B (E.g. 255 100 200)");
}

const int s [3] ={0,0,1};

void loop() {
  if(Serial.available()){
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    Serial.println(red);
    Serial.println(green);
    Serial.println(blue);
    setStateAnalog(red, green, blue);
  }
}

void setStateDigital(const int state [3]){
  digitalWrite(ledRed, state[0]);
  digitalWrite(ledYellow, state[1]);
  digitalWrite(ledGreen, state[2]);
}

void setStateAnalog(int r, int g, int b){
  analogWrite(ledRed, r);
  analogWrite(ledYellow, g);
  analogWrite(ledGreen, b);
}

