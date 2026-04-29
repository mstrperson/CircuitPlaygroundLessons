# Lesson 2 — Painting with Light

## Learning Goals
- Students will be able to use variables to store and change color values.
- Students will be able to use a `for` loop to set all 10 pixels at once.
- Students will be able to predict what color a set of RGB values will produce, and explain why mixing light is different from mixing paint.

## New Vocabulary
- **variable** — a named container that holds a number your program can use and change. `int red = 255;` creates a container called `red` that holds the number 255.
- **`for` loop** — a way to repeat a block of code a specific number of times, automatically counting as it goes.
- **RGB** — a way of describing color using three numbers: how much Red, how much Green, and how much Blue (each 0–255).
- **`setBrightness()`** — a dial for the whole ring that caps how bright all the pixels can get (0–255). Use 20–50 in a classroom.

## Warm-Up (~5 min)

Show two overlapping colored flashlights (or a projected image of additive color mixing) and ask:

> *"If you mix red paint and green paint, what do you get? What about red light and green light?"*

Take guesses — most students will say brown or dark green. Show them that red + green light = yellow. Ask:
> *"Why do you think that's different?"*

(No need to resolve it fully — just plant the question. You'll answer it during instruction.)

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Start from Lesson 1's working sketch.
2. Move the color numbers out of setPixelColor into variables:
     int r = 255;
     int g = 0;
     int b = 0;
   Then use r, g, b inside setPixelColor. Upload — same result.
3. Ask: "Why would I bother?" Then change r = 128 in one place and upload.
   Point out that if you had 10 setPixelColor calls, you'd only change ONE number.
4. Introduce the for loop by typing it live:
     for (int i = 0; i < 10; i++) {
       CircuitPlayground.setPixelColor(i, r, g, b);
     }
   Narrate each part: "i starts at 0, runs while i is less than 10, adds 1 each time."
5. Change g to 255. Upload. All pixels yellow.
6. Demonstrate setBrightness(20) in setup() — dims the whole ring.

KEY CONCEPTS:
- Variables let you change one number and have it affect the whole program.
- The loop counter i serves double duty: it's both the repetition count AND the pixel number.
- Additive color mixing: R+G=yellow, G+B=cyan, R+B=magenta, R+G+B=white, 0+0+0=off (not black).
- White is not "no color" — it's all three channels at full brightness.
- setBrightness() should be set low in a classroom to avoid glare and battery drain.

COMMON MISCONCEPTIONS:
- "255+255+255 would be really bright white" — yes, correct, that's the point.
- "Black" — the LED is off, not black. There is no black light.
- Students often confuse the loop variable i with a pixel they choose. Clarify:
  i counts from 0 to 9, which happens to be every pixel number.
-->

In Lesson 1 we called `setPixelColor` with raw numbers. Today we give those numbers names.

**Variables** store a value you want to use (and change) throughout your code:
```cpp
int r = 255;   // red channel
int g = 0;     // green channel
int b = 128;   // blue channel
```

`int` is the *type* — it tells the board this variable holds a whole number.

**`for` loops** repeat a block of code automatically:
```cpp
for (int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, r, g, b);
}
```
This sets pixel 0, then pixel 1, then pixel 2 … all the way to pixel 9. The variable `i` does double duty — it counts the repetitions *and* tells `setPixelColor` which pixel to change.

**Additive color mixing** (light, not paint):

| R   | G   | B   | Result |
|-----|-----|-----|--------|
| 255 | 0   | 0   | Red    |
| 0   | 255 | 0   | Green  |
| 0   | 0   | 255 | Blue   |
| 255 | 255 | 0   | Yellow |
| 0   | 255 | 255 | Cyan   |
| 255 | 0   | 255 | Magenta|
| 255 | 255 | 255 | White  |
| 0   | 0   | 0   | Off    |

**Limits of RGB:**
- Each channel has only 256 steps (0–255). Very subtle color differences may be impossible to represent — the board simply rounds to the nearest step it can make.
- Very high brightness drains the battery fast. `CircuitPlayground.setBrightness(30)` in `setup()` keeps everything comfortable.

## Guided Activity (~20 min)

**Step 1 — Start from starter code**
Upload the starter code. All 10 pixels should light up red.

**Step 2 — Mix a new color**
Change `g` from `0` to `255`. What color do you predict before you upload? Upload and check.

**Step 3 — Make it yours**
Change `r`, `g`, and `b` to make a color you like. Try a few combinations from the table above.

**Step 4 — Dim it down**
In `setup()`, call `CircuitPlayground.setBrightness(20)`. Upload. What changes?
Now try `setBrightness(200)`. Now back to `30`.

**Step 5 — Half the ring**
Change `i < 10` to `i < 5` in the `for` loop. What happens? Why?

**Step 6 — Predict before you upload**
Set `r = 255`, `g = 255`, `b = 0`. Before uploading, write down what color you expect.
Then upload. Were you right?

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

int r = 255;  // red   (0–255)
int g = 0;    // green (0–255)
int b = 0;    // blue  (0–255)

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, r, g, b);
  }
}
```

## Make It Yours (~remaining time)

- **Find your signature color** — mix an RGB combination that you'll use as your personal color for the rest of the unit. Write down the numbers.
- **Half-and-half ring** — make pixels 0–4 one color and pixels 5–9 a different color. (Hint: two loops, or set the two halves manually.)
- **Gradient attempt** — can you make the pixels gradually get brighter? Try changing `r` to `i * 25` inside the loop call and see what happens.
- **Challenge:** What RGB values produce the brightest possible white? What about a warm white (slightly orange-white, like a candle)? Experiment.

## Wrap-Up (~5 min)

<!-- Share-out: each student says their signature color values (r, g, b) out loud or holds up their board.
     Ask the class to predict what color it should be before the student reveals the board.
     This reinforces the RGB mental model and creates a moment of community/personalization.
     Record students' signature colors somewhere (whiteboard, shared doc) — you can reference them in future lessons. -->

Share your signature color with the class. Call out your three numbers — can your classmates predict the color before you hold up your board?

## Teacher Notes

<!--
PACING:
- Step 5 (half ring) often sparks good questions about why i < 5 works — let it breathe.
- The gradient in Make It Yours is intentionally imperfect (i*25 caps at 225, not 255 for i=9).
  If a sharp student notices, celebrate it: "that's a real precision issue with integer math."

RGB TABLE:
- Print or project the RGB table during independent work time — students will refer to it constantly.
- Consider printing it as a laminated card for their workstations.

COMMON BUG:
- Students often put the for loop in setup() instead of loop(). Either works here since the
  color doesn't change, but gently redirect them to loop() to build the right habit.

DIFFERENTIATION:
- Early finishers: push them toward the gradient challenge. It introduces the idea that
  a variable can be computed (not just set) — a preview of Lesson 3.
- Struggling students: focus on changing r, g, b values and seeing the result. The for loop
  syntax can be treated as a magic spell for now; the concept will recur.

SIGNATURE COLORS:
- This personalization moment matters. Students who name "their" color feel ownership
  over the device. Reference their colors in future lessons ("Amara, can you show us
  your cyan setup as the starting point?").
-->
