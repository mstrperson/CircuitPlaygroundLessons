# Lesson 5 — Give It a Voice

## Learning Goals
- Students will be able to call `playTone()` to produce a sound at a specific frequency and duration.
- Students will be able to explain what frequency means in terms of what they hear.
- Students will be able to sequence multiple `playTone()` calls to produce a short pattern.

## New Vocabulary
- **frequency** — how fast a sound wave vibrates, measured in Hertz (Hz). Higher frequency = higher pitch. Middle C on a piano is 262 Hz. 
- **duration** — how long a sound plays, measured in milliseconds (ms). 1000 ms = 1 second.
- **`playTone(frequency, duration)`** — tells the Circuit Playground's speaker to play a tone at the given pitch for the given number of milliseconds.

## Warm-Up (~5 min)

Ask:
> *"What makes a flute sound higher than a tuba? What's physically different about the sound waves?"*

After a few answers, ask:
> *"If the board can play any frequency from 1 to 20,000 Hz, what do you predict happens at 20,000? At 50? At 440?"*

(440 Hz is A above middle C — the note orchestras tune to. Students may recognize it if you play it.)

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Start with a minimal sketch (just CircuitPlayground.begin() in setup).
2. In setup(), type:
     CircuitPlayground.playTone(440, 500);
   Upload. The board plays a tone. "That's A4 — 440 vibrations per second, for half a second."
3. Change 440 to 880. Upload. "Twice the frequency — one octave higher. Same note, higher register."
4. Change 440 to 220. Upload. "Half the frequency — one octave lower."
5. Ask: "What if I put playTone in loop() instead of setup()?"
   Move it to loop(). Upload. Continuous tone — annoying but instructive.
6. Add delay(500) after the playTone in loop(). Now it pulses.
7. Add a second note:
     CircuitPlayground.playTone(523, 500);  // C5
     delay(500);
   Two-note alternating pattern.
8. Point out: playTone BLOCKS. The board does nothing else while a tone is playing.

KEY CONCEPTS:
- playTone is blocking — the program waits for the tone to finish before moving on.
  This is different from sensors, which just return a number instantly.
- Frequency is pitch. Duration is length. Both are numbers the student chooses.
- Silence between notes: a small delay() after each playTone creates separation.
  Without it, consecutive same-pitch notes blur together.
- Putting playTone in loop() plays it continuously (with the duration as a pause between repeats).
  Putting it in setup() plays it once at power-on.

WHERE TO PUT TONES:
- In setup(): plays once at power-on. Good for a startup "jingle."
- In loop(): plays repeatedly. Good for an alarm or continuous reaction.
- Inside an if statement: plays when a condition is met. Good for events.

COMMON MISCONCEPTIONS:
- Students try to play two tones simultaneously. The board has one speaker;
  it can only play one frequency at a time.
- Students expect playTone to be instant (like setPixelColor). It isn't.
  While a 500ms tone plays, no other code runs.
-->

The Circuit Playground has a small speaker. You control it with:

```cpp
CircuitPlayground.playTone(frequency, duration);
```

- **`frequency`** — the pitch in Hz. Try these references:

| Note | Frequency |
|------|-----------|
| C4 (middle C) | 262 Hz |
| E4 | 330 Hz |
| G4 | 392 Hz |
| A4 (concert A) | 440 Hz |
| C5 | 523 Hz |

- **`duration`** — how long in milliseconds. 1000 ms = 1 second.

`playTone()` is **blocking**: the board does nothing else while the sound plays.
Use a small `delay(50)` between notes to create silence that separates them — especially important when the same note plays twice in a row.

```cpp
CircuitPlayground.playTone(440, 500);   // A4, half a second
delay(50);                               // brief silence
CircuitPlayground.playTone(523, 500);   // C5, half a second
delay(50);
```

## Guided Activity (~20 min)

**Step 1 — Upload the starter code**
Upload the starter code. The board plays two tones in sequence, then repeats.

**Step 2 — Change the pitch**
Change `440` to `880`. What happens? Change it to `220`. What happens? 
Try `100`. Try `4000`. Where does the pitch become hard to hear?

**Step 3 — Change the duration**
Change `500` to `1000` for the first note. Change it to `100`. How does the feel change?

**Step 4 — Add a third note**
Add a third `playTone()` and `delay()` pair. Pick any frequency you like.

**Step 5 — Move one tone inside an if statement**
Add a sound sensor check — if the room is loud, play a high note. Otherwise, play a low one.
```cpp
if (CircuitPlayground.soundSensor() > 600) {
  CircuitPlayground.playTone(880, 200);
} else {
  CircuitPlayground.playTone(220, 200);
}
```

**Step 6 — Add lights**
Call `setPixelColor` *before* each `playTone` so the ring color changes with each note.

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  CircuitPlayground.playTone(440, 500);   // A4 — change me!
  delay(50);
  CircuitPlayground.playTone(523, 500);   // C5 — change me!
  delay(50);
}
```

## Make It Yours (~remaining time)

- **Find a three-note pattern you like** — experiment with frequencies until you have a short sequence that sounds intentional. Write down the numbers.
- **Link sound to color** — every time a tone plays, change the pixel color to match the mood of that note. High notes: bright colors. Low notes: dark or cool colors.
- **Make it sensor-triggered** — instead of looping forever, only play when the left button is pressed (`CircuitPlayground.leftButton()` returns `true` while held).
- **Challenge:** Create a rising pattern — five notes, each one 50 Hz higher than the last. Use a `for` loop where the loop variable changes the frequency. (Hint: `playTone(200 + i * 50, 200)`)

## Wrap-Up (~5 min)

<!-- Exit ticket: "What is frequency? What is duration? Give one example of each using actual numbers."
     Listen for students who describe frequency as "speed" of the wave vs. "how high the sound is"
     — both framings are acceptable, but "vibrations per second" is most precise. -->

What is frequency? What is duration? Give a concrete example using actual numbers from today.

## Teacher Notes

<!--
VOLUME:
- The Circuit Playground speaker is small and not very loud. In a quiet classroom it's
  audible; in a noisy one, students may need to hold the board close to their ear.
- setBrightness() has no effect on speaker volume. Volume is fixed.

BLOCKING BEHAVIOR:
- This is the most surprising behavior of this lesson. Students often expect the board
  to keep checking sensors while a tone plays. Demo the problem by putting a very long
  tone (playTone(440, 5000)) in an if statement — the board is frozen for 5 seconds.
- Workaround (not taught in this lesson): CircuitPlayground.playTone(440, 0) plays
  a tone that starts immediately and runs until the next playTone(0, 0) call.
  This non-blocking approach is too advanced for this lesson but worth knowing.

FREQUENCY RANGES:
- Human hearing: roughly 20 Hz – 20,000 Hz. Very low and very high tones
  may be inaudible, especially through a small speaker.
- The speaker bottoms out around 200 Hz and becomes a click/buzz below that.
- Frequencies above 8000 Hz become shrill. Most musical use is 200–4000 Hz.

STEP 6 (LIGHTS + SOUND):
- This step is important: it establishes that playTone() and setPixelColor() can coexist.
  Students sometimes assume the board can only do one thing at a time. setPixelColor()
  returns instantly, so the light change happens and THEN the tone plays (sequentially,
  but fast enough to feel simultaneous).

PACING:
- If the class gets stuck on Step 5, skip it — the sensor combination is a preview
  of Lesson 8 and doesn't need to land fully today. The core lesson is frequency + duration.
-->
