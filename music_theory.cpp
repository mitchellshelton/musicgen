//
// Created by Mitchell Shelton on 6/15/25.
//

#include "music_theory.h"

MusicTheory::MusicTheory() {
  build_data();
}

void MusicTheory::build_data() {
  SongScale song_scale = {
    {
      "Major", {
        "C",
        "G",
        "D",
        "A",
        "E",
        "B",
        "Gb",
        "F#",
        "Db",
        "Ab",
        "Eb",
        "Bb",
        "F"
      }
    },
    {
      "Minor", {
        "A",
        "E",
        "B",
        "F#",
        "C#",
        "G#",
        "Eb",
        "D#",
        "Bb",
        "F",
        "C",
        "G",
        "D"
      }
    }
  };

  // Scales
  // # = sharp, b = flat, ## = double sharp, bb = double flat
  // Define our vector structure
  ScaleData scales = {
    {"Major", {
      { "Cb", { "Cb", "Db", "Eb", "Fb", "Gb", "Ab", "Bb" }},
      { "C", { "C", "D", "E", "F", "G", "A", "B" }},
      { "C#", { "C#", "D#", "E#", "F#", "G#", "A#", "B#" }},
      { "Db", { "Db", "Eb", "F", "Gb", "Ab", "Bb", "C" }},
      { "D", { "D", "E", "F#", "G", "A", "B", "C#" }},
      { "D#", { "D#", "E#", "F##", "G#", "A#", "B#", "C##" }},
      { "Eb", { "Eb", "F", "G", "Ab", "Bb", "C", "D" }},
      { "E", { "E", "F#", "G#", "A", "B", "C#", "D#" }},
      { "E#", { "E#", "F##", "G##", "A#", "B#", "C##", "D##" }},
      { "Fb", { "Fb", "Gb", "Ab", "Bbb", "Cb", "Db", "Eb" }},
      { "F", { "F", "G", "A", "Bb", "C", "D", "E" }},
      { "F#", { "F#", "G#", "A#", "B", "C#", "D#", "E#" }},
      { "Gb", { "Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F" }},
      { "G", { "G", "A", "B", "C", "D", "E", "F#" }},
      { "G#", { "G#", "A#", "B#", "C#", "D#", "E#", "F##" }},
      { "Ab", { "Ab", "Bb", "C", "Db", "Eb", "F", "G" }},
      { "A", { "A", "B", "C#", "D", "E", "F#", "G#" }},
      { "A#", { "A#", "B#", "C##", "D#", "E#", "F##", "G##" }},
      { "Bb", { "Bb", "C", "D", "Eb", "F", "G", "A" }},
      { "B", { "B", "C#", "D#", "E", "F#", "G#", "A#" }},
      { "B#", { "B#", "C##", "D##", "E#", "F##", "G##", "A##" }},
    }},
    { "Minor", {
      { "Cb", { "Cb", "Db", "Ebb", "Fb", "Gb", "Abb", "Bbb" }},
      { "C", { "C", "D", "Eb", "F", "G", "Ab", "Bb" }},
      { "C#", { "C#", "D#", "E", "F#", "G#", "A", "B" }},
      { "Db", { "Db", "Eb", "Fb", "Gb", "Ab", "Bbb", "Cb" }},
      { "D", { "D", "E", "F", "G", "A", "Bb", "C" }},
      { "D#", { "D#", "E#", "F#", "G#", "A#", "B", "C#" }},
      { "Eb", { "Eb", "F", "Gb", "Ab", "Bb", "Cb", "Db" }},
      { "E", { "E", "F#", "G", "A", "B", "C", "D" }},
      { "E#", { "E#", "F##", "G#", "A#", "B#", "C#", "D#" }},
      { "Fb", { "Fb", "Gb", "Abb", "Bbb", "Cb", "Dbb", "Ebb" }},
      { "F", { "F", "G", "Ab", "Bb", "C", "Db", "Eb" }},
      { "F#", { "F#", "G#", "A", "B", "C#", "D", "E" }},
      { "Gb", { "Gb", "Ab", "Bbb", "Cb", "Db", "Ebb", "Fb" }},
      { "G", { "G", "A", "Bb", "C", "D", "Eb", "F" }},
      { "G#", { "G#", "A#", "B", "C#", "D#", "E", "F#" }},
      { "Ab", { "Ab", "Bb", "Cb", "Db", "Eb", "Fb", "Gb" }},
      { "A", { "A", "B", "C", "D", "E", "F", "G" }},
      { "A#", { "A#", "B#", "C#", "D#", "E#", "F#", "G#" }},
      { "Bb", { "Bb", "C", "Db", "Eb", "F", "Gb", "Ab" }},
      { "B", { "B", "C#", "D", "E", "F#", "G", "A" }},
      { "B#", { "B#", "C##", "D#", "E#", "F##", "G#", "A#" }},
    }},
    { "Diminished", {
      // # = sharp, b = flat, ## = double sharp, bb = double flat
      { "Cb", { "Cb", "Ebb", "Gbb" }},
      { "C", { "C", "Eb", "Gb" }},
      { "C#", { "C#", "E", "G" }},
      { "Db", { "Db", "Fb", "Abb" }},
      { "D", { "D", "F", "Ab" }},
      { "D#", { "D#", "F#", "A" }},
      { "Eb", { "Eb", "Gb", "Bbb" }},
      { "E", { "E", "G", "Bb" }},
      { "E#", { "E#", "G#", "B" }},
      { "Fb", { "Fb", "Abb", "Cbb" }},
      { "F", { "F", "Ab", "Cb" }},
      { "F#", { "F#", "A", "C" }},
      { "Gb", { "Gb", "Bbb", "Dbb" }},
      { "G", { "G", "Bb", "Db" }},
      { "G#", { "G#", "B", "D" }},
      { "Ab", { "Ab", "Cb", "Ebb" }},
      { "A", { "A", "C", "Eb" }},
      { "A#", { "A#", "C#", "E" }},
      { "Bb", { "Bb", "Db", "Fb" }},
      { "B", { "B", "D", "F" }},
      { "B#", { "B#", "D#", "F#" }},
    }}
  };

  // lower case i = minor, upper case I = major, * = diminished
  ChordProgressionPattern chord_progression_pattern = {
    { "Major", { "I", "ii", "iii", "IV", "V", "vi", "vii*" }},
    { "Minor", { "i", "ii*", "III", "iv", "v", "VI", "VII" }}
  };

  TheoreticalNotes theoretical_notes = {
    { "Double Flats", {
      { "C", { "Bb" } },
      { "D", { "C" } },
      { "E", { "D" } },
      { "F", { "Eb" } },
      { "G", { "F" } },
      { "A", { "G" } },
      { "B", { "A" } },
    }},
    { "Double Sharps", {
      { "C", { "D" } },
      { "D", { "E" } },
      { "E", { "F#" } },
      { "F", { "G" } },
      { "G", { "A" } },
      { "A", { "B" } },
      { "B", { "C#" } },
    }},
    { "Enharmonic", {
      { "E#", { "F" } },
      { "B#", { "C" } },
      { "Fb", { "E" } },
      { "Cb", { "B" } },
    }}
  };
}

std::vector<Chord> chord_table_builder(const ScaleData& scales) {
  std::vector<Chord> table;

  for (const auto& [mode, key_map] : scales) {
    for (const auto& [root, notes] : key_map) {
      if (notes.size() >= 5) {
        table.push_back({
            mode,
            root,
            { notes[0], notes[2], notes[4] }
        });
      }
    }
  }

  return table;
}

const ScaleData& MusicTheory::getScales() const { return scales; }
const SongScale& MusicTheory::getSongScale() const { return song_scale; }
const ChordProgressionPattern& MusicTheory::getChordPatterns() const { return chord_progression_pattern; }
const TheoreticalNotes& MusicTheory::getTheoreticalNotes() const { return theoretical_notes; }
