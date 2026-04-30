# Lesson 7 — Touch Magic

## Learning Goals
- Students will be able to read a value from a capacitive touch pad using `readCap()`.
- Students will be able to set a threshold to distinguish "touched" from "not touched."
- Students will be able to trigger lights and sounds from touch input.

## New Vocabulary
- **capacitive touch** — a way of sensing when a conductive object (like a finger) is near a metal pad, by detecting a tiny change in electrical charge. No button needs to be pressed.
- **threshold** — a number you choose that separates two states. If the reading is above the threshold, the finger is there; below, it isn't. Choosing the right threshold is part of your design.
- **`readCap(pin)`** — reads the capacitive touch value on one of the Circuit Playground's touch-capable pins. Returns a number roughly 0–30 at rest and 100–1000+ when touched.

## Warm-Up (~5 min)

Without explaining how it works, touch the board's gold pad labeled **A2** while holding it.
Ask: *"What do you think the board can detect just from my finger touching this pad? How is this different from pressing a button?"*

Then ask: *"How does your phone's touchscreen know where your finger is? Does it need you to push down?"*

Let students describe the idea of sensing touch without pressure before seeing the code.

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Start from a minimal sketch. Add Serial.begin(9600) in setup().
2. In loop():
     int t = CircuitPlayground.readCap(2);
     Serial.println(t);
     delay(50);
3. Upload. Open Serial Monitor. Show the idle value (roughly 0–30).
4. Touch pad A2 / pin 2 with a finger. Show the value jump (100–1000+).
5. "The number goes up when your finger is there. We need to pick a threshold —
   a cutoff number — to decide: above this means 'touched.'"
6. Add:
     if (t > 50) {
       for (int i = 0; i < 10; i++) {
         CircuitPlayground.setPixelColor(i, 0, 0, 255);
       }
     } else {
       CircuitPlayground.clearPixels();
     }
7. Touch / release the pad. Board lights up blue on touch, off on release.
8. Now add a second pad: pin 6. Show that two pads can trigger different colors.

VALID TOUCH PINS:
- The capacitive touch pads on the Circuit Playground are on digital pins:
  0, 1, 2, 3, 6, 9, 10, 12
- Despite what much of the online documentation says, these are NOT labeled A1–A7.
  They are digital pin numbers. Use the numbers exactly as listed.
- Pins labeled on the board near the pads may show A-prefixed names (A1, A2, etc.),
  but pass the digital pin NUMBER to readCap(), not an analog name.
- Pin 2 is the easiest starter — it's the large pad labeled "A2" on most boards
  and is away from buttons and other components.

THRESHOLD:
- Idle values vary by environment (humidity, whether the board is on a conductive surface).
  50 is a safe threshold in most classroom conditions.
- If a student's board seems "always triggered," lower the threshold idea:
  print the idle value and set threshold = idle + 30.

COMMON MISCONCEPTIONS:
- Students expect readCap() to return true/false like a button. It returns a number.
  The student decides what counts as "touched" by choosing the threshold.
- Students may confuse the analog label (A2) with the analog pin number for analogRead().
  readCap() takes a digital pin number. readCap(2), not readCap(A2).
-->

The Circuit Playground has **capacitive touch pads** — metal areas on the board that can sense the electrical charge of a nearby finger.

Call `readCap()` with a **digital pin number**:
```cpp
int touch = CircuitPlayground.readCap(2);
```

**Valid pin numbers:** `0, 1, 2, 3, 6, 9, 10, 12`

> **Note:** Despite labels on the board and in many tutorials that say A1, A2, etc., `readCap()` takes the **digital pin number** — not an analog label.

The return value is roughly:
- **0–30** at rest (no finger)
- **100–1000+** when touched

You choose a **threshold** to decide when a finger is present:
```cpp
if (touch > 50) {
  // finger is touching
} else {
  // no finger
}
```

Print the value with `Serial.println()` first to see your board's actual idle range before setting a threshold.

## Guided Activity (~20 min)

**Step 1 — Upload the starter code**
Upload the starter code. Open the Serial Monitor and watch the values. Touch pin 2's pad (labeled A2 on the board). The value should jump.

**Step 2 — Find your threshold**
Look at the idle value (no touch) and the touched value. Pick a threshold number between them. Change `50` in the `if` statement to your threshold.

**Step 3 — Trigger a sound**
Inside the `if (touch > threshold)` block, add a `playTone()` call. Pick a frequency and a short duration (try 200 ms). The board should play a note every time you touch it.

