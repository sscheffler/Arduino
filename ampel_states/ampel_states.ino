
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
}

void loop() {
  setState(states[actualStep]);
  delay(ownDelay);
  actualStep=(actualStep+1)%totalSteps;
}

void setState(const int state [3]){
  digitalWrite(ledRed, state[0]);
  digitalWrite(ledYellow, state[1]);
  digitalWrite(ledGreen, state[2]);
}

