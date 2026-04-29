# Lesson 4 — More Senses

---

# Warm-Up: Your phone is covered in sensors

Your phone knows when you rotate it, when you tap, how bright the room is, where you are on Earth.

> What physical thing is it actually measuring in each case?

Your Circuit Playground has several of the same sensors built in. Today we find out what numbers they report — and make the board do something with those numbers.

---

# Three new sensors

```cpp
int sound  = CircuitPlayground.soundSensor();    // 0–1023, louder = higher
float temp = CircuitPlayground.temperature();    // degrees Celsius
float x    = CircuitPlayground.motionX();        // tilt left/right, m/s²
```

Notice the new word: `float`.

---

# float vs. int

| | `int` | `float` |
|---|-------|---------|
| Stores | whole numbers only | numbers with a decimal point |
| Example value | `5` | `22.4` |
| What happens with `= 9.8` | stores `9` — silently drops the decimal | stores `9.8` |

Temperature and motion return decimals.  
Use `float` when storing them, or you silently lose precision.

---

# The Serial Monitor

A window in the Arduino IDE that lets the board send text to your computer while it runs.

**Set it up once in `setup()`:**

```cpp
Serial.begin(9600);
```

**Print anything from `loop()`:**

```cpp
Serial.print("Sound: ");
Serial.println(sound);
```

Open it: **Tools → Serial Monitor** (or Ctrl+Shift+M).  
Set the baud rate in the bottom-right corner to **9600**.

---

# Open your starter code

Open **`Lesson04_MoreSenses.ino`**.

Upload it. Then open the Serial Monitor.  
You should see three values printing side by side, updating every 200 ms.

---

# Step 2 — Explore the range

Watch the Serial Monitor while you:

- **Clap** loudly near the board. How high does sound spike?
- **Cup your hands** around the board. What does temperature read? Blow warm air on it.
- **Tilt** the board. Which axis changes? What does X read when the board is flat on the desk?

Write down the range you observe for each sensor.

> Why does motionX() read a non-zero number when the board is completely still?

---

# Step 3 — Make the ring react to sound

Comment out (or delete) the `Serial.print` lines.  
Add this to `loop()`:

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

Upload. Clap near the board. Adjust `600` until the response feels right for your room.

---

# Step 4 — Design your own reaction

Replace the sound condition with one of your own.

First, write your idea in plain English:

> "When ___, the board should ___."

Then write the code. You can use:  
`soundSensor()` / `temperature()` / `motionX()` / `motionY()` / `motionZ()`

---

# Make It Yours

- **Thermometer ring** — use `map()` to translate temperature (roughly 15–35°C in a classroom) to a color. Cold → blue, warm → red.
- **Shake detector** — if `motionX()` or `motionY()` exceeds `5.0`, flash all pixels white.
- **Sound meter** — use `map()` to translate the sound level to a pixel count. Loud = all 10 on, quiet = 0. (Hint: `map()` the sound value to a count, then use that count as the limit in your `for` loop.)
- **Challenge:** Combine two sensors — ring color set by temperature, ring brightness set by sound level.

---

# Exit Ticket

> Name one sensor you used today and describe the range of values it reported in your classroom.

The point: sensor values are raw numbers in arbitrary units. Learning the range by experimenting is a real programming skill.
