
#include <FlexCAN.h>
#include <kinetis_flexcan.h>


// Match motorcontroller settings
const int bitRate = 125000; // default
const int nodeID = 1;

// Initialize CAN object and messages
FlexCAN myCAN(bitRate);
CAN_message_t message;

void setup() {
  Serial.begin(9600);
  myCAN.begin();
  message.id = 0x600 + nodeID;
  message.len = 8;
//  message.buf[0] = 0x20;
//  message.buf[1] = 0x20;
//  message.buf[2] = 0x02;
//  message.buf[3] = 0x01;
//  message.buf[4] = 0;
//  message.buf[5] = 0;
//  message.buf[6] = 3;
//  message.buf[7] = 0xE8;
//  myCAN.write(message);
//  delay(5000);
//  message.buf[0] = 0x20;
//  message.buf[1] = 0x20;
//  message.buf[2] = 0x0E;
//  message.buf[3] = 0x01;
//  message.buf[4] = 0;
//  message.buf[5] = 0;
//  message.buf[6] = 0;
//  message.buf[7] = 0;
//  myCAN.write(message);
  
}

void loop() {
  message.buf[0] = 0x20;
  message.buf[1] = 0;
  message.buf[2] = 0x20;
  message.buf[3] = 0x01;
  message.buf[4] = (unsigned char)500;
  message.buf[5] = (unsigned char)500 >> 8;
  message.buf[6] = 0;
  message.buf[7] = 0;
  myCAN.write(message);
  delay(1000);
}
