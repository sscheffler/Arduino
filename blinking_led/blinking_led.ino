
const int led =9;
const int ownDelay =1000;
void setup() {
  pinMode(led,OUTPUT);

}

void loop() {
  digitalWrite(led, HIGH);
  delay(ownDelay);
  digitalWrite(led, LOW);
  delay(ownDelay);
}
