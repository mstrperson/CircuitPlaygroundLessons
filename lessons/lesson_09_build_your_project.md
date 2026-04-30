# Lesson 9 — Build Your Project

## Learning Goals
- Students will be able to choose a starter scaffold that matches their project brief and modify it toward their design.
- Students will be able to form a clear, specific question for an AI assistant and evaluate the answer it gives.
- Students will be able to demo their working device and explain at least one design decision they made.

## New Vocabulary
- **scaffold** — starter code that handles the structure of a project so you can focus on the parts that are specific to your design.
- **AI assistant** — a conversational tool (like MagicSchool or Flint) that can answer coding questions, suggest syntax, and help debug. It is a tool, not an authority — always check its answers against what you know.
- **prompt** — the question or instruction you give an AI assistant. A specific prompt gets a more useful answer than a vague one.

---

## How This Lesson Works

1. Find the scaffold below that best matches your project brief from Lesson 8.
2. Upload it and confirm it runs.
3. Modify it one step at a time toward your design, testing after each change.
4. When you get stuck on syntax, use the AI guide (below) to get unstuck.
5. Demo your device at the end of class.

---

## Physical Making

The Maker Space gives you tools that can make your project feel like a real
object, not just a board sitting on a desk. You don't have to use them, but
they're available.

### Copper tape and wire

Capacitive touch is not limited to the gold pads on the board. You can extend
any touch pad to a new surface:

1. Press a strip of **copper tape** firmly against one of the Circuit Playground's
   gold touch pads (the ones with alligator-clip-sized holes around the edge).
   Secure it with a small piece of regular tape so it stays in contact.
2. Route the copper tape — or a wire clipped to the pad with an alligator clip —
   to whatever surface you want to be touchable: a paper key, a cardboard button,
   a foil shape, a drawing.
3. Touch that surface. `readCap()` will still detect your finger.

**Threshold adjustment:** A larger conductive surface reads a higher baseline.
Use the Serial Monitor to find your idle value and set your threshold about 50
above that number (instead of the default 50).

**Ideas:** paper piano keys, a touch-sensitive drawing, a secret button hidden
under a label, interactive spots on a creature's body.

### Enclosures and housing

The Circuit Playground is small enough to hide inside almost anything:

- **Cardboard** — cut holes for the USB cable and the light sensor if needed.
  The LEDs shine through thin paper easily.
- **Foam** — easy to carve a pocket for the board; diffuses light softly.
- **Fabric** — the board can be sewn into a pouch; copper tape traces can be
  stitched with conductive thread.
- **3D printing / laser cutting** — available in the Maker Space. Use these if
  you need a precise shape that cardboard genuinely can't make. Talk to the
  teacher first and plan the build time — a print or cut takes longer than
  a cardboard prototype.

**Rule of thumb:** Build the code first, prototype the enclosure in cardboard,
then upgrade the housing if you want to.

---

## Project Scaffolds

### Scaffold A — Mood Light

**For projects where:** the ring color shifts continuously based on one or more sensors. No buttons, no events — just a ring that always reflects the environment.

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  // Read your chosen sensors (use only the ones your project needs)
  int light = CircuitPlayground.lightSensor();   // 0–1023
  int sound = CircuitPlayground.soundSensor();   // 0–1023
  float temp = CircuitPlayground.temperature();  // degrees C

  // Map each sensor to a color channel (0–255)
  int r = map(light, 0, 1023, 0, 255);    // light  → red
  int g = map(sound, 0, 1023, 0, 255);    // sound  → green
  int b = map((int)temp, 15, 35, 255, 0); // cool=blue, warm=no blue

  // Apply to all pixels
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, r, g, b);
  }

  delay(50);
}
```

**Modify toward your design:**
- Remove sensors you aren't using; add ones you are
- Change which sensor maps to which color channel
- Adjust the `map()` ranges to match what your sensors actually read in your room (use Serial Monitor from Lesson 4 to check)

---

### Scaffold B — Touch Instrument

**For projects where:** each touch pad plays a note and lights the ring. Designed to be performed with.

```cpp
#include <Adafruit_CircuitPlayground.h>

