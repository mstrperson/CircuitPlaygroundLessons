#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
  Serial.begin(9600);
}

void loop() {
  int sound  = CircuitPlayground.soundSensor();
  float temp = CircuitPlayground.temperature();
  float x    = CircuitPlayground.motionX();

  Serial.print("Sound: ");  Serial.print(sound);
  Serial.print("  Temp: "); Serial.print(temp);
  Serial.print("  X: ");    Serial.println(x);

  delay(200);
}
