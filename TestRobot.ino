//#define FWD = 0x00

int leftAddress = 128;
int rightAddress = 129;
int i = 0;

void setup() {
  delay(2000);
  Serial.begin(9600);
 // Serial1.begin(9600);
  Serial.write(0xAA); //Makes Sabertooth automatically detect baud rate in packetized serial mode
  }

void loop() {
 
 i += 1;
 if(i < 3) {
  DriveForward(60);
  delay(1000);
  stopMotors();
  delay(1000);
  DriveBackward(60);
  delay(1000);
  stopMotors();
  delay(1000);
 }
 else{
  stopMotors();
 }
  /*
  Serial.write(leftAddress);
  Serial.write(0);
  Serial.write(127);
  Serial.write((leftAddress + 0 + 127) & 0b01111111);
  delay(1000);
  Serial.write(leftAddress);
  Serial.write(0);
  Serial.write(60);
  Serial.write((leftAddress + 0 + 60) & 0b01111111);
  delay(1000);
  */
}

void stopMotors() {
  //Left side, motor 1
  Serial.write(leftAddress);
  Serial.write(0);
  Serial.write(0);
  Serial.write((leftAddress + 0 + 0) & 0b01111111);
  //Left side, motor 2
  Serial.write(leftAddress);
  Serial.write(4);
  Serial.write(0);
  Serial.write((leftAddress + 4 + 0) & 0b01111111);
  //Right side, motor 1
  Serial.write(rightAddress);
  Serial.write(0);
  Serial.write(0);
  Serial.write((rightAddress + 0 + 0) & 0b01111111);
  //Right side, motor 2
  Serial.write(rightAddress);
  Serial.write(4);
  Serial.write(0);
  Serial.write((rightAddress + 4 + 0) & 0b01111111);
}

void leftDriveForward(int speed) {
  Serial.write(leftAddress);
  Serial.write(1);
  Serial.write(speed);
  Serial.write((leftAddress + 1 + speed) & 0b01111111);
  Serial.write(leftAddress);
  Serial.write(5);
  Serial.write(speed);
  Serial.write((leftAddress + 5 + speed) & 0b01111111);
}

void rightDriveForward(int speed) { //Right side is reversed to drive straight
  Serial.write(rightAddress);
  Serial.write(0);
  Serial.write(speed);
  Serial.write((rightAddress + 0 + speed) & 0b01111111);
  Serial.write(rightAddress);
  Serial.write(4);
  Serial.write(speed);
  Serial.write((rightAddress + 4 + speed) & 0b01111111);
}

void leftDriveBackward(int speed) {
  Serial.write(leftAddress);
  Serial.write(0);
  Serial.write(speed);
  Serial.write((leftAddress + 0 + speed) & 0b01111111);
  Serial.write(leftAddress);
  Serial.write(4);
  Serial.write(speed);
  Serial.write((leftAddress + 4 + speed) & 0b01111111);
}

void rightDriveBackward(int speed) {
  Serial.write(rightAddress);
  Serial.write(1);
  Serial.write(speed);
  Serial.write((rightAddress + 1 + speed) & 0b01111111);
  Serial.write(rightAddress);
  Serial.write(5);
  Serial.write(speed);
  Serial.write((rightAddress + 5 + speed) & 0b01111111);
}

void DriveForward(int speed) {
  leftDriveForward(speed);
  rightDriveForward(speed);
}

void DriveBackward(int speed) {
  leftDriveBackward(speed);
  rightDriveBackward(speed);
}

void RightTurn(int speed) { //Untested
  leftDriveForward(speed);
  rightDriveForward(speed);
}

void LeftTurn(int speed) {  //Untested
  leftDriveBackward(speed);
  rightDriveBackward(speed);
}



