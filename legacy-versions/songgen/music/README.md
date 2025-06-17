music
========

A module for randomly generating MIDI files for juncmodule

New songs will be created as nodes. All song generation will happen outside of and independent of node generation through a single interface. When a save button is clicked, the new node will be generated.

---
- Generator
  - Create a Progression with 4 Chords
  - Create Chord Pattern
  - Create Bass Pattern
  - Create Melody 1 Pattern
  - Create Melody 2 Pattern
  - Create Melody 3 Pattern
  - Create Intro/Outro Pattern

Circle
I - IV - viio - iii - vi - ii - V - I

50s
I - vi - IV - V
I - vi - ii - V

Blues
I - I - I - I
IV - IV - I - I
V - IV - I - I

Chord relationships:
relative notes:
1 - 6
4 - 2
5 - 3

diminished (atonal)
7

Chord progressions will use relative notes or ascending and descending relationships. Progressions will always start on 1 and end on 1 and sometimes 5. Progressions will be constructed on a template of 4, 8, and 12 notes. 4 note patterns will be represented as 8 notes with the first pattern repeated, but ending on a 1 instead of the note the 4 note progression ends on (which in the case of 4 note progressions, is never 1). 7's will appear randomly sometimes in the center of the progression and should be preceded or followed by a 6. All 4 and 8 note patterns will be extended to 12 notes. A 4 note progression will repeat twice with the second modified 4 as described earlier appearing at the end. An 8 note pattern will repeat the last 4 notes two times. This allows for simpler pattern to emerge while maintaining an easier to work with 12 note structure. At the 2, 4, and 6th notes (respective to progression length) there is a 25% chance that a diminished note will occur.

1 - 6
1 - 2
1 - 4
1 - 5

2 - 1
2 - 4
2 - 3

3 - 5
3 - 4
3 - 2

4 - 2
4 - 5
4 - 1
4 - 3

5 - 3
5 - 6
5 - 4
5 - 1

6 - 1
6 - 7
6 - 5

7 - 6

---

## Possible Part Building Techniques

---

Bass

root of chord - walk through corresponding key - return to next root of chord

Create a function to return a scale
Create a function to return a leading note from a given note in a given scale
Create a function to return a following note from a given note in a given scale

---

Simple Chord based

---

Create a Progression with 4 Chords
Create Chord Pattern
  root, third, and fifth on each 1 beat
Create Bass Pattern
  root and fifth on each 1 beat
Create Melody 1 Pattern
  2 root notes followed by two fifth notes on each beat with one chord represented for each measure
Create Melody 2 Pattern
  2 root notes followed by two third notes on each beat with one chord represented for each measure
Create Melody 3 Pattern
  1 root note, followed by two third notes, and finally by one fifth note on each beat with one chord represented for each measure

Complex Melody Based

---

Bass
  If there are 6 or more notes in a section, sustain the first note for two steps
  Play every other note in each section as they are presented
Chords:
  Drop every note except for first note in the section
  Add a major 3rd and perfect 5th to each note (create a triad)
  Sustain each note (chord) until the next note begins
Melody 1
  Drop every other note
  Drop every third note, skipping to the next if it is the starting note for that section
Melody 2
  Drop every other note in Melody 2
  Drop any notes that occur in melody 1 except the first note of every section
Melody 3
  Drop every other note in Melody 3, starting with the second note (note 1 and 3 should be dropped)
  Drop every third note, skipping to the next if it is the starting note for that section
  Add the very first and very last note back to Melody 3
Melody 1 Intervals
  Mark every other note, skipping the next if it is the starting note for that section, for a interval change
  Mark every other interval change as 5th or 3rd, starting with 5th
  Replace root notes with a major 3rd or perfect 5th where marked for an interval change
Melody 2 & 3 Intervals
  Mark every third note, skipping the next if it is the starting note for that section, for a interval change
  Mark every other interval change as 5th or 3rd, starting with 3rd on Melody 2 and 5th on Melody 3
  Replace root notes with a major 3rd or perfect 5th where marked for an interval change