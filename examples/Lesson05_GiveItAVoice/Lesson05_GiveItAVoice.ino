#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  CircuitPlayground.playTone(440, 500);  // A4 -- change me!
  delay(50);
  CircuitPlayground.playTone(523, 500);  // C5 -- change me!
  delay(50);
}
