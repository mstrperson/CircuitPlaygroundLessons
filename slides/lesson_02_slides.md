# Lesson 2 — Painting with Light

---

# Warm-Up: Mixing colors

> If you mix red paint and green paint, what do you get?  
> What about red light and green light?

Most people say brown or dark green.

The answer for light is **yellow** — and today you'll see exactly why.

---

# The problem with Lesson 1's approach

Imagine lighting all 10 pixels red this way:

```cpp
CircuitPlayground.setPixelColor(0, 255, 0, 0);
CircuitPlayground.setPixelColor(1, 255, 0, 0);
CircuitPlayground.setPixelColor(2, 255, 0, 0);
CircuitPlayground.setPixelColor(3, 255, 0, 0);
// ...and so on
```

Now imagine you want to change the color. You'd edit **10 lines**.  
There is a better way.

---

# Variables: named containers

Instead of writing `255` everywhere, give the number a name:

```cpp
int r = 255;   // red channel
int g = 0;     // green channel
int b = 0;     // blue channel
```

`int` means this variable holds a whole number.

Now change `g` in one place and every pixel changes.

---

# The for loop

```cpp
for (int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, r, g, b);
}
```

Read it out loud:
- Start with `i = 0`
- Keep going while `i < 10`
- After each step: `i++` (add 1 to i)

`i` counts 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 — which happen to be every pixel number.

---

# Mixing light is not mixing paint

| R   | G   | B   | Color   |
|-----|-----|-----|---------|
| 255 | 0   | 0   | Red     |
| 0   | 255 | 0   | Green   |
| 0   | 0   | 255 | Blue    |
| 255 | 255 | 0   | Yellow  |
| 0   | 255 | 255 | Cyan    |
| 255 | 0   | 255 | Magenta |
| 255 | 255 | 255 | White   |
| 0   | 0   | 0   | Off     |

Red + green light = **yellow** (not brown).  
All three at full = **white** (not "very bright whatever color").  
All three at 0 = **off** — the LED is dark, not "black."

---

# Open your starter code

Open **`Lesson02_PaintingWithLight.ino`**.

```cpp
int r = 255;
int g = 0;
int b = 0;

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

Upload. All 10 pixels should light up red.

---

# Step 2 — Mix a new color

Find the variable at the top:

```cpp
int g = 0;
```

**Change `g` from `0` to `255`.**

Before you upload — what color do you predict?

Upload and check.

---

# Step 3 — Find your signature color

Change `r`, `g`, and `b` to any values you like (0–255 each).

Aim for a color you want to call yours — you'll use it again in later lessons.

Write your three numbers down:

```
My signature color:  r = ___   g = ___   b = ___
```

---

# Step 4 — Control the brightness

In `setup()`, find:

```cpp
CircuitPlayground.setBrightness(30);
```

**Change `30` to `200`.** Upload. What happens?  
**Change it to `5`.** Upload. What happens?  
**Set it back to `30`** — high brightness drains the battery quickly.

---

# Step 5 — Half the ring

Inside the `for` loop header, find:

```cpp
for (int i = 0; i < 10; i++)
```

**Change `10` to `5`.** Upload.

> What happens? Why does changing that one number only light half the ring?

---

# Make It Yours

- **Share your signature color** — call out your three numbers. Can your classmates predict the color before you hold up your board?
- **Half-and-half** — make pixels 0–4 one color and pixels 5–9 a different color. (Hint: you'll need two `for` loops.)
- **Gradient** — inside the loop, try changing `r` to `i * 25` inside the `setPixelColor` call instead of using the variable. What happens? Why doesn't it reach 255?
- **Challenge:** Find an RGB combination that looks like warm candlelight. What makes it different from `(255, 255, 255)`?

---

# Exit Ticket

Share your signature color with the class.

> Call out your three numbers.  
> Can your classmates predict the color before you show them your board?
