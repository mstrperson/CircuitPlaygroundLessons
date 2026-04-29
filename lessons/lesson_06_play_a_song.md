# Lesson 6 — Play a Song

## Learning Goals
- Students will be able to use `#define` to give meaningful names to number constants.
- Students will be able to transcribe a simple melody using named note and duration constants.
- Students will be able to explain why naming numbers makes code easier to read and change.

## New Vocabulary
- **`#define`** — a directive that tells the compiler to replace a name with a number everywhere it appears. `#define NOTE_A4 440` means: every time the code says `NOTE_A4`, use `440` instead.
- **constant** — a value that is named but never changes while the program runs. Different from a variable: you set it once at the top and the program uses it as-is.
- **transcribe** — to write down music in a form a computer can read — in this case, as a sequence of `playTone()` calls.

## Warm-Up (~5 min)

Write this on the board:
```
262, 294, 330, 262, 262, 294, 330, 262, 330, 349, 392, 330, 349, 392
```
Ask: *"Can anyone tell what this is?"*  (It's the start of *Mary Had a Little Lamb*, but nobody will know from numbers.)

Then write:
```
C4, D4, E4, C4, C4, D4, E4, C4, E4, F4, G4, E4, F4, G4
```
Ask: *"How about now?"* (Likely some students recognize it.)

This is the problem `#define` solves.

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Start with a working playTone sketch from Lesson 5.
2. Show the raw-number version of Mary Had a Little Lamb (just the first phrase):
     CircuitPlayground.playTone(330, 250);  // E4
     CircuitPlayground.playTone(294, 250);  // D4
     CircuitPlayground.playTone(262, 250);  // C4
     ...
   Ask: "What's wrong with this code?" (The numbers are meaningless; you'd have to
   look up every frequency to know what note is playing.)
3. Introduce #define at the top of the file:
     #define NOTE_E4  330
     #define NOTE_D4  294
     #define NOTE_C4  262
     #define QUARTER  250
4. Rewrite the same three lines:
     CircuitPlayground.playTone(NOTE_E4, QUARTER);
     CircuitPlayground.playTone(NOTE_D4, QUARTER);
     CircuitPlayground.playTone(NOTE_C4, QUARTER);
   "Now the code reads almost like sheet music."
5. Key point: #define is NOT a variable. You can't write NOTE_E4 = 400 later.
   The compiler replaces the name with the number before the program even runs.
6. Show what delay(50) between notes does — play the opening with and without it.
   Repeated notes blur without it.

EXPLAINING #define VS. VARIABLES:
- Variables are boxes: the program can put different values in them at different times.
- #define names are labels the compiler pastes in before running: the program never
  sees the name, only the number. This is why you can't change them at runtime.
- For 6th graders: "It's like find-and-replace before the code runs."

NOTE SHEET:
- Hand out or project the note-frequency table from the Guiding Principles quick reference.
- Students will be staring at it for most of the lesson.

COMMON MISCONCEPTIONS:
- Students try to put a semicolon after #define. There is none: #define NOTE_A4 440
  (no semicolon, no equals sign). The compiler will error or silently malfunction with one.
- Students try to change a #define'd name in the code: NOTE_A4 = 500; — this is a compile error.
  Redirect: if they want it to be changeable, they need a variable instead.
-->

In Lesson 5 we called `playTone()` with raw numbers like `440` and `500`. Those numbers work — but nobody reading the code knows what note `440` is.

**`#define`** solves this by letting you give every number a name:

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

// Note durations (milliseconds)
#define WHOLE    1000
#define HALF      500
#define QUARTER   250
#define EIGHTH    125
```

`#define` is not a variable. It's a **find-and-replace** the compiler performs before your program runs. Every time it sees `NOTE_E4` in your code, it substitutes `330`. You cannot assign a new value to it later — if you need something that changes, use a variable.

With these definitions, your code reads almost like sheet music:
```cpp
CircuitPlayground.playTone(NOTE_E4, QUARTER);  delay(50);
CircuitPlayground.playTone(NOTE_D4, QUARTER);  delay(50);
CircuitPlayground.playTone(NOTE_C4, QUARTER);  delay(50);
```

The `delay(50)` between notes creates a brief silence. Without it, two consecutive notes at the same pitch blur into one long tone.

**Mary Had a Little Lamb — first phrase:**

| Note | Duration | Note | Duration |
|------|----------|------|----------|
| E4 | quarter | E4 | quarter |
| D4 | quarter | E4 | quarter |
| C4 | quarter | E4 | half |
| D4 | quarter | | |

## Guided Activity (~20 min)

**Step 1 — Upload the starter code**
Upload the starter code. It plays the first phrase of *Mary Had a Little Lamb* once and then stops.

**Step 2 — Follow along**
As it plays, follow the `playTone` calls in the code. Match each call to the note name. Can you hear each note?

**Step 3 — Finish the song**
The starter code stops halfway through. Continue transcribing. The second phrase:

| Note | Duration |
|------|----------|
| D4 | quarter |
| D4 | quarter |
| D4 | half |
| E4 | quarter |
| G4 | quarter |
| G4 | half |

**Step 4 — Add the third and fourth phrases**
```
Third:  E4 D4 C4 D4 E4 E4 E4 E4
Fourth: D4 D4 E4 D4 C4 (whole note)
```
(All quarter notes unless noted otherwise.)

**Step 5 — Loop it**
Move all your `playTone` calls to `loop()` and add a `delay(1000)` at the very end before the next repetition. Now it plays repeatedly.

**Step 6 — Light it up**
Before each phrase begins, change the pixel colors. Use a different color for each phrase.

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

// ── Note frequencies (Hz) ────────────────────────────────────────
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// ── Note durations (ms) ──────────────────────────────────────────
#define WHOLE    1000
#define HALF      500
#define QUARTER   250
#define EIGHTH    125

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);

  // Mary Had a Little Lamb — first phrase
  CircuitPlayground.playTone(NOTE_E4, QUARTER);  delay(50);
  CircuitPlayground.playTone(NOTE_D4, QUARTER);  delay(50);
  CircuitPlayground.playTone(NOTE_C4, QUARTER);  delay(50);
  CircuitPlayground.playTone(NOTE_D4, QUARTER);  delay(50);
  CircuitPlayground.playTone(NOTE_E4, QUARTER);  delay(50);
  CircuitPlayground.playTone(NOTE_E4, QUARTER);  delay(50);
  CircuitPlayground.playTone(NOTE_E4, HALF);     delay(50);

  // YOUR SONG CONTINUES HERE
}

