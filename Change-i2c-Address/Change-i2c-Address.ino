#include <Wire.h>
//Change this to your i2c address - mine shipped as 0x14 but use an i2c scanner sketch to confirm
uint8_t touchAddr = 0x14;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Command 0xC4 = Change I2C address
  // Example: change from 0x10 → 0x20
  Wire.beginTransmission(touchAddr);
  Wire.write(0xC4);
  Wire.write(0x20);   // New address
  Wire.endTransmission();

  Serial.println("Address changed! Update your code to use 0x20 now.");
}

void loop() {}