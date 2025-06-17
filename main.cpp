#include <iostream>
#include "dice.h"
#include "music_theory.h"

int main() {
  std::cout << "Welcome to the Music Generator" << std::endl;

  // TODO:
  // DONE - Dice Class
  // DONE - dice.cpp
  // DONE - - Test by rolling a die in main
  // Music Theory Class
  // music_theory.cpp
  // - Test by building a progression manually in main
  // Progression Class
  // progression.cpp
  // - Test by calling from main (final deployment method)

  Dice dice;
  std::cout << "Roll 1: 2D4" << std::endl;
  std::cout << Dice::roll(2, 4) << std::endl;
  std::cout << "Roll 2: 3D8" << std::endl;
  std::cout << Dice::roll(3, 8) << std::endl;
  std::cout << "Roll 3: 1D20" << std::endl;
  std::cout << Dice::roll(1, 20) << std::endl;

  // MusicTheory theory;
  // ScaleData scales = theory.getScales();


  return 0;
}