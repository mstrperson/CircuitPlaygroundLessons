# Lesson 8 — Putting It Together

## Learning Goals
- Students will be able to combine multiple sensor inputs and output behaviors in a single program.
- Students will be able to describe their program's behavior using "when … then …" statements.
- Students will be able to debug a multi-feature program by isolating one feature at a time.

## New Vocabulary
- **behavior** — a specific thing the device does in response to a specific condition. "When it's dark, the ring turns red" is a behavior.
- **`else if`** — a way to chain multiple conditions together so the board checks them in order and runs only the first matching one.
- **debug** — to find and fix a part of a program that isn't working as intended. Isolating one feature at a time is a core debugging strategy.

## Warm-Up (~5 min)

Ask students to describe one device in real life that uses multiple sensors at once:

> *"Your phone uses its microphone, camera, and GPS at the same time. How does it decide which one to pay attention to?"*

Then show the Circuit Playground and ask:
> *"We've taught this board to see light, hear sound, feel temperature, feel motion, and feel touch. Today we're going to give it a job where it uses several of those at once. What do you want it to do?"*

Take two or three ideas. Use them to frame the guided activity.

## Direct Instruction (~10 min)

<!--
PROJECTOR DEMO:
1. Start with a blank sketch. Build it up live, one feature at a time.
2. First: read the light sensor and set pixel color.
3. Second: add a sound check — if loud, play a tone.
4. Third: add a touch check on pin 2 — if touched, change color.
5. At each step, upload and verify that feature works before adding the next.
   Say explicitly: "I'm adding one thing, testing it, then adding the next.
   That's how you debug: one piece at a time."
6. Introduce else if:
     if (condition1) {
       // ...
     } else if (condition2) {
       // ...
     } else {
       // ...
     }
   "Only one branch runs. The board checks in order — first condition wins."

KEY CONCEPTS:
- Building incrementally: add one feature, test, add next. Never add two things at once.
- else if priority: conditions are checked top to bottom. The first match wins.
  This means ORDER MATTERS — think about which behavior should have priority.
- There is no magic to combining features: each sensor read is just another variable,
  each output call is just another function call. The structure is the same as always.

DEBUGGING STRATEGY:
- If something doesn't work, comment out everything EXCEPT the one feature you're checking.
- Add Serial.println() to see what value each sensor is actually reporting.
- Fix one thing, then uncomment the next feature.

COMMON MISCONCEPTIONS:
- Students think combining features requires learning something new.
  Emphasize: you know everything you need. This lesson is about assembling it.
- Students put conditions inside each other (nested if) when else if is cleaner.
  Both work; steer toward else if for readability.
- Students forget that playTone() blocks. If they have a 1000ms tone inside a condition
  that checks frequently, the board seems "unresponsive" to other sensors while playing.
  Short durations (100–200ms) keep the board feeling live.
-->

You now know how to use all of the Circuit Playground's senses and outputs. This lesson is about combining them.

**The structure stays the same** — `loop()` reads sensors, checks conditions, and produces output. You're just doing more of it:

```cpp
void loop() {
  // read all the sensors you need
  int light = CircuitPlayground.lightSensor();
  int sound = CircuitPlayground.soundSensor();
  int touch = CircuitPlayground.readCap(2);

  // behavior 1: light controls ring color
  int brightness = map(light, 0, 1023, 0, 255);
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, brightness, 0, 0);
  }

  // behavior 2: loud sound triggers a tone
  if (sound > 600) {
    CircuitPlayground.playTone(880, 100);
  }

  // behavior 3: touch overrides everything with blue
  if (touch > 50) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 0, 255);
    }
  }
}
```

**`else if`** lets you create exclusive choices — only the first matching condition runs:

```cpp
if (light < 200) {
  // very dark
} else if (light < 600) {
  // medium
} else {
  // bright
}
```

**Debugging rule:** When something doesn't work, comment out everything except the one feature you're testing. Fix that. Then uncomment the next piece.

