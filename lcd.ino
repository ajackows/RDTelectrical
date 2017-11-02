#include <LiquidCrystal.h>

int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
int voltagePin = 0;
int amperagePin = 2;

LiquidCrystal lcd(rs, e, d4, d5, d6 , d7);

void setup() { 
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("V=");
  lcd.setCursor(0,1);
  lcd.print("A=");
  Serial.begin(9600);
}

void loop() {
  float volRaw = analogRead(voltagePin);
  float voltage = volRaw/63.69*5;
  lcd.setCursor(2,0);
  lcd.print(voltage);
  lcd.print("              ");

  //0.722V 0 - 5 = 0 - 1023

  float ampRaw = analogRead(amperagePin);
  Serial.print(ampRaw);
  float amperage = ampRaw/36.60*5;
  lcd.setCursor(2,1);
  lcd.print(ampRaw*1000);
  lcd.print("              ");
}