// Add or remove note defines to match the notes in your design
#define NOTE_C4  262
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_C5  523

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  // Read each touch pad you are using (valid pins: 0,1,2,3,6,9,10,12)
  int t1 = CircuitPlayground.readCap(1);
  int t2 = CircuitPlayground.readCap(2);
  int t3 = CircuitPlayground.readCap(3);
  int t6 = CircuitPlayground.readCap(6);

  if (t1 > 50) {
    CircuitPlayground.playTone(NOTE_C4, 150);
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
  } else if (t2 > 50) {
    CircuitPlayground.playTone(NOTE_E4, 150);
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 255, 0);
  } else if (t3 > 50) {
    CircuitPlayground.playTone(NOTE_G4, 150);
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  } else if (t6 > 50) {
    CircuitPlayground.playTone(NOTE_C5, 150);
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 255, 0);
  } else {
    CircuitPlayground.clearPixels();
  }
}
```

**Modify toward your design:**
- Change the notes assigned to each pad
- Change the colors assigned to each pad
- Add more pads by adding more `readCap()` calls and `else if` branches
- Add more note constants using `#define` for notes you want

---

### Scaffold C — Motion Toy

**For projects where:** tilting, shaking, or flipping the board changes what happens.

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  float x = CircuitPlayground.motionX();  // left/right tilt
  float y = CircuitPlayground.motionY();  // forward/back tilt
  float z = CircuitPlayground.motionZ();  // up/down (≈9.8 when flat)

  if (x > 5.0) {
    // tilted right
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
  } else if (x < -5.0) {
    // tilted left
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 0, 0, 255);
  } else if (z < 5.0) {
    // flipped upside-down (gravity now reads low on Z)
    for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 0, 255);
    CircuitPlayground.playTone(880, 200);
  } else {
    // roughly level
    CircuitPlayground.clearPixels();
  }

  delay(50);
}
```

**Modify toward your design:**
- Adjust the tilt thresholds (`5.0`, `-5.0`) — use Serial Monitor to see real values
- Add behaviors for Y-axis tilt
- Add a shake detection: a sudden large change in any axis means the board was shaken

---

### Scaffold D — Creature / Story Device

**For projects where:** the board has a resting personality and reacts to touch, claps, or shakes.

```cpp
#include <Adafruit_CircuitPlayground.h>

#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_C5  523

// Resting color — change these to your creature's color
int restR = 0;
int restG = 80;
int restB = 20;

void showRestingState() {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, restR, restG, restB);
  }
}

void happyReaction() {
  for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 200, 0);
  CircuitPlayground.playTone(NOTE_G4, 150);  delay(50);
  CircuitPlayground.playTone(NOTE_A4, 150);  delay(50);
  CircuitPlayground.playTone(NOTE_C5, 300);
  delay(200);
  showRestingState();
}

void scaredReaction() {
  for (int i = 0; i < 10; i++) CircuitPlayground.setPixelColor(i, 255, 0, 0);
  CircuitPlayground.playTone(150, 500);
  delay(200);
  showRestingState();
}

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
  showRestingState();
}

