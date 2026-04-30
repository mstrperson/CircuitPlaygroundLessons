# Lesson 8 — Finding Your Project

## Learning Goals
- Students will be able to describe what each Circuit Playground sensor and output can do in plain language.
- Students will be able to identify at least one project idea they are genuinely excited to build.
- Students will be able to write a project brief — a concrete description of what their device does, what inputs it uses, and what outputs it produces.

## New Vocabulary
- **project brief** — a short written description of what you are building, who it is for, and what it does. Written before any code, so you have a target.
- **input** — anything the device reads from the world: sensors, buttons, touch pads.
- **output** — anything the device does in response: lights, sounds.

## Warm-Up (~5 min)

Ask students to look back at anything they made in Lessons 1–7 and answer:

> *"What's the coolest thing your board did this unit? What did you wish it could do that you didn't have time for?"*

Take three or four answers. Write them on the board — they'll serve as raw material during the ideation activity.

## Direct Instruction (~10 min)

<!--
TEACHER DEMO — TOUR OF POSSIBILITIES:
For each project archetype below, run a 60-second demo on a pre-loaded board.
Students don't need to understand the code — this is inspiration, not instruction.
The goal is: "I didn't know it could do THAT. I want to do something like that."

If you don't have time to load all five, describe them verbally and show the starter
code on the projector — even reading the behavior comments is enough to spark ideas.
-->

Below are five **project archetypes** — starting-point ideas. Your project doesn't have to match one of these exactly, but most ideas will be close to one of them.

---

### Archetype A — Mood Light
**What it does:** The ring color shifts continuously in response to the environment — light level, sound level, temperature, or some combination. There's no "event"; it just always reflects the world around it.

*Example: Red = warm room, Blue = cool room, brightness = how quiet it is.*

**Key sensors:** `lightSensor()`, `soundSensor()`, `temperature()`  
**Key output:** continuous pixel color, `map()` to translate sensor → color channel  
**Physical form ideas:** a paper lantern or frosted-acrylic globe that diffuses the light; a framed "mood window" hung on the wall.

---

### Archetype B — Touch Instrument
**What it does:** Each touch pad plays a different note and changes the ring color. It's a playable instrument you can perform with.

*Example: Four pads play C, E, G, C5. The ring shows a different color for each note.*

**Key sensors:** `readCap()` on multiple pins  
**Key output:** `playTone()`, `setPixelColor()`  
**Physical form ideas:** copper tape "keys" on a strip of cardboard or paper, laid out like a keyboard. The board hides underneath; only the keys are visible. Alligator clips or copper tape traces connect each key back to a touch pin.

---

### Archetype C — Motion Toy
**What it does:** The accelerometer drives behavior. Tilting, shaking, or flipping the board changes what happens.

*Example: Tilt left = blue ring. Tilt right = red ring. Shake hard = white flash + alarm tone.*

**Key sensors:** `motionX()`, `motionY()`, `motionZ()`  
**Key output:** pixels, optional tones  
**Physical form ideas:** mounted inside a small box or ball that students hold and tilt; attached to a wand or handle; embedded in a squishy foam case.

---

### Archetype D — Creature / Story Device
**What it does:** The board has a personality. It has a resting "face" (a calm light pattern) and reacts when touched, squeezed, shaken, or clapped at.

*Example: Glows green slowly at rest. Touched → plays a happy melody and flashes yellow. Clapped at → turns red and buzzes.*

**Key sensors:** `readCap()`, `soundSensor()`, `motionZ()`  
**Key output:** pixel patterns, `playTone()` melodies  
**Physical form ideas:** a stuffed creature or cardboard character where the Circuit Playground is the glowing "heart" or "eye." Copper tape traces connect internal touch pads to spots on the exterior (a nose, a hand, a button on a costume).

---

### Archetype E — Environment Monitor
**What it does:** Displays a real measurement from the environment as a visual or audio readout. Acts like a scientific instrument.

*Example: Shows room temperature as a color (blue = cold, red = hot). Plays a low hum when it's too loud in the room.*

**Key sensors:** `temperature()`, `lightSensor()`, `soundSensor()`  
**Key output:** color mapped from sensor value, optional alert tone  
**Physical form ideas:** mounted in a small frame or stand so it faces outward like a gauge; labeled with a legend ("blue = cold, red = warm") cut from paper or vinyl.

