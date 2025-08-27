#include <Wire.h>
//Change this to your i2c address - mine shipped as 0x14 but use an i2c scanner sketch to confirm
uint8_t touchAddr = 0x14;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Command 0xC2 = Set No-Touch Color
  Wire.beginTransmission(touchAddr);
  Wire.write(0xC2);
  Wire.write(255);   // Red
  Wire.write(0);     // Green
  Wire.write(0);     // Blue
  Wire.write(20);    // Brightness
  Wire.endTransmission();

  Serial.println("No-touch color set to dim red.");
}

void loop() {}
