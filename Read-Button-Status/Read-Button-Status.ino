#include <Wire.h>
//Change this to your i2c address - mine shipped as 0x14 but use an i2c scanner sketch to confirm
uint8_t touchAddr = 0x14;

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  // Ask for button status (command 0xC6)
  Wire.beginTransmission(touchAddr);
  Wire.write(0xC6);
  Wire.endTransmission();

  Wire.requestFrom(touchAddr, (uint8_t)1);
  if (Wire.available()) {
    uint8_t status = Wire.read();
    if (status == 0xAA) {
      Serial.println("Button is PRESSED!");
    } else if (status == 0xBB) {
      Serial.println("Button is NOT pressed.");
    } else {
      Serial.print("Unknown response: 0x");
      Serial.println(status, HEX);
    }
  }
  delay(500);
}