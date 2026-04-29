# Lesson 3 — Sensing Light

## Learning Goals
- Students will be able to read a value from the light sensor and store it in a variable.
- Students will be able to use `map()` to translate a sensor range into a color range.
- Students will be able to use an `if`/`else` statement to make the board behave differently under different conditions.

## New Vocabulary
- **sensor** — a part of the board that measures something in the physical world and gives back a number.
- **`map(value, fromLow, fromHigh, toLow, toHigh)`** — a function that rescales a number from one range to another. Like converting a temperature from Celsius to Fahrenheit, but for any two ranges.
- **`if` / `else`** — a way to give the board two choices: "if this condition is true, do this; otherwise, do that."
- **condition** — a comparison that is either true or false, like `light > 500`.

## Warm-Up (~5 min)

Cover the Circuit Playground with your hand and ask:

> *"What just happened to the light around the sensor? How could the board know that?"*

Then ask:

> *"Automatic night lights turn on when it gets dark. What does the light sensor need to 'decide' to make that happen?"*

Let students describe the logic in plain English before seeing any code.

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Start from a working Lesson 2 sketch (all pixels one color).
2. Add this to loop():
     int light = CircuitPlayground.lightSensor();
   Explain: "lightSensor() measures the brightness of the room and gives back a number.
   We store that number in a variable called light."
3. Show that the range is 0–1023: "0 is completely dark, 1023 is extremely bright."
4. Ask: "But setPixelColor wants 0–255, not 0–1023. What's the problem?"
   Let students articulate the mismatch. Then introduce map():
     int brightness = map(light, 0, 1023, 0, 255);
5. Use brightness as the red channel: setPixelColor(i, brightness, 0, 0).
   Cover and uncover the sensor — the color changes.
6. Now introduce if/else by asking: "What if I want it fully blue in the dark and
   fully red in bright light?"
     if (light < 300) {
       // blue
     } else {
       // red
     }
7. Upload and demonstrate covering the sensor.

KEY CONCEPTS:
- Sensors give back numbers; the board doesn't "understand" the physical world,
  it just reads a number.
- map() is a proportional rescaling — it doesn't do anything magical.
  Draw it on the board as two number lines with arrows.
- if/else: only ONE branch runs. The board checks the condition and picks.
- The threshold (300, 500, etc.) is a design choice, not a fact. Students choose it.

COMMON MISCONCEPTIONS:
- Students expect lightSensor() to give a value in lumens or some real-world unit.
  It gives a raw hardware reading (0–1023). The units are "sensor units."
- Students may put lightSensor() in setup() instead of loop() — the value will
  be read once at power-on and never update. Demonstrate this bug.
- map() with the ranges reversed (toLow > toHigh) inverts the relationship.
  This is useful! (Dark → bright, bright → dark.) Preview it as a feature.
-->

The Circuit Playground has a **light sensor** that returns a number from **0** (pitch dark) to **1023** (very bright). Call it in `loop()` so it keeps updating:

```cpp
int light = CircuitPlayground.lightSensor();
```

**The range problem:** `setPixelColor` wants values from 0–255, but the sensor gives 0–1023. The `map()` function rescales one range to another:

```cpp
int brightness = map(light, 0, 1023, 0, 255);
```

Think of it as two number lines:
```
sensor:  0 ─────────────────── 1023
color:   0 ──────────────────── 255
```
`map()` finds where your value falls on the top line and returns the matching position on the bottom line.

**`if` / `else`** gives the board two choices:

```cpp
if (light < 400) {
  // this runs when it's dark
} else {
  // this runs when it's bright
}
```

The board checks the condition once every time through `loop()` and executes exactly one branch.

## Guided Activity (~20 min)

**Step 1 — Upload the starter code**
Upload the starter code. Wave your hand over the board — the brightness of the red ring should change.

**Step 2 — Read the sensor value**
Change the `for` loop so `brightness` controls all three channels equally:
```cpp
CircuitPlayground.setPixelColor(i, brightness, brightness, brightness);
```
Now the ring goes from off to white. What does it look like in the middle?

**Step 3 — Add an if/else**
Below the `map()` line, add an `if`/`else`:
- If the light reading is **below 300**, make the ring blue.
- Otherwise, make the ring red.

Test it by covering and uncovering the sensor.

**Step 4 — Tune the threshold**
The 300 is your choice. Try 100, then 700. Which one feels most like "it just got dark"?

**Step 5 — Reverse the map**
Change `map(light, 0, 1023, 0, 255)` to `map(light, 0, 1023, 255, 0)`.
Before uploading: what do you predict will happen? Upload and check.

## Starter Code

```cpp
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
```

## Make It Yours (~remaining time)

- **Change the reaction color** — instead of going from dark to red, go from dark to your signature color (from Lesson 2). Use your `r`, `g`, `b` variables with `brightness` as a multiplier.
- **Two-condition response** — add a second `if` so there are three states: dark (one color), medium (another), and bright (a third). You'll need an `else if`.
- **Map to a different channel** — what if darkness makes the board more green instead of more red? Try mapping the sensor to the `g` channel only.
- **Challenge:** Make the ring split in half — the top 5 pixels react to light one way, the bottom 5 react the opposite way. Experiment with reversed `map()` for one of the halves.

## Wrap-Up (~5 min)

<!-- Exit ticket: "In your own words, what does map() do? Use the words 'sensor' and 'color' in your answer."
     Collect on an index card or sticky note. Look for students who describe it as a proportion
     vs. students who describe it as magic — both need follow-up next class. -->

In your own words: what does `map()` do? Use the words "sensor" and "color" in your answer.

## Teacher Notes

<!--
CLASSROOM SETUP:
- If the room has very consistent lighting, the sensor won't have much range to show.
  Have students cover the sensor with a hand (dark) or point it at the window (bright).
- Fluorescent lights flicker at 60Hz — the sensor may jitter slightly. A small delay(10)
  in loop() can help stabilize readings if the lights are noticeably twitchy.

COMMON BUG — SENSOR IN SETUP():
- This is the most common structural error in Lesson 3. If a student reports "it doesn't
  react to my hand," check that lightSensor() is called inside loop(), not setup().

if / else PACING:
- Don't rush to introduce else if in the main lesson. The Make It Yours prompt introduces
  it for students who get there. For the guided activity, plain if/else is enough.

MISCONCEPTION — THRESHOLD IS A FACT:
- Some students think there is a "correct" threshold for dark vs. bright. Emphasize that
  they are making a design decision. What counts as "dark" is up to them.

DIFFERENTIATION:
- Early finishers: push toward the challenge (split ring with reversed map). This is
  genuinely interesting and previews the idea of multiple simultaneous behaviors.
- Struggling students: focus on just the map() and the color change responding to hand coverage.
  The if/else can be introduced next class as a warm-up review.
-->
