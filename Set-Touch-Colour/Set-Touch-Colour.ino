#include <Wire.h>
//Change this to your i2c address - mine shipped as 0x14 but use an i2c scanner sketch to confirm
uint8_t touchAddr = 0x14;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Command 0xC1 = Set Touch Color
  Wire.beginTransmission(touchAddr);
  Wire.write(0xC1);      // Command
  Wire.write(0);         // Red value (0–255)
  Wire.write(255);       // Green value
  Wire.write(0);         // Blue value
  Wire.write(50);        // Brightness (0–255)
  Wire.endTransmission();

  Serial.println("Touch color set to green at medium brightness.");
}

void loop() {
  // Nothing else needed here
}