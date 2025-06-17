# Song Builder

## Process

> Notes to build out the process

---

- Machinedrum
  - Default Drum Kit Layout
- Monomachine
  - Track 1: Backing
  - Track 2: Bass
  - Track 3: Melody 1
  - Track 4: Melody 2
  - Track 5: Melody 3
  - Track 6: Machinedrum Thru

- Timing Breakdown
  - 16 Steps/Measure
  - 4 Measures/Pattern
  - 64 Total Steps/Pattern
  - 120 BPM
  - 4 Beats/Measure
  - 1 Measure/2 Seconds
  - 3 Minutes = 180 Seconds = 90 Measures

- Instrument Parts
  - Backing
  - Bass
  - Melody 1
  - Melody 2
  - Melody 3
  - Kick
  - Percussion

- Song Structure Parts
  - Intro: Kick and Backing
  - Verse 1: Kick, Percussion, Bass, Backing, and Melody 1
  - Verse 2: Kick, Percussion, Bass, Backing, and Melody 2
  - Verse 3: Kick, Percussion, Bass, Backing, and Melody 3
  - Verse 4: Kick, Percussion, Bass, Backing, Melody 1, and Melody 3
  - Chorus: Kick, Percussion, Bass, Backing, Melody 1, Melody 2, and Melody 3
  - Bridge: Bass and Percussion
  - Outro: Kick and Backing

---

> Section One - The Progression
- First we need to create the progression. A few parameters are needed to generate the progression. This returns an array of chord triads for the generated progression.

1. Select Note Value
2. Select Note Quality
3. Select Progression Duration

*Much of this section is already complete*

> Section Two - Song Parts
- Next we take the progression and break it down into Instrument Parts

1. Kick and Percussion
  - Multiple basic Kick, Snare, and HiHat combinations will be offered. Since all notes and accents are determined by the placement of the kick and snare this must be selected first. A alternative melody oriented percussion track will also be available.
2. Backing
  - Full Chorded Notes would usually be called for here. Due to the use of the Monomachine this isn't possible without using 3 channels. An optional machine is provided that simulates a chord. This limitation on sound is not always acceptable for the desired results. An alternative option will be to use the perfect fifth note from each triad.
3. Bass
  - The bass uses a repeated root note from the triad that follows the kick drum. An alternative variation allowing for a alternative root and third will also be available.
4. Melody 1, 2, and 3
  - Alternative methods of melody generation need to be created. Melodies will be accented based on Kick and Snare placement. Likely methods of generation involve spreading arpeggios across all three melodies so that each step is filled with a note from an alternating melody track.

*A bulk of the project work takes place here*

> Section Three - Output
- Output of the generator is done in the form of arrays displayed in tables. Notes then need to be manually entered into the Machinedrum and Monomachine. An automated export feature is not planned at this time.

*This is simple display work*

---

### Melody Generation - Method One

- The Parts
  - Call
    - 1/2 bar
    - steps 1-8
  - Response
    - 1/2 bar
    - steps 9-16
  - Call Repetition
    - 1/2 bar
    - steps 17-24 (1-8: Measure 2)
  - Response Variation
    - 1/2 bar
    - steps 25-32 (9-16: Measure 2)

- Melody 1
  - Call
  - Call Repetition
- Melody 2
  - Call
  - Response
  - Call Repetition
- Melody 3
  - Call
  - Call Repetition
  - Response Variation

- Other Notes
  - All 3 sounds play call and call repetition
  - Only Melody 2 and Melody 3 play responses
  - 4-6 Notes for each part
  - 4-8 Silent notes across each bar
  - Melody silence positioning should be used in percussion

> The Process

1. Randomly generate call duration (4-6 notes)
2. Randomly generate response duration (4-6 notes)
3. Call - first note is root
4. Response Variation - last note is root
5. Generate Call based on low to high pattern
  - root-mid-mid-high: 1, 4-5, 4-5, 6-7
6. Generate Response based on high to low pattern
  - high-low-mid-mid (no root): 6-7, 2-3, 4-5, 4-5
7. Generate Response Variation
  - high-low-mid-root: 6-7, 2-3, 4-5, 1
8. Using Call and Response durations get silence duration
9. Randomly generate rhythm based on silences

> Much of the above outlined method is based on the following section for generating a "pleasing" pattern and the related progression pattern:

```

  // These are tonal steps for generating a "pleasing" pattern.
  // The 1 represents the first note in the pattern with the numbers
  // in the corresponding array representing the position of the next note.
  // This can be used both for chord progressions and melody generation.
  var steps = {
    1: [1, 2, 3, 4, 5, 6, 7],
    2: [4, 5, 7],
    3: [2, 4, 6],
    4: [1, 3, 5, 7],
    5: [1],
    6: [2, 4, 5, 1],
    7: [1, 3]
  };

  // The numbers above correspond to the following chord progression patterns
  chord_progression_pattern = {
    // lower case i = minor, upper case I = major, * = diminished
    "Major": ["I", "ii", "iii", "IV", "V", "vi", "vii*"],
    "Minor": ["i", "ii*", "III", "iv", "v", "VI", "VII"]
  };

```

---

