// Needed library for i2c
#include <Wire.h>

// Setting the address of the button, 0x28 and 0x36 are common defaults
#define TOUCH_SENSOR_ADDR 0x14

// Define 3 variables which will be our random color values
int redCol = 0;
int grnCol = 0;
int bluCol = 0;

// Define a variable for our intensity
int intVal = 30;

// Declaring a variable to flag when we've already performed an action when the button is touched

bool touchFlag = false;

void setup() {
  // Start serial communications so that we can receive messages and debug
  Serial.begin(115200);

  // Start the i2c communications so we can talk to the button
  Wire.begin();

}

void loop() {
  // The goal here that every time you touch the button, the LED turns a random colour
  // every time you let go of the button, the no-touch color changes as well.
  // When you press and hold, the intensity increases until it bottoms out, and then starts back up at max
  // This should only start after touching for 10s

  // this code checks the status of the button via a function
  uint8_t status = readButtonStatus(); // 'status' is a variable which equals the output of the readButtonStatus() function
  if (status == 0xAA) {

    Serial.println("Button PRESSED!");

    while (touchFlag == false) {
    randomizeColors();
    setTouchColor(redCol, grnCol, bluCol, intVal);
    touchFlag = true;
    }
    
    delay(50);


  } else if (status == 0xBB) {

    Serial.println("Button NOT pressed.");
    touchFlag = false;
    delay(50);

  }
}

int randomizeColors() {
  // Randomizes the color values
  redCol = random(0,255);
  grnCol = random(0,255);
  bluCol = random(0,255);

}

void setTouchColor(uint8_t r, uint8_t g, uint8_t b, uint8_t intensity) {
  Wire.beginTransmission(TOUCH_SENSOR_ADDR);
  Wire.write(0xC1);      // Command
  Wire.write(r);
  Wire.write(g);
  Wire.write(b);
  Wire.write(intensity);
  Wire.endTransmission();

  delay(50); // Small wait for response
  // Optional: Read response string ("OK\r", etc.)
}

uint8_t readButtonStatus() {
  Wire.beginTransmission(TOUCH_SENSOR_ADDR);
  Wire.write(0xC6);      // Command
  Wire.endTransmission();

  Wire.requestFrom(TOUCH_SENSOR_ADDR, 1); // Request 1 byte
  if (Wire.available()) {
    return Wire.read();  // Return status byte
  }
  return 0x00; // Return 0 on error
}