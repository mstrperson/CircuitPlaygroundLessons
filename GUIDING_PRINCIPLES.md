# Circuit Playground Lessons — Guiding Principles

---

## The Base Project

The **Adafruit Circuit Playground** (Express or Bluefruit) is a self-contained
microcontroller board designed for learning.  Everything a student needs is
already on the board:

| Hardware | What it does |
|----------|-------------|
| 10 NeoPixel RGB LEDs | Full-color programmable lights, arranged in a ring |
| Light sensor | Reports ambient brightness (0–1023) |
| Sound sensor / microphone | Reports ambient sound level (0–1023) |
| Temperature sensor | Reports temperature in °C or °F |
| 3-axis accelerometer | Reports tilt and motion on X, Y, Z axes |
| Speaker / buzzer | Plays tones at a specified frequency and duration |
| Left + Right buttons | Simple digital push-buttons |
| Capacitive touch pads | 8 pads (digital pins 0, 1, 2, 3, 6, 9, 10, 12) that sense a finger's presence without pressing |
| Infrared send/receive | (not covered in this series) |

The **Adafruit Circuit Playground Arduino library** wraps all of this in a
single object: `CircuitPlayground`.  Every student call goes through this
object — there is no need to manipulate pins, registers, or hardware directly.
The library's Hello World moment is a single function call that lights up an LED.

---

## Audience

- **Grade:** 6th grade
- **Prior experience:** Students have had some very limited experience programming in Processing.  They are familiar with the `setup()` and `loop()` structure, and have seen some flow control statements and generally know what variables are.
- **Course context:** Continuing first text-based programming experience.  This series
  is the students' introduction to Arduino/C++ syntax.
- **Class format:** Each lesson is one class period (~50 minutes).

---

## Physical Environment

The class meets in a **Maker Space**, which has direct bearing on what projects
are achievable and how the final lessons should be framed.