void loop() {
  int touch = CircuitPlayground.readCap(2);   // gentle touch → happy
  int sound  = CircuitPlayground.soundSensor(); // clap → scared

  if (touch > 50) {
    happyReaction();
  } else if (sound > 700) {
    scaredReaction();
  }

  delay(50);
}
```

**Modify toward your design:**
- Change `restR`, `restG`, `restB` to your creature's resting color
- Rewrite `happyReaction()` and `scaredReaction()` — or rename them to match your creature's personality
- Add a third reaction function (e.g., `sleepyReaction()`, triggered by darkness)
- Change which touch pad or sensor triggers which reaction

---

### Scaffold E — Environment Monitor

**For projects where:** the board acts as a scientific instrument — displaying a measurement as a color scale, sound alert, or pixel meter.

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
  Serial.begin(9600);
}

void loop() {
  // Choose your measurement — comment out the ones you don't use
  float temp  = CircuitPlayground.temperature();   // degrees C
  int   light = CircuitPlayground.lightSensor();   // 0–1023
  int   sound = CircuitPlayground.soundSensor();   // 0–1023

  // Example: temperature displayed as blue (cold) → red (warm)
  // Adjust 15 and 35 to the actual range in your room
  int r = map((int)temp, 15, 35, 0, 255);
  int b = map((int)temp, 15, 35, 255, 0);

  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, r, 0, b);
  }

  // Alert: play a tone if it gets too loud
  if (sound > 750) {
    CircuitPlayground.playTone(880, 100);
  }

  // Print readings to Serial Monitor so you can verify calibration
  Serial.print("Temp: "); Serial.print(temp);
  Serial.print("  Light: "); Serial.print(light);
  Serial.print("  Sound: "); Serial.println(sound);

  delay(200);
}
```

**Modify toward your design:**
- Replace temperature with the measurement your project cares about
- Adjust the `map()` ranges after observing real values in Serial Monitor
- Add a pixel "meter" — light N pixels based on a sensor value, where N = `map(value, low, high, 0, 10)`

---

## Getting Help from an AI Assistant

When you get stuck on a specific syntax detail — how to write something you already understand conceptually — an AI assistant like **MagicSchool** or **Flint** can help you get the exact code right.

### The golden rule

> **You design. The AI writes syntax.**

You already know what you want the device to do. The AI doesn't know your project, your board, or what you've learned. Your job is to give it enough context that it can help with the specific piece you're stuck on.

---

### How to write a good prompt

A useful prompt has three parts:

| Part | What to include |
|------|----------------|
| **Context** | What board you're using, what library, and what you're building |
| **Goal** | What specific behavior you want in plain English |
| **Question** | The exact syntax detail you need help with |

---

### Examples

**Vague prompt (less useful):**
> *"How do I make LEDs react to sound?"*

The AI doesn't know what board, what library, or what "react" means to you. It will give a generic answer that may not match your setup.

**Specific prompt (more useful):**
> *"I'm using an Adafruit Circuit Playground with the Adafruit Circuit Playground Arduino library. In my loop(), I'm reading `CircuitPlayground.soundSensor()` which returns 0–1023. I want to light up more pixels the louder the sound is — 0 pixels when quiet, all 10 when very loud. Can you show me how to use map() and a for loop to do that?"*

The AI now knows: the board, the library, the function you're already using, the exact behavior you want, and which concepts you've already been introduced to.

---

### Prompts to try

Copy and adapt these for your own project:

**For a sensor → color question:**
> *"I'm using an Adafruit Circuit Playground with the Adafruit Circuit Playground library. `CircuitPlayground.temperature()` returns a float in Celsius. My classroom is between about 18°C and 28°C. I want to show blue when it's cold and red when it's warm, with a smooth transition. Can you show me how to map the temperature to the red and blue channels of setPixelColor?"*

**For a touch pad question:**
> *"I'm using `CircuitPlayground.readCap(pin)` on an Adafruit Circuit Playground. The valid pin numbers are 0, 1, 2, 3, 6, 9, 10, 12. I want to check if any of four pads are being touched and play a different tone for each one. Can you show me the if/else if structure for checking four readCap() calls and calling playTone() in each branch?"*

**For a motion question:**
> *"I'm using `CircuitPlayground.motionX()` which returns a float in m/s². I want to detect when the board is shaken hard — a big sudden change in X. Can you show me how I might check for a large absolute value of motionX() and trigger a short light-and-sound reaction when it happens?"*

**For a structure question:**
> *"I'm writing an Arduino sketch for an Adafruit Circuit Playground. I have a function called `happyReaction()` that plays a melody and flashes lights. I want this function to run only once when a touch pad is first pressed — not over and over while I hold it. How do I track whether the pad was already pressed last loop, so I only trigger the reaction on the transition from not-touched to touched?"*

---

### What to do with the AI's answer

