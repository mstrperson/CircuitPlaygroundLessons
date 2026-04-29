#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  int light = CircuitPlayground.lightSensor();
  int brightness = map(light, 0, 1023, 0, 255);

  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, brightness, 0, 0);
  }
}