---

## Guided Activity: Choosing Your Project (~25 min)

Work through these steps in order. **Do not open the Arduino IDE until Step 4.**

**Step 1 — React to the archetypes (3 min)**

Look at the five archetypes. Put a checkmark next to any that interest you. Put an X next to any that don't. You don't have to choose yet.

**Step 2 — Explore your own idea (5 min)**

Ask yourself:
- Is there something in my life I'd want this board to help with or express?
- Is there something from Lessons 1–7 I wanted to keep going with?
- Is there an archetype I'd remix into something different?

Write down every idea, even bad ones. Aim for at least three.

**Step 3 — Narrow to one (5 min)**

Pick the idea you're most excited about. If you're stuck between two, ask: *"Which one would I most want to show someone at the end of class?"* That's your answer.

**Step 4 — Write your project brief (10 min)**

Fill in this template on paper or in a shared doc:

```
PROJECT BRIEF

My device is called: _______________________________

In one sentence, it: ________________________________
________________________________________

It uses these INPUTS:
  [ ] Light sensor      [ ] Sound sensor     [ ] Temperature
  [ ] Motion (tilt)     [ ] Capacitive touch  [ ] Buttons
  (if touch: which pins? ________________________)

It produces these OUTPUTS:
  [ ] Pixel colors      [ ] Pixel patterns    [ ] Tones
  [ ] A melody          [ ] Other: _____________

My three "when…then…" behaviors:
  1. When _______________, then _______________
  2. When _______________, then _______________
  3. When _______________, then _______________

Resting state (what does it look/sound like when nothing triggers?):
  _____________________________________________

Physical form — what does it look like / live inside?
  _____________________________________________
  Materials I plan to use from the Maker Space:
  [ ] Cardboard / paper   [ ] Copper tape   [ ] Craft supplies
  [ ] Foam / fabric       [ ] Wire / clips  [ ] Other: _______
  [ ] 3D print or laser cut (describe why cardboard won't work):
      ___________________________________________

The closest archetype is: A / B / C / D / E / none of the above
```

**Step 5 — Get your brief approved (2 min)**

Show your brief to the teacher before you open the Arduino IDE. The teacher will check:
- Does it use at least two inputs?
- Does it use at least two outputs (or one sensor mapped continuously to an output)?
- Is it specific enough that you could tell if you built it successfully?
- If it uses copper tape or physical materials: is the wiring plan clear enough to build from?
- If it needs the 3D printer or laser cutter: is there a good reason cardboard won't work?

## Wrap-Up (~5 min)

<!-- Share-out: students pair up and read each other's one-sentence description.
     The listener asks: "What does it look like when [resting state]? What triggers it to change?"
     Goal: hearing your brief described back to you reveals where it's vague.
     Send students home with their brief — they'll need it next class. -->

Share your one-sentence description with a partner. Partner: ask two questions — what does it look like at rest, and what makes it change?

## Teacher Notes

<!--
THE BRIEF APPROVAL STEP:
- This is worth enforcing. Students who start coding without a clear target drift and
  get frustrated. Even a 30-second "yes, go for it" gives them permission and momentum.
- Watch for briefs that are too vague ("it reacts to stuff") or too ambitious
  ("it plays any song I hum to it"). Push vague briefs toward specifics;
  push ambitious ones toward a simpler first version.

ARCHETYPE SELECTION:
- Most students will land on B (Touch Instrument) or D (Creature) — these are the
  most immediately playable and social.
- A (Mood Light) appeals to students who are more process-oriented and comfortable
  with less "event" drama.
- C (Motion Toy) works well for students who fidget — they'll naturally explore tilt.
- E (Environment Monitor) is good for students with a science interest.

STUDENTS WITH NO IDEAS:
- Ask: "If this board could tell you one thing about the room right now, what would
  you most want to know?" → usually leads to Archetype E.
- Ask: "If you could use this as an instrument in a song, what would it play?" → B.
- Ask: "If this board were alive, what would its personality be?" → D.

STUDENTS WITH OVERLY AMBITIOUS IDEAS:
- Validate the idea, then scope it: "Love it. What's the simplest version of that
  which would still feel like YOUR thing? Let's build that first."

PACING NOTE:
- If students finish the brief early, have them start identifying which starter code
  scaffold from Lesson 9 they'll use. They can begin reading it before next class.
-->
