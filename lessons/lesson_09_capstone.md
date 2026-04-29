# Lesson 9 — Capstone: Your Device

## Learning Goals
- Students will be able to design a program that combines at least two sensors and two output types.
- Students will be able to explain the design choices they made and why.
- Students will be able to demonstrate their working device to the class and describe what it does.

## New Vocabulary

No new vocabulary this lesson. All terms come from previous lessons.

## Warm-Up (~5 min)

Ask students to take out their Lesson 8 "when…then…" statements (or think back to them):

> *"If you could keep one behavior from yesterday and add one brand-new one, what would they be?"*

Then share the design brief:

> *"Today you're the designer. Your job is to build a device that does something real — something you can demo, explain, and be proud of. You have the whole period."*

## The Design Brief

Your Circuit Playground device must meet **at least three** of the following constraints — your choice:

- [ ] Reacts to at least **two different sensors** (any combination of light, sound, temperature, motion, touch, or buttons)
- [ ] Uses **both light and sound** as output
- [ ] Has a clear **"resting state"** (what it looks like/sounds like when nothing is happening) and an **"activated state"** (what changes when a condition is triggered)
- [ ] Uses **at least one touch pad** as an input
- [ ] Has a behavior that **responds proportionally** — the output scales with the sensor reading (e.g., louder sound → more pixels lit)
- [ ] **Plays a recognizable melody** at some point (even if triggered by a condition)
- [ ] Could be **useful or meaningful** to someone — it solves a small problem, expresses something, or tells you something about the environment

Write down which three (or more) constraints you're targeting **before you write any code.**

## Design Process

**Step 1 — Define your device in one sentence**

> *"My Circuit Playground is a ____________ that ____________ when ____________."*

Example: *"My Circuit Playground is a study timer that plays a song when I clap twice."*

**Step 2 — Write your behaviors in English**

List every "when … then …" statement your device will have. Aim for at least three behaviors.

**Step 3 — Plan your sensors and outputs**

| Behavior | Sensor / Input | Output |
|----------|---------------|--------|
| 1 | | |
| 2 | | |
| 3 | | |

**Step 4 — Build one behavior, test it**

Start with the behavior you're most confident about. Get it working before touching anything else.

**Step 5 — Add the next behavior**

Test after each addition. If something breaks, comment out the newest piece.

**Step 6 — Polish**

Does the resting state look intentional? Are your thresholds tuned? Does the timing feel right?

**Step 7 — Prepare your demo**

You'll share your device with at least one other student or the whole class. Be ready to explain:
1. What it does
2. Which sensors / inputs it uses
3. One decision you made during design and why

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

// ── Note constants (available if you need them) ───────────────────
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

#define WHOLE    1000
#define HALF      500
#define QUARTER   250
#define EIGHTH    125

// ── Your design choices ───────────────────────────────────────────
// Add any #define or variable declarations you need here.

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);

  // Add any startup behavior here (a startup jingle, an initial light state, etc.)
}

void loop() {
  // Read your sensors here:
  //   CircuitPlayground.lightSensor()          returns 0–1023
  //   CircuitPlayground.soundSensor()          returns 0–1023
  //   CircuitPlayground.temperature()          returns °C (use float)
  //   CircuitPlayground.motionX() / Y() / Z()  returns m/s² (use float)
  //   CircuitPlayground.readCap(pin)           pins: 0,1,2,3,6,9,10,12
  //   CircuitPlayground.leftButton()           returns true/false
  //   CircuitPlayground.rightButton()          returns true/false

  // Write your behaviors here using if / else if / else

  // Output tools:
  //   CircuitPlayground.setPixelColor(n, r, g, b)
  //   CircuitPlayground.clearPixels()
  //   CircuitPlayground.playTone(frequency, duration_ms)
  //   map(value, fromLow, fromHigh, toLow, toHigh)
}
```

## Sharing Protocol

When the class shares out, the presenter should cover:

1. **Name your device.** (*"This is the ____"*)
2. **Demo the resting state.** (*"When nothing is happening, it looks like this."*)
3. **Trigger at least two behaviors.** (*"Watch what happens when I ____."*)
4. **Explain one decision.** (*"I chose to use the sound sensor instead of light because ____."*)

Audience: after each demo, offer one observation and one question.

## Teacher Notes

<!--
STRUCTURE OF THE PERIOD:
Recommended timing for a 50-minute class:
  0–5 min:   Warm-up and brief
  5–10 min:  Students complete Steps 1–3 on paper (enforce this — it pays off)
  10–35 min: Build and test (circulate constantly)
  35–45 min: Polish and prepare demo
  45–50 min: Share-out (pick 3–4 students, or pairs share with pairs)

ENFORCING THE PLANNING PHASE:
- Students who skip Steps 1–3 and start coding immediately usually produce unfocused
  work and get stuck. Ask every student to show you their behavior list before they
  open the Arduino IDE.

CONSTRAINT MENU PHILOSOPHY:
- The menu of constraints is deliberately broad and achievable. Every student should
  be able to hit three. The constraints are designed to ensure the project uses what
  was taught without prescribing a specific outcome.
- If a student wants to do something not on the list, that's fine — ask them to
  articulate it as a "when…then…" statement and check that it uses at least two sensors.

COMMON STRUGGLES:
- "I don't know what to make." → Ask: what problem do you have in your life that a
  sensor could detect? What's something you want to show people?
- "My code is too long." → Ask: pick the TWO behaviors you care most about. Delete the rest.
- "It doesn't work." → Ask: which behavior isn't working? Comment everything else out
  and test just that one thing.

SHARING OUT:
- Having pairs share with pairs is lower-stakes and faster than whole-class demos.
  For a class that's been building together all unit, whole-class is more satisfying.
- Video recording the demos (even just phone video) gives students a shareable artifact
  and provides you documentation for assessment.

ASSESSMENT IDEAS:
- The "explain one decision" requirement is the best formative signal.
  Students who can articulate a design choice demonstrate genuine understanding.
- Consider a simple 1-page reflection: "What does your device do? What would you change
  if you had another class period?"

EXTENSION:
- Students who finish early: add a startup animation or jingle, tune every threshold,
  or add a feature that requires a concept from outside the unit (e.g., using a counter
  variable to track how many times a pad has been touched).
-->
