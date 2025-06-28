#include <iostream>
#include "music_theory.h"
#include "progression.h"

int main() {
  std::cout << "Welcome to the Music Generator" << std::endl;

  // Use random key and length
  Progression progression;

  // Use specified key and length
  //Key key = { "C", "Major" }; // quality, note
  //int length = 4;
  //Progression progression(key, length);

  auto song = progression.get_progression();

  std::cout << "Key: " << song.properties.key.note << " " << song.properties.key.quality << "\n";
  std::cout << "Length: " << song.properties.length << "\n";

  std::cout << "Progression: ";
  for (const auto& step : song.progression) {
    std::cout << step << " ";
  }
  std::cout << "\n";

  std::cout << "Chords:\n";
  for (const auto& chord : song.properties.chords) {
    for (const auto& note : chord) {
      std::cout << note << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