## Guided Activity (~20 min)

**Step 1 — Upload the starter code**
Upload. Verify that the ring reacts to light (cover the board), sound (clap near it), and touch (pin 2 pad). All three should work.

**Step 2 — Write your behaviors in English first**
On paper, write out three "when … then …" statements describing what you want your board to do. Example:
- *When it's dark, the ring is purple.*
- *When it's tilted sideways, it plays a low tone.*
- *When I touch pad A3, it flashes all white.*

**Step 3 — Implement one behavior at a time**
Starting from the starter code, modify the first behavior. Upload and test it alone before touching anything else.

**Step 4 — Add the second and third behaviors**
Add each one and test after each addition. If something breaks, comment out the newest addition and check what changed.

**Step 5 — Resolve priority**
If two conditions could be true at the same time (e.g., it's dark AND you're touching the pad), which should "win"? Use `else if` or reorder your conditions to reflect your intended priority.

## Starter Code

```cpp
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {
  int light = CircuitPlayground.lightSensor();
  int sound = CircuitPlayground.soundSensor();
  int touch = CircuitPlayground.readCap(2);

  // behavior 1: light controls ring brightness (red)
  int brightness = map(light, 0, 1023, 0, 255);
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, brightness, 0, 0);
  }

  // behavior 2: loud sound triggers a tone
  if (sound > 600) {
    CircuitPlayground.playTone(880, 100);
  }

  // behavior 3: touch turns ring blue
  if (touch > 50) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 0, 255);
    }
  }
}
```

## Make It Yours (~remaining time)

- **Replace any behavior** — swap the light sensor for temperature, or the tone for a pixel flash. Every behavior is just a sensor + condition + output.
- **Add a fourth behavior** — use a sensor you haven't used yet in this sketch (try `motionY()` or a second touch pad).
- **Make the behaviors exclusive** — convert all your `if` statements to a single `if` / `else if` / `else` chain. Which condition gets priority? Does that match what you want?
- **Challenge:** Build a "mood ring" that uses three sensors to set three independent color channels:
  - Light sensor → red channel
  - Sound sensor → green channel  
  - Temperature → blue channel  
  All three update continuously and combine to produce an ever-changing color.

## Wrap-Up (~5 min)

<!-- Exit ticket: "What debugging strategy did you use when something wasn't working?
     Describe in one sentence what you tried."
     Listen for: comment out / isolate / print the value / upload after one change.
     These are real software engineering practices worth naming explicitly. -->

Describe one moment during today's work where something didn't do what you expected. What did you try to fix it?

## Teacher Notes

<!--
PACING:
- This lesson is intentionally process-focused, not content-focused.
  Students are not learning a new API call — they are learning how to compose.
- If the class races through Steps 1–3, encourage them to go deeper on Step 4
  (priority and else if) rather than adding more features.
- Step 2 (write behaviors in English first) is easy to skip but worth enforcing.
  Students who write it down before coding produce more intentional work and debug faster.

BLOCKING TONES IN COMBINED SKETCHES:
- Students who use long tones (500ms+) will notice the board feels "sluggish" —
  sensors aren't read while the tone plays. Recommend: keep tones to 100–200ms
  in always-running loop() programs. Save long tones for setup() or infrequent events.

COMMON STRUCTURAL ISSUE:
- Students use independent if statements when they mean else if.
  Example: if (light < 200) → set blue; if (touch > 50) → set red.
  If both are true, the ring ends up red every time (last write wins).
  Walk around and look for this pattern — it's a good teaching moment about
  execution order.

MOOD RING CHALLENGE:
- This is a genuinely fun Make It Yours outcome. The color shifts slowly and
  somewhat unpredictably as all three sensors respond to the environment.
  If students get here, have them share their board with the class.

CAPSTONE PREVIEW:
- Use the last 3 minutes to say: "Next time, you're on your own. Your job will be
  to design a device that does something you choose. Start thinking about what you
  want it to do — you already have all the tools."
-->
