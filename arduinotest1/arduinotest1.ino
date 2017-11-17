void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); 
  pinMode(5, INPUT);
  
  //OUTPUT can also be 1 possibly
  }

void loop(){
  sread();
  pin5();
  analog_read();
  
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
    if (val == 'b'){
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000)
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      }
    }
  }

void pin5(){
   int value = digitalRead(5);
   if (value == HIGH){    
      Serial.println("Pin is high");
   }
  }

void analog_read(){
  int value = analogRead(A0);
  Voltage_value = (value*5)/1023;
  
  
  
  
  
  
  }