**Step 4 — Add a second pad**
Add a second `readCap()` call for pin 6:
```cpp
int touch6 = CircuitPlayground.readCap(6);
```
Make pin 6 trigger a different color and a different note.

**Step 5 — Print both values**
Add `Serial.print()` for both pads so you can see both values at once:
```cpp
Serial.print("Pin2: ");  Serial.print(touch);
Serial.print("  Pin6: ");  Serial.println(touch6);
```
Observe what happens when you touch both pads simultaneously.

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
  Serial.begin(9600);
}

void loop() {
  int touch = CircuitPlayground.readCap(2);   // pin 2

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
```

## Make It Yours (~remaining time)

- **Make a mini piano** — map four touch pads to four different notes. Pin 1 → C4, pin 2 → E4, pin 3 → G4, pin 6 → C5. Touch each pad to play its note.
- **Color chooser** — each pad selects a different color for the whole ring. The last pad touched "wins."
- **Touch alarm** — normally the ring glows dim white. When pad 9 is touched, flash all pixels red and play a loud, fast tone.
- **Copper tape extension** — get a strip of copper tape from the supplies and press one end firmly against one of the gold touch pads on the board. Route the tape across a piece of paper or cardboard and touch the far end. Does `readCap()` still detect your finger? (You may need to raise the threshold — try 100 or 150 instead of 50 for an extended surface.)
- **Challenge:** Create a "hold to brighten" behavior — the longer you hold a pad (keeping checking `readCap()` and counting how many loops pass), the brighter the ring gets. Release to reset.

## Wrap-Up (~5 min)

<!-- Exit ticket: "Why does readCap() return a number instead of just true or false?
     What advantage does that give you?"
     Target answer: a number lets you choose the threshold yourself and tune it to
     your environment; a yes/no answer wouldn't let you distinguish a light touch from
     a firm touch, or adjust for different humidity conditions.
     Any answer that references "you get to decide when it counts as touched" is correct. -->

Why does `readCap()` return a number instead of `true` or `false`? What advantage does that give you as a programmer?

## Teacher Notes

<!--
VALID PIN NUMBERS — CRITICAL:
- The valid capacitive touch pins are: 0, 1, 2, 3, 6, 9, 10, 12.
- Pass these as integer literals: readCap(2), readCap(6), etc.
- Many Adafruit tutorials use A1-style labels, which refer to analog input numbering.
  readCap() does NOT accept those labels in this library version.
- Pin 2 is the recommended starter: it's physically labeled, away from the buttons,
  and consistently reliable.
- Pins 0 and 1 are also hardware serial TX/RX. They work for readCap() but may show
  slightly elevated idle values if Serial is active. Safe to use; just note the behavior.

IDLE VALUE VARIABILITY:
- Idle values vary based on: humidity, whether the board is on a conductive surface,
  whether the student is wearing a wool sweater, USB cable type, and more.
- Always have students print the idle value and set their own threshold.
  A blanket "use 50" works in dry conditions but may not in humid weather.
- If a pad reads ~40 at rest, use threshold = 60 or 70.

SIMULTANEOUS TOUCHES:
- The board can read all pads independently and simultaneously. Both readCap() calls
  in Step 4 return independent values. Students enjoy discovering they can trigger both.

MINI PIANO (Make It Yours):
- This is the most popular Make It Yours direction. It tends to produce a lot of noise.
  Consider setting a class expectation: "make your sound, then hold off while others listen."
- Note: the tones are blocking. If a student holds two pads, only one tone plays —
  whichever if-branch runs first. This limitation is real and worth discussing if it comes up.

COPPER TAPE EXTENSION:
- The Maker Space copper tape works well as a capacitive touch extension.
  Press one end firmly against the gold pad on the board (pin 2 is easiest) and secure it
  with a small piece of regular tape to hold it in contact.
- The threshold will need to increase — a longer copper run means higher baseline capacitance.
  Have students print the idle value with Serial Monitor and set their threshold ~50 above it.
- Common extension ideas students will invent: paper piano keys, touch-sensitive drawings,
  "secret button" hidden under a piece of paper, conductive fabric patches.
- Alligator clips can also clip directly to the edge of a touch pad for a quicker connection.

PACING:
- Step 3 (add a sound) is where the lesson really clicks. Prioritize getting there.
  Steps 4–5 are enrichment.
-->
