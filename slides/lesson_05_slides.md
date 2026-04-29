# Lesson 5 — Give It a Voice

---

# Warm-Up: What makes sounds different?

> What makes a flute sound higher than a tuba?  
> What is physically different about the sound waves?

If your board can play any frequency from 1 to 20,000 Hz, what do you predict happens at:

- 50 Hz?
- 440 Hz?
- 20,000 Hz?

---

# The function that makes sound

```cpp
CircuitPlayground.playTone(frequency, duration);
```

- **`frequency`** — the pitch in Hz. Higher number = higher pitch.
- **`duration`** — how long to play, in milliseconds. `1000` ms = 1 second.

---

# Frequency reference

| Note | Frequency |
|------|-----------|
| C4 (middle C) | 262 Hz |
| E4 | 330 Hz |
| G4 | 392 Hz |
| A4 (concert A) | 440 Hz |
| C5 | 523 Hz |

440 Hz is the note orchestras tune to before a performance.  
When frequency doubles, pitch goes up by one **octave**.

---

# playTone() is blocking

While the board plays a tone, **it does nothing else**.

| Call | How long it takes |
|------|-------------------|
| `setPixelColor()` | returns instantly |
| `playTone(440, 500)` | takes 500 ms to return |

A `delay()` after a note creates silence before the next one starts.  
Without any gap, two notes at the same pitch blur into one long tone.

---

# Open your starter code

Open **`Lesson05_GiveItAVoice.ino`**.

```cpp
void loop() {
  CircuitPlayground.playTone(440, 500);  // A4 -- change me!
  delay(50);
  CircuitPlayground.playTone(523, 500);  // C5 -- change me!
  delay(50);
}
```

Upload. The board plays two notes in a repeating loop.

---

# Step 2 — Change the pitch

Change `440` to each of these — one at a time, upload, listen:

- `880` — what do you notice? (880 = 440 × 2)
- `220` — what do you notice? (220 = 440 ÷ 2)
- `100` — what does it sound like?
- `4000` — at what point does it become hard to hear?

> When frequency doubles, the pitch goes up by one octave.

---

# Step 3 — Change the duration

Change the first `500` to `1000`. Upload — how does the feel change?  
Change it to `100`. Upload — how does that feel?

`duration` is how long each note lasts.  
Shorter values = faster, more staccato. Longer values = slower, more sustained.

---

# Step 4 — Add a third note

Add a third `playTone()` and `delay()` pair below the second:

```cpp
void loop() {
  CircuitPlayground.playTone(440, 500);
  delay(50);
  CircuitPlayground.playTone(523, 500);
  delay(50);
  CircuitPlayground.playTone(392, 500);  // add this
  delay(50);                              // add this
}
```

Pick any frequency you like for the third note.

---

# Step 5 — Trigger a tone from a sensor

Replace the contents of `loop()` with:

```cpp
if (CircuitPlayground.soundSensor() > 600) {
  CircuitPlayground.playTone(880, 200);
} else {
  CircuitPlayground.playTone(220, 200);
}
```

Upload. Clap near the board. Adjust `600` until it responds the way you want.

---

# Step 6 — Add lights

Before a `playTone()` call, add a `setPixelColor` so the ring color matches each note:

```cpp
for (int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 255, 0, 0);
}
CircuitPlayground.playTone(440, 500);
delay(50);
```

`setPixelColor()` returns instantly — so the color changes, then the tone plays.  
They feel simultaneous even though they aren't.

---

# Make It Yours

- **Find a three-note pattern you like** — experiment until you have a short sequence that sounds intentional. Write down the numbers.
- **Link sound to color** — high notes get warm or bright colors; low notes get cool or dim colors.
- **Button-triggered** — only play when the left button is held: `CircuitPlayground.leftButton()` returns `true` while pressed.
- **Challenge:** Rising scale — five notes, each 50 Hz higher than the last. Use a `for` loop: `playTone(200 + i * 50, 200)`.

---

# Exit Ticket

> What is **frequency**? What is **duration**?  
> Give a concrete example using actual numbers from today.
