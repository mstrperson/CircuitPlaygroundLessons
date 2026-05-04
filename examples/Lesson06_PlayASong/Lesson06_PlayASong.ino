#include <Adafruit_CircuitPlayground.h>

// Note frequencies in Pythagorean temperament (Hz), tuned to A4 = 440.00
// Pythagorean temperament builds every note by stacking pure perfect fifths
// (ratio 3:2) up and down from A. Fifths and fourths are acoustically pure;
// major thirds are slightly sharper than in equal temperament.
#define c4  260.74
#define d4  293.33
#define e4  330.00
#define f4  347.65
#define g4  391.11
#define a4  440.00
#define b4  495.00
#define c5  521.48

// Note durations (ms) -- quarter note = 500 ms = 120 beats per minute
#define quarter  500
#define half     quarter * 2
#define whole    quarter * 4
#define eighth   quarter / 2

// delay() is a rest -- it pauses the program for that many milliseconds.
// A longer delay() between notes creates audible silence, just like a rest
// in sheet music. The short delay(50) after each note below is too brief to
// hear as silence, but it prevents two notes in a row from blurring into one
// long tone. Musicians call that separation staccato.

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);

}

void loop() {
  // Mary Had a Little Lamb -- first phrase
  CircuitPlayground.playTone(e4, quarter);
  delay(50);
  CircuitPlayground.playTone(d4, quarter);
  delay(50);
  CircuitPlayground.playTone(c4, quarter);
  delay(50);
  CircuitPlayground.playTone(d4, quarter);
  delay(50);
  CircuitPlayground.playTone(e4, quarter);
  delay(50);
  CircuitPlayground.playTone(e4, quarter);
  delay(50);
  CircuitPlayground.playTone(e4, half);
  delay(50);

  // YOUR SONG CONTINUES HERE

  delay(1000); // pause for a moment before repeating the song
}
