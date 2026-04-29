#include <Adafruit_CircuitPlayground.h>

int r = 255;  // red   (0-255)
int g = 0;    // green (0-255)
int b = 0;    // blue  (0-255)

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, r, g, b);
  }
}
