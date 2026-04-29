# Lesson 1 — Hello, Pixels!

## Learning Goals
- Students will be able to open the Arduino IDE, paste starter code, and upload it to the Circuit Playground.
- Students will be able to call `setPixelColor()` to light up a single LED.
- Students will be able to describe the difference between `setup()` and `loop()` in plain language.

## New Vocabulary
- **upload** — sending your code from the computer to the Circuit Playground so the board can run it.
- **function** — a named action you can tell the computer to perform by writing its name followed by parentheses.
- **`setup()`** — the block of code that runs once, right when the board turns on.
- **`loop()`** — the block of code that runs over and over, forever, after `setup()` finishes.

## Warm-Up (~5 min)

Hold up the Circuit Playground and ask:

> *"What do you notice about this board? What do you think it can do?"*

Take a few answers, then ask:

> *"If I wanted just one of these lights to turn on — that one, right there — what information would I need to give the computer?"*

Let students guess freely. (They'll land on: which light, what color. That's exactly right.)

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Show the Arduino IDE open with a blank sketch.
2. Point out setup() and loop() — "two rooms your code lives in."
3. Type CircuitPlayground.begin(); in setup(). Explain: this is like pressing the power button
   on everything inside the board. Always first.
4. Type CircuitPlayground.setPixelColor(0, 255, 0, 0); directly below it.
5. Upload. One red LED lights up.
6. Change the 0 (pixel number) to 5. Upload again. Different pixel lights up.
7. Say: "That first number is the address. The board has pixels 0 through 9."

KEY CONCEPTS TO HIT:
- The board numbers its pixels 0–9, starting at the USB connector and going clockwise.
- setPixelColor takes four numbers: which pixel, how much red, how much green, how much blue.
- Values 0–255: 0 means "none," 255 means "as much as possible."
- Don't explain why 255 yet — just establish the range as a fact.
- setup() runs once. loop() runs forever. Nothing is in loop() today — that's fine.

COMMON MISCONCEPTIONS:
- Students may try pixel number 10. Tell them it silently does nothing — the board has 0–9.
- Students may expect the light to blink or change. Explain: "It stays on because we told it
  to turn on in setup() and never told it to turn off."
-->

The Circuit Playground has **10 NeoPixel LEDs** numbered **0 through 9**, starting at the USB port and going clockwise around the ring.

To light one up, you use:
```cpp
CircuitPlayground.setPixelColor(pixel, red, green, blue);
```

- `pixel` — which LED (0–9)
- `red`, `green`, `blue` — how much of each color (0 = none, 255 = full)

To turn on pixel 0 in red:
```cpp
CircuitPlayground.setPixelColor(0, 255, 0, 0);
```

Every Arduino program has two required blocks:
- **`setup()`** — runs once when the board powers on
- **`loop()`** — runs over and over after that

`CircuitPlayground.begin()` must always be the first line in `setup()`. It wakes up all the hardware on the board.

## Guided Activity (~20 min)

**Step 1 — Open the starter code**
Open the Arduino IDE. Create a new sketch and replace everything with the starter code below, then upload it. You should see one red LED.

**Step 2 — Change which pixel**
Change the first number inside `setPixelColor` from `0` to `5`. Upload. Which pixel lit up?

**Step 3 — Try all of them**
Change the pixel number to `9`. Upload. Now try `3`. Try `0` again.

**Step 4 — Turn on two pixels**
Add a second `setPixelColor` line below the first one, using a different pixel number.
Upload. Both should stay on.

**Step 5 — Think about it**
Why does the light stay on permanently? Where in the code would you have to make a change to turn it off?

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();

  CircuitPlayground.setPixelColor(0, 255, 0, 0);  // pixel 0, red
}

void loop() {
  // nothing here yet
}
```

## Make It Yours (~remaining time)

- **Change the pixel number** — which pixel is your favorite? Make it your "home base" pixel.
- **Change the color** — try `(0, 0, 255, 0)` for green, or `(0, 0, 0, 255)` for blue. What does `(0, 255, 255, 0)` produce?
- **Light up three pixels at once** — add three `setPixelColor` lines, each with a different pixel number.
- **Challenge:** Can you light all 10 pixels? (You'll need 10 lines — there's a better way coming in Lesson 2, but try it by hand first.)

## Wrap-Up (~5 min)

<!-- Exit ticket: go around the room, each student completes ONE of these sentences out loud:
     "Pixel __ on my board shows color __."
     "Something I noticed: __."
     "Something I'm confused about: __."
     Make sure every student has successfully uploaded at least once before class ends.
     If a student hasn't uploaded, stay with them — uploading is the non-negotiable skill of Lesson 1. -->

Before you leave: make sure your board has at least one pixel lit up with a color YOU chose.

## Teacher Notes

<!--
SETUP CHECKLIST (before class):
- Arduino IDE installed on all machines.
- Adafruit Circuit Playground library installed (Library Manager → search "Adafruit Circuit Playground").
- Board set to "Adafruit Circuit Playground" (Tools → Board).
- Correct COM port selected (Tools → Port) — will vary per machine.
- Have one board already uploaded and glowing so students see the goal immediately.

PACING:
- Uploading for the first time takes longer than expected. Budget 5 extra minutes.
- If a student can't find their COM port, unplug and replug the USB cable.
- Windows machines sometimes need the driver installed separately (Adafruit website).

DIFFERENTIATION:
- Early finishers: Challenge them to write out all 10 setPixelColor lines by hand.
  This naturally motivates the for loop in Lesson 2.
- Struggling students: Focus on just one successful upload of the unmodified starter code.
  Color changes can wait.

THE "DOES NOTHING" LOOP:
- Some students will be bothered by an empty loop(). Reassure them: an empty loop() is
  legal and does exactly what it says — nothing, repeatedly. The light stays on because
  setup() ran and nobody told it to turn off.
-->
