# Lesson 4 — More Senses

## Learning Goals
- Students will be able to read values from the sound, temperature, and motion sensors.
- Students will be able to use the Serial Monitor to see sensor values printed in real time.
- Students will be able to write an `if`/`else` that reacts to a sensor other than light.

## New Vocabulary
- **Serial Monitor** — a window in the Arduino IDE that lets the board send text to your computer while it runs. Used to see what values sensors are actually reporting.
- **`Serial.println(value)`** — tells the board to send a value to the Serial Monitor and move to a new line.
- **accelerometer** — a sensor that measures how fast the board is speeding up or changing direction. Tilting the board makes it read differently on each axis.

## Warm-Up (~5 min)

Ask students to list every way their phone "senses" the physical world:
> *"Your phone knows when you rotate it, when you tap the screen, how bright the room is, where you are on Earth. What physical thing is it measuring in each case?"*

Then: *"Your Circuit Playground has several of these same sensors built in. Today we're going to figure out what numbers they report — and then make the board do something with those numbers."*

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Open a fresh sketch. Add Serial.begin(9600) in setup().
2. In loop(), add:
     int sound = CircuitPlayground.soundSensor();
     Serial.println(sound);
     delay(100);
3. Upload. Open Serial Monitor (Tools → Serial Monitor, or Ctrl+Shift+M).
   Set baud rate to 9600. Numbers scroll by.
4. Clap near the board — numbers spike. Room is quiet — numbers low.
5. Add temperature:
     float temp = CircuitPlayground.temperature();
     Serial.print("Temp: ");
     Serial.println(temp);
   Show that temperature() returns a decimal (float, not int).
6. Add motion:
     float x = CircuitPlayground.motionX();
     Serial.print("X: ");
     Serial.println(x);
   Tilt the board — numbers change.
7. Pause: "The Serial Monitor is how you see what the board is actually measuring.
   Whenever something isn't working right, print the value first."

KEY CONCEPTS:
- Serial Monitor is the programmer's window into the running board.
  Always use it to check sensor values before writing if/else logic.
- float vs. int: temperature() and motionX/Y/Z() return decimals.
  Use float for those variables.
- delay(100) in loop() slows printing to readable speed. Without it,
  the monitor fills faster than you can read.
- soundSensor() returns the raw level, not decibels. A clap might spike to 900+
  in a quiet room; a noisy room might idle around 200–300.

COMMON MISCONCEPTIONS:
- Students open Serial Monitor but forgot Serial.begin(9600) → garbage or no output.
  Check baud rate matches.
- Students call temperature() and store in int — the decimal is silently dropped.
  Show the difference between int and float with a concrete example.
- motionX/Y/Z return m/s² (meters per second squared). On a flat board,
  motionZ ≈ 9.8 (gravity). Tilting changes which axis "feels" gravity.
-->

The Circuit Playground has several sensors beyond the light sensor. Each one is a function call that returns a number:

```cpp
int sound = CircuitPlayground.soundSensor();    // 0–1023, higher = louder
float temp = CircuitPlayground.temperature();   // degrees Celsius
float x = CircuitPlayground.motionX();          // tilt left/right, m/s²
float y = CircuitPlayground.motionY();          // tilt forward/back, m/s²
float z = CircuitPlayground.motionZ();          // up/down acceleration, m/s²
```

**`float` vs. `int`:** Temperature and motion sensors return decimal numbers. Use `float` (not `int`) when storing those values, or the decimal part is silently discarded.

**The Serial Monitor** lets the board send text to your computer while it runs. Set it up once in `setup()`, then use it anywhere in `loop()`:

```cpp
void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);          // open the connection at 9600 baud
}

void loop() {
  int sound = CircuitPlayground.soundSensor();
  Serial.print("Sound: ");
  Serial.println(sound);       // print and move to next line
  delay(100);                  // slow down so you can read it
}
```