1. **Read it before you paste it.** Do you understand what each line does? If not, ask the AI to explain it.
2. **Compare it to what you know.** Does it use `CircuitPlayground.` calls the way you've learned? Does it use functions from the right library?
3. **Test it in isolation first.** Paste just the new piece into your sketch and test that one behavior before adding more.
4. **If it doesn't work, tell the AI exactly what happened.** Example: *"I tried your code and the Serial Monitor showed an error on line 12: 'readCap was not declared in this scope.' Here is my full sketch: [paste it]. What might be wrong?"*

---

## Demo and Share (~last 10 min)

When time is called, be ready to show:

1. **Resting state** — what does the board do when nothing is triggering?
2. **At least two behaviors** — trigger each one for the class.
3. **One sentence** — explain one decision you made: *"I chose [X] because [Y]."*

## Teacher Notes

<!--
LESSON STRUCTURE:
This is primarily a work period. Your role is to circulate and unblock.
Recommended timing:
  0–5 min:   Students find their scaffold, upload, and confirm it runs
  5–35 min:  Work time (circulate constantly; this is where the teaching happens)
  35–45 min: Polish and wrap
  45–50 min: Share-out (3–4 demos, or pair-shares)

THE AI ASSISTANT SECTION — FRAMING FOR STUDENTS:
- Before students open the AI tool, read the "golden rule" together:
  "You design. The AI writes syntax."
- Stress that the AI does not know their project. They must give context.
- Encourage them to ask the AI to EXPLAIN an answer, not just give it.
  "Can you explain what each line does?" is always a valid follow-up.
- MagicSchool and Flint are designed for educational settings and are FERPA-compliant.
  Check your school's approved tools list before the lesson.

WHEN TO DIRECT STUDENTS TO THE AI VS. HELPING DIRECTLY:
- If a student has a conceptual question ("why doesn't my if/else work?"): help them directly.
  This is understanding, not syntax — the AI will give them an answer they may not understand.
- If a student has a syntax question ("how do I write a for loop that counts backwards?"):
  send them to the AI with a good prompt. This is exactly what it's for.
- If a student has a bug: have them print the sensor values first (Serial Monitor).
  Once they know what the values actually are, they'll often solve it themselves.

COMMON SITUATIONS:
- "It doesn't do anything." → Is it uploaded? Is the right port selected? Is begin() in setup()?
- "My touch pad won't trigger." → Print the readCap() value. Check the pin number.
  Only: 0, 1, 2, 3, 6, 9, 10, 12.
- "The AI gave me code that uses analogRead() instead of CircuitPlayground.soundSensor()."
  → This is a teachable moment. The AI didn't know about the library. Their prompt
  needed more context. Have them re-prompt with the library name included.
- "I don't know how to do [X]." → Ask: "Do you know what you want it to DO?
  Write that in one sentence. That's your AI prompt."

PHYSICAL MAKING — MANAGEMENT NOTES:
- Budget 5–10 extra minutes if students are building enclosures. Physical making
  expands scope unpredictably; a student who spends 20 minutes on cardboard
  may not finish their code. Coach: "Get the code working first. Then build."
- Copper tape connections: the most common failure is insufficient contact between
  the tape and the gold pad. Have students press firmly and add a small piece of
  regular tape on top to hold it. If readCap() reads 0 at all times, the connection
  is probably broken.
- If a student wants to use the 3D printer or laser cutter: ask them to sketch
  the design on paper first and explain why cardboard won't work. If the reason
  is sound, coordinate with whoever manages the equipment. A simple box lid
  usually takes 30–60 min to print — plan accordingly.
- Remind students that the board needs USB access for uploading. Leave a gap
  in any enclosure for the cable, or plan to upload before sealing.

ASSESSMENT:
- The "one decision you made" share-out is the most useful formative signal.
  A student who can say "I used else if instead of if because I only wanted one thing
  to happen at a time" understands more than their code might show.
- Consider a brief 3-question exit reflection:
  1. What does your device do?
  2. What was the hardest part to figure out?
  3. What would you add with more time?
-->
