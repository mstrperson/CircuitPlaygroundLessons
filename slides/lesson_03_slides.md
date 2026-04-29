# Lesson 3 — Sensing Light

---

# Before you touch any code

An automatic night light turns on when it gets dark.

> What does the light sensor need to *decide* to make that happen?

Describe the logic in plain English first.

---

# The light sensor

```cpp
int light = CircuitPlayground.lightSensor();
```

- Returns a number from **0** (completely dark) to **1023** (very bright)
- Must be called inside `loop()` so it keeps updating
- The board doesn't "understand" dark or bright — it just gives you a number

---

# The range problem

The sensor gives you `0–1023`.  
`setPixelColor` wants `0–255`.

Those ranges don't match.

---

# map() rescales one range to another

```cpp
int brightness = map(light, 0, 1023, 0, 255);
```

Think of two number lines:

```
sensor:  0 ─────────────────── 1023
color:   0 ──────────────────── 255
```

`map()` finds where your sensor value sits on the top line  
and returns the matching position on the bottom line.

---

# if / else gives the board two choices

```cpp
if (light < 400) {
  // this runs when it's dark
} else {
  // this runs when it's bright
}
```

The board checks the condition once every time through `loop()`.  
**Exactly one branch runs each time.**

The number `400` is *your* design choice — not a scientific fact.

---

# Open your starter code

Open **`Lesson03_SensingLight.ino`**.

```cpp
void loop() {
  int light = CircuitPlayground.lightSensor();
  int brightness = map(light, 0, 1023, 0, 255);

  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, brightness, 0, 0);
  }
}
```

Upload. Wave your hand slowly over the board. The ring should get brighter and dimmer.

---

# Step 2 — White brightness

Change the `setPixelColor` call to use `brightness` for all three channels:

```cpp
CircuitPlayground.setPixelColor(i, brightness, brightness, brightness);
```

Upload. Now the ring goes from **off** in the dark to **white** in bright light.

> What color does it show in the middle? Why?

---

# Step 3 — Add an if / else

Below the `map()` line, add this block:

```cpp
if (light < 300) {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 0, 255);    // dark → blue
  }
} else {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);    // bright → red
  }
}
```

Upload. Cover the sensor with your hand. Does it switch colors?

---

# Step 4 — Tune your threshold

Your threshold is the `300` in `if (light < 300)`.

That number is your decision. Try:

- `100` — did it switch too soon?
- `700` — did it switch too late?

Set it to whatever feels like "just got dark" for your room.

---

# Step 5 — Reverse the map

Change the `map()` call from:

```cpp
int brightness = map(light, 0, 1023, 0, 255);
```

to:

```cpp
int brightness = map(light, 0, 1023, 255, 0);
```

**Before you upload — what do you predict will happen?**

Upload and check. When would a reversed map be useful?

---

# Make It Yours

- **Your signature reaction** — instead of red or blue, use your signature color from Lesson 2 when the board detects dark.
- **Three states** — add an `else if` so there are three color states: dark, medium, and bright. You'll need: `if` / `else if` / `else`.
- **Map a different channel** — what if only the green channel reacts to light? Try mapping `brightness` to `g` only, with the other channels fixed.
- **Challenge:** Split the ring — the top five pixels brighten as light increases; the bottom five dim. Use two `for` loops with a reversed `map()` for one of them.

---

# Exit Ticket

In your own words, answer this:

> What does `map()` do?  
> Use the words **sensor** and **color** in your answer.