Open the Serial Monitor: **Tools → Serial Monitor** (or `Ctrl+Shift+M`). Make sure the baud rate in the bottom-right corner says **9600**.

## Guided Activity (~20 min)

**Step 1 — Upload the starter code**
Upload the starter code. Open the Serial Monitor. You should see three values printing side-by-side every 200 ms.

**Step 2 — Explore the range**
- Clap loudly near the board. What does the sound value spike to?
- Cup your hands around the board. What does the temperature read? Blow warm breath on it.
- Tilt the board in different directions. Which axis changes? What does Z read when the board is flat?

Write down the range of values you observe for each sensor.

**Step 3 — Make the ring react to sound**
Remove the Serial.println calls (or comment them out with `//`). Add a sound-reactive pixel response:

```cpp
int sound = CircuitPlayground.soundSensor();
if (sound > 600) {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 255, 255, 0);  // yellow flash
  }
} else {
  CircuitPlayground.clearPixels();
}
```

Clap near the board. Adjust the threshold `600` until the behavior feels right for your room.

**Step 4 — Try a different sensor**
Replace the sound condition with a temperature or motion condition of your own design. Describe in plain English what you want the board to do, then write the code.

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
  Serial.begin(9600);
}

void loop() {
  int sound     = CircuitPlayground.soundSensor();
  float temp    = CircuitPlayground.temperature();
  float x       = CircuitPlayground.motionX();

  Serial.print("Sound: ");  Serial.print(sound);
  Serial.print("  Temp: "); Serial.print(temp);
  Serial.print("  X: ");    Serial.println(x);

  delay(200);
}
```

## Make It Yours (~remaining time)

- **Thermometer ring** — use `map()` to translate the temperature reading (roughly 15–35°C in a classroom) to a color. Cold = blue, warm = red.
- **Shake detector** — if `motionX()` or `motionY()` exceeds a threshold (try 5.0), flash all pixels white briefly.
- **Sound meter** — use `map()` to translate the sound level into how many pixels light up. Loud = all 10, quiet = 0. (Hint: map the sound level to a count, then light that many pixels in your `for` loop condition.)
- **Challenge:** Combine two sensors — the color of the ring is set by temperature AND the brightness is set by the sound level.

## Wrap-Up (~5 min)

<!-- Exit ticket: "Name one sensor you used today and one thing you learned about its range."
     The goal is to establish that sensor values are raw numbers in arbitrary units,
     and that discovering the range by experimentation is a real skill. -->

Name one sensor you used today and describe the range of values it reported in your classroom.

## Teacher Notes

<!--
SERIAL MONITOR SETUP:
- The most common issue: baud rate mismatch. The Serial.begin() argument and the Serial
  Monitor dropdown must match. Always 9600 in this series.
- If the monitor shows garbage characters, the baud rate is wrong.
- If nothing appears, Serial.begin() is missing from setup().

FLOAT VS. INT DEMO:
- Worth doing live: int x = 9.8; Serial.println(x); prints 9.
  float x = 9.8; Serial.println(x); prints 9.80. Students find this clarifying.

SOUND SENSOR NOTE:
- The microphone is on the back of the board. Students holding the board in their
  palm will muffle it. Have them set the board flat on the table for the clap test.

MOTION SENSOR (GRAVITY):
- When the board is flat and motionless, motionZ() reads approximately 9.8 m/s²
  because the accelerometer measures gravity. This surprises students ("I didn't move it!").
  Explain: the accelerometer can't tell the difference between gravity and acceleration.

DELAY:
- Without delay(200) in loop(), the Serial Monitor fills so fast it's unreadable and
  can slow down older computers. Always include a small delay when printing in a loop.

PACING:
- Step 3 (sound-reactive ring) is the most satisfying moment of this lesson.
  Give students time to find their own threshold — this is their first time tuning a
  threshold from scratch (as opposed to the light sensor where hand-coverage is the test).
-->
