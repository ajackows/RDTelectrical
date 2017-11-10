void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);                 //OUTPUT can also be 1 possibly
  }

void loop(){
  sread();
}

void sread(){
  if (Serial.available()>0){
    char val = Serial.read();
    if (val == 'a'){
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);         
      }
    }
  }