void loop() {
  // song plays once in setup — move it here if you want it to repeat
}
```

## Make It Yours (~remaining time)

- **Transcribe a different song** — pick any simple melody you know and transcribe its first phrase. Good options: *Hot Cross Buns*, *Ode to Joy*, *Happy Birthday*, *Twinkle Twinkle*. Use the note table for reference.
- **Add your signature color** — change the ring color at the start and end of your song using the RGB values you found in Lesson 2.
- **Define your own constants** — what if you want a dotted quarter note (= 375 ms)? Add your own `#define DOTTED_QUARTER 375` and use it.
- **Challenge:** Transcribe a song that uses octaves — you'll need notes from both C4 and C5. Use `NOTE_C4` and `NOTE_C5` in the same piece and listen to the jump.

## Wrap-Up (~5 min)

<!-- Exit ticket: "In your own words: what is the difference between #define and a variable?"
     Target answer: a #define name is replaced by the compiler before the program runs
     and can't be changed; a variable is a box the program can update while running.
     Don't expect 6th graders to use those exact words — look for the idea that
     #define is "baked in" and variables are "changeable." -->

In your own words: what is the difference between `#define` and a variable?

## Teacher Notes

<!--
SONG SELECTION:
- Mary Had a Little Lamb uses only C4, D4, E4, G4 — just five distinct notes.
  It's ideal for a first transcription.
- Hot Cross Buns uses E4, D4, C4 — even simpler (3 notes), good for struggling students.
- Ode to Joy uses E4, F4, G4, A4, B4 — introduces more of the scale but is still beginner-friendly.
- Happy Birthday: warn students it has sharps (#) and accidentals that their define set
  doesn't cover. Save it for the challenge or add defines for sharp notes.

#define SYNTAX:
- No semicolon. No equals sign. Just: #define NAME value
- This is the most common syntax error. Walk around and check define statements early.
- If a student gets a compile error on a #define line, the first thing to check is
  a stray semicolon at the end.

SETUP VS. LOOP DECISION:
- Songs in setup() play once, which is often what students expect.
- Moving to loop() plays it repeatedly — fun but can become grating quickly in a classroom.
- If students are looping songs all at once, consider asking everyone to keep it in setup()
  until "Make It Yours" time.

DELAY(50) BETWEEN NOTES:
- This is critical for repeated consecutive notes. Without it:
  E4(quarter) E4(quarter) sounds like E4(half).
  With it: two distinct notes are audible.
- Students who skip the delay will hear their song "wrong" and think they made a mistake.
  Have them add the delays and re-upload first before assuming a transcription error.

PACING:
- Getting through Steps 1–4 (complete Mary Had a Little Lamb) is the target for most students.
  Steps 5–6 and Make It Yours are for fast finishers.
- If only a few students finish their own song transcription, share one out and have the class
  read through the code together to identify what song it is before playing it.
-->
