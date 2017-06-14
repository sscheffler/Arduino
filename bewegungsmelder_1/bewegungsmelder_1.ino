

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 12; // Eingang für HC-S501
int pirValue; // Platz zum Speichern des PIR-Wertes


void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);  
}

void loop() {
  pirValue = digitalRead(pirPin);
  
    digitalWrite(ledPin, pirValue);
    Serial.println(pirValue);
    delay(1000);
}
