//#define FWD = 0x00

int leftAddress = 128;
int rightAddress = 129;
int i = 0;
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  delay(2000);
  Serial.begin(9600);  //to computer
  Serial2.begin(9600); //to sabertooth
  Serial2.write(0xAA); //Makes Sabertooth automatically detect baud rate in packetized serial mode
  }

void loop() {
// chaseRed();
 /*
 Serial2.write(129);
 Serial2.write(0);
 Serial2.write(50);
 Serial2.write((129 + 0 + 50) & 0b01111111);
 
 Serial2.write(129);
 Serial2.write(4);
 Serial2.write(50);
 Serial2.write((129 + 4 + 50) & 0b01111111);

 delay(1000);

 //Turn around

 Serial2.write(129);
 Serial2.write(1);
 Serial2.write(50);
 Serial2.write((129 + 1 + 50) & 0b01111111);
 
 Serial2.write(129);
 Serial2.write(5);
 Serial2.write(50);
 Serial2.write((129 + 5 + 50) & 0b01111111);

 delay(1000);
 */
 takeInput();
 /*
 digitalWrite(led, HIGH);
 i += 1;
 if(i < 3) {
  TurnRight(60);
  delay(1000);
  stopMotors();
  delay(1000);
  TurnLeft(60);
  delay(1000);
  stopMotors();
  delay(1000);
 }
 else{
  stopMotors();
 }
 */
 
}

void takeInput() {
  if (Serial.available()) {
    int input = Serial.read();
    if (input == 102) {
      Serial.println("forwards");
      DriveForward(60);
    }
    else if (input == 98) {
      Serial.println("backwards");
      DriveBackward(60);
    }
    else if (input == 108) {
      Serial.println("left");
      TurnLeft(60);
    }
    else if (input == 114) {
      Serial.println("right");
      TurnRight(60);
    } 
    else if (input == 115) {
      Serial.println("stop");
      stopMotors();
    }
    else {
      Serial.println("input not valid:\nf=forwards\nb=backwards\nl=left\nr=right");           
    }
  }
  /*  
  Ascii values used:
   f = 102 = forwards
   b = 98 = backwards
   l = 108 = left
   r = 114 = right
   */
}
//233-700
uint16_t full;


void chaseRed() {
  if (Serial.available() > 0) {
    uint8_t input = Serial.read();
    if (input == 'G') {
      digitalWrite(led, HIGH);
      uint8_t high = Serial.read();
      uint8_t low = Serial.read();

      full = (high << 8) | low;
      Serial.println(full);
    }
    else if (input == 'N') {
      Serial.println("NO RED");
    }
    else {
      digitalWrite(led, LOW);
    }
  }
  map(full, 233, 700, 1, 3);
  if (full == 1) {
    TurnLeft(30);
  }
  else if (full == 2) {
    DriveForward(30);
  }
  else {
    TurnRight(30);
  }
  
  if (Serial.available()) {
    uint8_t firstEight = Serial.read();
    full = (firstEight << 8);
  }
  if (Serial.available()) {
    uint8_t secondEight = Serial.read();
    full = full | secondEight;
  }
  Serial.println(full);
  
}

void stopMotors() {
  //Left side, motor 1
  Serial2.write(leftAddress);
  Serial2.write(0);
  Serial2.write(0);
  Serial2.write((leftAddress + 0 + 0) & 0b01111111);
  //Left side, motor 2
  Serial2.write(leftAddress);
  Serial2.write(4);
  Serial2.write(0);
  Serial2.write((leftAddress + 4 + 0) & 0b01111111);
  //Right side, motor 1
  Serial2.write(rightAddress);
  Serial2.write(0);
  Serial2.write(0);
  Serial2.write((rightAddress + 0 + 0) & 0b01111111);
  //Right side, motor 2
  Serial2.write(rightAddress);
  Serial2.write(4);
  Serial2.write(0);
  Serial2.write((rightAddress + 4 + 0) & 0b01111111);
}

void leftDriveForward(int speed) {
  Serial2.write(leftAddress);
  Serial2.write(1);
  Serial2.write(speed);
  Serial2.write((leftAddress + 1 + speed) & 0b01111111);
  Serial2.write(leftAddress);
  Serial2.write(5);
  Serial2.write(speed);
  Serial2.write((leftAddress + 5 + speed) & 0b01111111);
}

void rightDriveForward(int speed) { //Right side is reversed to drive straight
  Serial2.write(rightAddress);
  Serial2.write(0);
  Serial2.write(speed);
  Serial2.write((rightAddress + 0 + speed) & 0b01111111);
  Serial2.write(rightAddress);
  Serial2.write(4);
  Serial2.write(speed);
  Serial2.write((rightAddress + 4 + speed) & 0b01111111);
}

void leftDriveBackward(int speed) {
  Serial2.write(leftAddress);
  Serial2.write(0);
  Serial2.write(speed);
  Serial2.write((leftAddress + 0 + speed) & 0b01111111);
  Serial2.write(leftAddress);
  Serial2.write(4);
  Serial2.write(speed);
  Serial2.write((leftAddress + 4 + speed) & 0b01111111);
}

void rightDriveBackward(int speed) {
  Serial2.write(rightAddress);
  Serial2.write(1);
  Serial2.write(speed);
  Serial2.write((rightAddress + 1 + speed) & 0b01111111);
  Serial2.write(rightAddress);
  Serial2.write(5);
  Serial2.write(speed);
  Serial2.write((rightAddress + 5 + speed) & 0b01111111);
}

void DriveForward(int speed) {
  leftDriveForward(speed);
  rightDriveForward(speed);
}

void DriveBackward(int speed) {
  leftDriveBackward(speed);
  rightDriveBackward(speed);
}

void TurnRight(int speed) { //Turning at 60 speed for 1 sec is almost perfectly 45 degrees
  leftDriveForward(speed);
  rightDriveBackward(speed);
}

void TurnLeft(int speed) { 
  leftDriveBackward(speed);
  rightDriveForward(speed);
}


