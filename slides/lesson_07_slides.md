# Lesson 7 — Touch Magic

---

# Before the code: try this

Touch the gold pad labeled **A2** on your board with your finger.

> What do you think the board can detect from that?  
> How is it different from pressing a button?

How does your phone's touchscreen know where your finger is — without you pushing down?

---

# Capacitive touch

The pads don't need to be pressed.

They sense the tiny change in electrical charge caused by your finger's presence nearby.  
The same principle your phone's touchscreen uses.

`readCap()` returns a **number** — not just true or false.  
You decide what counts as "touched."

---

# readCap()

```cpp
int touch = CircuitPlayground.readCap(2);
```

Pass it a **digital pin number:**

**Valid pins: `0, 1, 2, 3, 6, 9, 10, 12`**

> Note: the pads on your board may be labeled A1, A2, etc.  
> `readCap()` takes the **digital pin number** — use `2`, not `A2`.

Returns roughly:
- **0–30** at rest (no finger)
- **100–1000+** when touched

---

# Choosing a threshold

The return value is a number, so you decide when "touched" begins:

```cpp
if (touch > 50) {
  // finger is touching
} else {
  // no finger
}
```

The right threshold depends on your board and your environment.  
**Print the value first** to see what your board actually reads at rest.

---

# Open your starter code

Open **`Lesson07_TouchMagic.ino`**.

Upload it. Open the Serial Monitor (Tools → Serial Monitor, baud rate **9600**).

Watch the number change. Touch the A2 pad with your finger.

---

# Step 1 — Watch the values

With the Serial Monitor open:

- What is the **idle value** when you are not touching the pad?
- What is the value when you **touch** A2?
- What happens if you hover your finger just above the pad without touching?

Write down both the idle value and the touched value.

---

# Step 2 — Find your threshold

Your threshold is the `50` in:

```cpp
if (touch > 50) {
```

Change `50` to a number between your idle value and your touched value.

Upload. Touch the pad. Does the ring turn blue? Release — does it go off?  
Adjust if it feels hair-trigger or too slow to respond.

---

# Step 3 — Add a sound

Inside the `if (touch > ...)` block, add a `playTone()` call:

```cpp
if (touch > 50) {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 0, 255);
  }
  CircuitPlayground.playTone(440, 200);    // add this line
}
```

Upload. Touch the pad. The board should light up and play a note.

---

# Step 4 — Add a second pad

Add a second `readCap()` call for **pin 6**:

```cpp
int touch6 = CircuitPlayground.readCap(6);
```

Then add a second `if` block that makes pin 6 trigger a different color and a different note.

---

# Step 5 — Print both values

Add print statements so you can watch both pads at once:

```cpp
Serial.print("Pin 2: ");
Serial.print(touch);
Serial.print("   Pin 6: ");
Serial.println(touch6);
```

What happens in the Serial Monitor when you touch **both pads at the same time**?

---

# Make It Yours

- **Mini piano** — four pads, four notes: pin 1 → c4, pin 2 → e4, pin 3 → g4, pin 6 → c5.
- **Color chooser** — each pad selects a different ring color. The last pad touched wins.
- **Touch alarm** — ring glows dim white normally. Touching pad 9 triggers a red flash and a fast, loud tone.
- **Challenge:** "Hold to brighten" — the longer you hold a pad, the brighter the ring gets. Release to reset. (Hint: count how many times through `loop()` the pad stays touched.)

---

# Exit Ticket

> Why does `readCap()` return a **number** instead of just `true` or `false`?  
> What advantage does that give you as a programmer?

Target idea: a number lets you set your own threshold and tune it to your room's conditions. A yes/no answer wouldn't let you adjust for different environments.
