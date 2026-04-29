# Lesson 1 — Hello, Pixels!

---

# What do you notice?

Hold up the Circuit Playground and look at it.

- What shapes do you see?
- What do you think those small gold circles are for?
- If you wanted just ONE light to turn on — what would you need to tell the computer?

---

# Meet the Circuit Playground

**10 NeoPixel LEDs** arranged in a ring.

They are numbered **0 through 9**, starting at the USB connector, going clockwise around the board.

*The board numbers them from 0, not 1. Pixel 10 does not exist.*

---

# Two rooms your code lives in

```cpp
void setup() {
  // Runs ONCE when the board turns on.
}

void loop() {
  // Runs FOREVER after setup() finishes.
}
```

`setup()` — for getting ready.  
`loop()` — for doing things over and over.

Today, all our code goes in `setup()`.

---

# The line that wakes everything up

The very first thing in `setup()` must always be:

```cpp
CircuitPlayground.begin();
```

This starts the library and wakes up everything on the board. Without it, nothing else works.

---

# The line that lights an LED

```cpp
CircuitPlayground.setPixelColor(pixel, red, green, blue);
```

Four numbers:

| Argument | What it means | Range |
|----------|--------------|-------|
| `pixel`  | Which LED?   | 0–9   |
| `red`    | How much red?   | 0–255 |
| `green`  | How much green? | 0–255 |
| `blue`   | How much blue?  | 0–255 |

`0` = none. `255` = full brightness.

---

# Open your starter code

Open **`Lesson01_HelloPixels.ino`** in the Arduino IDE.

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

Click **Upload**. One red LED should light up.

---

# What just happened?

- `CircuitPlayground.begin()` woke up the hardware.
- `setPixelColor(0, 255, 0, 0)` turned pixel 0 to full red.
- `loop()` is running forever — but it's empty, so nothing keeps changing.

> The light stays on because we turned it on and never told it to turn off.

---

# Step 2 — Change which pixel

Find this line:

```cpp
CircuitPlayground.setPixelColor(0, 255, 0, 0);
```

**Change the first `0` to `5`.** Upload. Which pixel lit up?

Try `3`. Try `9`. Now try `10`.

> What happens with pixel 10? Why?

---

# Step 3 — Change the color

The last three numbers are **red, green, blue**.

Try these — **predict the color before you upload:**

```cpp
CircuitPlayground.setPixelColor(0, 0, 255, 0);    // ?
CircuitPlayground.setPixelColor(0, 0, 0, 255);    // ?
CircuitPlayground.setPixelColor(0, 255, 255, 0);  // ?
CircuitPlayground.setPixelColor(0, 0, 0, 0);      // ?
```

---

# Step 4 — Light two pixels at once

Add a second `setPixelColor` line below the first:

```cpp
void setup() {
  CircuitPlayground.begin();

  CircuitPlayground.setPixelColor(0, 255, 0, 0);
  CircuitPlayground.setPixelColor(5, 0, 0, 255);  // add this line
}
```

Upload. Both pixels should stay lit.

---

# Make It Yours

- **Pick your home-base pixel** — choose one pixel (0–9) and make it glow your favorite color.
- **Three pixels, three colors** — add a third `setPixelColor` line with a different pixel and a different color.
- **Challenge:** Light all 10 pixels using 10 `setPixelColor` lines. (There is a better way coming in Lesson 2 — but try it by hand first and notice why the better way is worth learning.)

---

# Exit Ticket

Before you leave, complete one of these out loud:

> "Pixel ___ on my board shows color ___."  
> "Something I noticed: ___."  
> "Something I'm confused about: ___."

**Your board must have at least one pixel lit with a color you chose before class ends.**