| Resource | Relevance to this series |
|----------|-------------------------|
| **Copper tape** | Extends capacitive touch to any conductive surface. Students can route a strip from a touch pad to a drawing, a cardboard cutout, a piece of foil — anything that conducts. The `readCap()` threshold typically needs to be raised (try 100–200) for extended surfaces, since more copper = more capacitance. |
| **Hookup wire / alligator clips** | Same extension capability as copper tape; useful for connecting pads to objects at a distance. |
| **Craft supplies** (cardboard, foam, fabric, paper) | Students can embed the Circuit Playground into a physical object — a stuffed animal, a box, a wearable. The board's small size makes it easy to hide inside a creation. |
| **3D printer / laser cutter** | Available but students in this course have not had explicit training. A student with a strong reason (an enclosure shape that can't be made from cardboard) may use one with appropriate supervision and coordination. Not expected; not promoted as a default. |

**Key implication for Lessons 8–9:** Students should be encouraged to think about
what their device *looks like physically*, not just what it *does in code*.
A touch instrument is more compelling when the pads are copper-tape keys on a paper keyboard.
A creature is more alive when it lives inside a cardboard body.
The project brief (Lesson 8) explicitly asks for a physical form.

---

## Entry Approach: Output First

Students call one function and something happens on the physical board before
they know what a variable, loop, or function is.  The "wow before the why"
principle is especially powerful here because the result is a glowing LED they
can hold in their hand.

The very first line of student code is:
```cpp
CircuitPlayground.setPixelColor(0, 255, 0, 0);
```
One LED turns red.  That's it.  That's Lesson 1.

We chose **Output First** over Objects First or Problem First because:
- The board already exists as a physical "object" — students don't need to
  construct one in code.
- The first result is tangible and shareable in a way that a graph or number
  on screen is not.
- Color is viscerally satisfying and requires no prior CS knowledge to find
  meaningful.

---

## Narrative Thread: The Evolving Device

There is no persistent code object in this series (unlike a sprite or
character class).  The narrative thread is the **physical board itself**.

The running question throughout the series is:
> *What can your Circuit Playground do now that it couldn't do before?*

Each lesson adds one new **sense or ability** to the board the student is
holding.  By the final lesson, the device:

- **Displays** any color the student chooses (Lessons 1–2)
- **Reacts** to the light and sound around it (Lessons 3–4)
- **Speaks** — produces tones and simple melodies (Lesson 5)
- **Feels touch** — responds to finger contact on its pads (Lesson 6)
- **Does all of the above together** in a student-designed creation (Lessons 7–8)

The thread is physical, not textual.  The "artifact that grows" is the
behavior of the board, not a file.  Each lesson's starter code is intentionally
self-contained (not cumulative) so that a student who missed a lesson is not
blocked — but the *capabilities* learned are all available for the capstone.

---

## Concept Progression Table

| # | Title | New CS Concept | Circuit Playground Feature | Device Gains |
|---|-------|---------------|---------------------------|-------------|
| 1 | Hello, Pixels! | `setup()` / `loop()`, a single function call, uploading code | `setPixelColor(n, r, g, b)` | Lights up — one LED |
| 2 | Painting with Light | Variables, RGB color model, `for` loops | Multiple pixels, `setBrightness()`, `clearPixels()` | Shows any color, all pixels at once |
| 3 | Sensing Light | Reading a sensor, `map()`, `if` / `else` | `lightSensor()` | Changes color based on brightness |
| 4 | More Senses | Multiple inputs, Serial Monitor for debugging, combining conditions | `soundSensor()`, `temperature()`, `motionX/Y/Z()` | Reacts to sound, heat, and tilt |
| 5 | Give It a Voice | Output beyond light: tone, frequency, duration | `playTone(freq, duration)` | Makes sounds and simple melodies |
| 6 | Play a Song | Named constants (`#define`), music as data, sequential execution | `playTone()` called in sequence with defined note/duration constants | Plays a recognizable song |
| 7 | Touch Magic | A new input modality; comparing input to trigger output | `readCap(pad)` on pins 0, 1, 2, 3, 6, 9, 10, 12 | Responds to finger touch |
| 8 | Finding Your Project | Design thinking; translating ideas into "when…then…" behaviors; choosing an archetype | All prior features (review) | A committed project brief |
| 9 | Build Your Project | Scaffolded independent build; using an AI assistant for syntax help | Archetype scaffold of student's choice | Student's finished, demo-ready device |

### Bonus Lessons (self-contained, insertable after Lesson 3)

| # | Title | New Concept | Feature |
|---|-------|-------------|---------|
| B-A | Button Logic | Digital input, `while` loops | `leftButton()`, `rightButton()` |
| B-B | Scrolling Animations | Timing with `delay()`, pixel patterns, arrays | Pixel ring patterns |

---

## Guardrails

These are explicit constraints on what this lesson series will NOT do,
regardless of how tempting.

1. **Do not expose pin numbers or hardware registers.**
   All hardware access goes through `CircuitPlayground.*`.  Students never
   call `analogRead()`, `digitalRead()`, or `pinMode()` directly.

2. **Do not introduce `int`, `float`, and `bool` as a unit.**
   Introduce each type exactly once, when a concrete situation demands it.
   Type names are vocabulary, not a prerequisite lecture.

3. **Do not use hex color notation before students are comfortable with RGB.**
   `0xFF0000` is introduced only as a "shorthand you might see" *after*
   students already understand `(255, 0, 0)`.

4. **Do not require Serial Monitor before Lesson 4.**
   The Serial Monitor is introduced as a debugging tool when students first
   need to see a sensor value they can't otherwise observe.  It is a means, not an end.

5. **Do not stack more than one new concept per lesson.**
   If a lesson seems to need two new ideas, find a way to split it or to
   present one idea as a "tool" and the other as the "concept."

6. **Do not use domain jargon until students have experienced the concept.**
   "This is called a variable" comes *after* students have written one and
   changed it to see what happens.

7. **Do not let the final project be fully open-ended.**
   Lesson 8 leads students through a structured ideation process that ends with a
   written project brief before any code is written.  Lesson 9 provides archetype
   scaffolds (five starting-point designs) so students choose a structure, not a
   blank page.  Open choice within a scaffold prevents paralysis and produces better work.

8. **AI assistants are a syntax tool, not a design tool.**
   Students learn all concepts through Lessons 1–7.  In Lesson 9, AI tools
   (MagicSchool, Flint) are explicitly introduced as a way to get unstuck on
   syntax details the student already understands conceptually.  The framing is:
   "You design. The AI writes syntax."  Students are taught to prompt with context
   and to evaluate — not just paste — the answer they receive.

8. **Do not introduce `class` or object-oriented patterns.**
   The `CircuitPlayground` object is used as a black box.  Students do not
   define their own classes in this series.

---

## RGB Color Model — Core Concepts to Cover in Lesson 2

These are the specific ideas about RGB that Lesson 2 must convey, because
they surface as misconceptions in every subsequent lesson:

- Each channel (R, G, B) runs from **0 (off) to 255 (full brightness)**.
- All three at 255 produces **white**, not "maximum of each color."
- All three at 0 produces **off** (not black — the LED is simply dark).
- NeoPixels mix light, not paint: R+G = yellow, G+B = cyan, R+B = magenta.
- **Limitation:** The 256-step resolution means some subtle color differences
  are impossible to represent.  (Motivates the concept of "precision" in data.)
- **Limitation:** Very high brightness drains battery quickly.  `setBrightness()`
  controls this.

---

## Song Transcription — Core Concepts to Cover in Lesson 6

Lesson 6 introduces `#define` as the mechanism for naming musical notes and
durations.  These are the specific ideas that must land:

**Why `#define` instead of variables?**
`#define` is a preprocessor directive: the compiler replaces every occurrence
of the name with its value *before* compiling, so there is no variable, no
memory slot, no type.  For this lesson, that distinction is background detail —
the teaching point is simply: *give numbers meaningful names so the code reads
like music, not like math.*

```cpp
// Note frequencies (Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// Duration constants (milliseconds)
#define WHOLE    1000
#define HALF      500
#define QUARTER   250
#define EIGHTH    125
```

**Pedagogical arc within the lesson:**
1. Students first hard-code a call: `CircuitPlayground.playTone(440, 500)` — works, but what is 440?
2. Teacher introduces `#define NOTE_A4 440` — now the call reads `playTone(NOTE_A4, HALF)`.
3. Students transcribe a short, familiar song using only `playTone()` calls in sequence.
   Suggested songs: *Hot Cross Buns*, *Mary Had a Little Lamb*, *Ode to Joy* (first phrase).
4. Extension: add `delay(50)` between notes as a "breath" to separate repeated notes.

**Key misconception to address:** Students often expect `#define` to behave
like a variable that can be changed at runtime.  Clarify: the name is a
*label the compiler uses*, not a box the program can update.

**Connection to Lesson 5:** Lesson 5 introduced `playTone()` with literal numbers.
Lesson 6 does not introduce any new *function* — the only new idea is that we
can name numbers.  Keep this distinction clear in teacher framing.

---

## Library Quick Reference

*Student-facing cheat sheet — plain-language descriptions.*

```
CircuitPlayground.begin()               Must be called once in setup(). Starts everything.

--- Light ---
CircuitPlayground.setPixelColor(n, r, g, b)   Turn pixel n (0–9) to color (r, g, b).
CircuitPlayground.clearPixels()               Turn all pixels off.
CircuitPlayground.setBrightness(n)            Set overall brightness 0–255. Use 20–50 for classroom.

--- Sensors ---
CircuitPlayground.lightSensor()         Returns 0–1023: how bright the room is.
CircuitPlayground.soundSensor()         Returns 0–1023: how loud the room is.
CircuitPlayground.temperature()         Returns temperature in °C.
CircuitPlayground.motionX()             Returns tilt left/right in m/s².
CircuitPlayground.motionY()             Returns tilt forward/back in m/s².
CircuitPlayground.motionZ()             Returns up/down acceleration in m/s².

--- Sound ---
CircuitPlayground.playTone(freq, ms)    Play a tone at frequency (Hz) for duration (ms).
                                        Middle C = 262, A4 = 440.  ms = milliseconds.

--- Input ---
CircuitPlayground.leftButton()          Returns true if left button is pressed.
CircuitPlayground.rightButton()         Returns true if right button is pressed.
CircuitPlayground.readCap(pad)          Returns 0–1000+ for capacitive touch.
                                        Valid pins: 0, 1, 2, 3, 6, 9, 10, 12.
                                        > ~50 usually means a finger is touching it.
                                        NOTE: despite common documentation, these are
                                        digital pin numbers, NOT analog pin labels.

--- Utility ---
map(value, fromLow, fromHigh, toLow, toHigh)
    Rescales value from one range to another.
    Example: map(lightSensor(), 0, 1023, 0, 255)
delay(ms)                               Pause the program for ms milliseconds.
Serial.begin(9600)                      Start Serial Monitor (put in setup()).
Serial.println(value)                   Print a value to Serial Monitor.
```

---

## Key Decisions Log

*Record of non-obvious choices and the reasoning behind them.*

| Decision | Reasoning |
|----------|-----------|
| Output First entry | Physical output (a glowing LED in-hand) is more motivating than any screen result for this age group and context. |
| Self-contained lessons (not cumulative starters) | Students miss class. A missed lesson should not block participation going forward. |
| Sensors before sound | Sensors introduce the concept of *reading* a value, which makes `readCap()` in the touch lesson feel familiar rather than new. Sound is output-only and is more fun as a reward after students have mastered input. |
| Two sound lessons (5 and 6) | Lesson 5 establishes `playTone()` with raw numbers. Lesson 6 introduces `#define` to name those numbers — the concept of *named constants* — by having students transcribe a real song. Splitting them ensures `#define` is motivated by felt pain ("440 means nothing to me") rather than presented abstractly. |
| Lessons 8–9 split between ideation and building | Lesson 8 is entirely design work (no Arduino IDE). Students who skip ideation produce unfocused code and get stuck. Committing to a project brief before writing any code consistently produces better outcomes and faster builds. |
| AI assistants introduced in Lesson 9, not earlier | Introducing AI tools before students have built their own mental model risks them becoming dependent on generated code they don't understand. By Lesson 9, students have written enough code to read and evaluate an AI's suggestion critically. |
| Capacitive touch last (before capstone) | Touch is the most surprising and "magical" input modality — saving it builds anticipation and makes it a strong motivator for the capstone. |
| No hex colors in early lessons | Hex notation introduces a second representation of the same concept. Students who are new to base-10 numeric ranges (0–255) don't need the added cognitive load of base-16. |
| `map()` introduced with light sensor | `map()` is a function students will use constantly, and the light sensor provides a natural, concrete motivation: "the sensor gives 0–1023 but I want 0–255 for a color channel." |
