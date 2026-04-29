#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
  Serial.begin(9600);
}

void loop() {
  int touch = CircuitPlayground.readCap(2);  // pin 2 (labeled A2 on the board)

  Serial.println(touch);

  if (touch > 50) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 0, 255);  // blue when touched
    }
  } else {
    CircuitPlayground.clearPixels();
  }

  delay(50);
}
