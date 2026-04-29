# Lesson 6 — Play a Song

---

# Can you read this?

```
262  294  330  262  262  294  330  262  330  349  392
```

No?

What about this?

```
E4  D4  C4  D4  E4  E4  E4  D4  D4  E4  G4
```

Those are the same pitches — just impossible to read when they're raw numbers.  
This is the problem `#define` solves.

---

# #define: find-and-replace before your code runs

```cpp
#define a4  440
```

Every time the compiler sees `a4` in your code, it replaces it with `440` before compiling.

The name is **not a variable.** You cannot write `a4 = 500` later.

Think of it as: the compiler does a **find-and-replace** on your code before it runs.

---

# Note constants

```cpp
#define c4  260.74
#define d4  293.33
#define e4  330.00
#define f4  347.65
#define g4  391.11
#define a4  440.00
#define b4  495.00
#define c5  521.48
```

*(These frequencies are in Pythagorean temperament — a tuning system built from  
pure perfect fifths. If you know what that means, you found the easter egg.)*

---

# Duration constants

```cpp
#define quarter  500      // 120 beats per minute
#define half     quarter * 2
#define whole    quarter * 4
#define eighth   quarter / 2
```

Each duration is defined in terms of `quarter`, so they stay in proportion.

If you change `quarter` to `375`, the whole song runs at 160 bpm automatically.

---

# delay() is a rest

```cpp
CircuitPlayground.playTone(e4, quarter);
delay(50);
CircuitPlayground.playTone(d4, quarter);
delay(50);
```

- A **longer** `delay()` is an audible rest — silence between phrases, like a rest in sheet music.
- The short `delay(50)` after each note is too brief to hear as silence, but it prevents the same note played twice from blurring into one long tone.
- Musicians call that separation **staccato**.

---

# Open your starter code

Open **`Lesson06_PlayASong.ino`**.

Upload it. Follow along as it plays.

Can you match each `playTone` call in the code to the note you hear?

---

# Step 3 — Finish the song

The starter code has the first phrase only. Add the second phrase below `// YOUR SONG CONTINUES HERE`:

| Note | Duration |
|------|----------|
| d4   | quarter  |
| d4   | quarter  |
| d4   | half     |
| e4   | quarter  |
| g4   | quarter  |
| g4   | half     |

Don't forget a `delay(50)` after each note.

---

# Step 4 — Third and fourth phrases

```
Third phrase:   e4  d4  c4  d4  e4  e4  e4  e4
Fourth phrase:  d4  d4  e4  d4  c4  (whole note)
```

All quarter notes unless shown otherwise. Add them below the second phrase.

---

# Step 5 — Loop it

Move all your `playTone` calls from `setup()` to `loop()`.  
Add a `delay(1000)` at the very end of `loop()`:

```cpp
void loop() {
  // ... all your playTone calls ...

  delay(1000);  // pause before the song repeats
}
```

---

# Make It Yours

- **Transcribe a different song** — try *Hot Cross Buns*, *Ode to Joy*, or *Twinkle Twinkle*. Use the note definitions at the top of the file.
- **Add your signature color** — change the ring color at the start and end of your song using the values you found in Lesson 2.
- **Define your own duration** — want a dotted quarter note? Add `#define dotted_quarter  quarter + eighth` and use it.
- **Challenge:** Transcribe a song that jumps between octaves — use both `c4` and `c5` in the same piece and listen to the leap.

---

# Exit Ticket

In your own words:

> What is the difference between `#define` and a variable?

Target idea: a `#define` name is replaced before the program runs and cannot be changed; a variable is a box the program can update while running.
