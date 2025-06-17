#ifndef MUSIC_THEORY_H
#define MUSIC_THEORY_H

#include <string>
#include <vector>
#include <unordered_map>

// Struct for each chord
struct Chord {
  std::string mode;
  std::string root;
  std::vector<std::string> notes;
};

// Type Aliases
using ScaleData = std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>>;
using SongScale = std::vector<std::pair<std::string, std::vector<std::string>>>;
using ChordProgressionPattern = std::vector<std::pair<std::string, std::vector<std::string>>>;
using NoteEquivalents = std::unordered_map<std::string, std::vector<std::string>>;
using TheoreticalNotes = std::unordered_map<std::string, NoteEquivalents>;

class MusicTheory {
public:
  MusicTheory(); // constructor builds the scale map and related data

  std::vector<Chord> chord_table_builder() const;

  // Public getters if needed
  const ScaleData& getScales() const;
  const SongScale& getSongScale() const;
  const ChordProgressionPattern& getChordPatterns() const;
  const TheoreticalNotes& getTheoreticalNotes() const;

private:
  ScaleData scales;
  SongScale song_scale;
  ChordProgressionPattern chord_progression_pattern;
  TheoreticalNotes theoretical_notes;

  void build_data(); // internal method to populate the data
};

#endif
