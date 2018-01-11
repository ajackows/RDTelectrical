double voltage = 0;
void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT);
}

void loop() {
  if(digitalRead(0) == HIGH) {
    Serial.println("High BItCh");
  } else {
    Serial.println("Low hO3");
  }
  delay(1000);
}
