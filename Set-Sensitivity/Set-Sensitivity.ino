#include <Wire.h>
//Change this to your i2c address - mine shipped as 0x14 but use an i2c scanner sketch to confirm
uint8_t touchAddr = 0x14;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Command 0xC3 = Set Sensitivity
  // Levels: 1 = very sensitive, 5 = least sensitive
  Wire.beginTransmission(touchAddr);
  Wire.write(0xC3);
  Wire.write(3);   // Example: level 3
  Wire.endTransmission();

  Serial.println("Sensitivity set to level 3.");
}

void loop() {}