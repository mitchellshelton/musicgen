//
// Created by Mitchell Shelton on 6/14/25.
//
#include <random>
#include "dice.h"

using namespace std;

// Get a random number between two numbers
int getRandom(const int min, const int max) {
  // Initialize a random number generator
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(min, max);

  // Generate random number in the range [min, max]
  const int randomValue = distrib(gen);

  // Return the random number
  return randomValue;
}

// Roll a given number of multisided dice
// Ex: 2D4
int Dice::roll(int numDice, int numSides) {
  // Handle incorrect dice or sides
  if (numDice == 0) { // Is the quantity zero?
    // There must be at least one die
    numDice = 1;
  }
  if (numSides == 0) { // Are there zero sides?
    // Any die must have at least one side
    numSides = 1;
  }

  // Initialize our return value
  int rollTotal = 0;

  for (int i = 0; i < numDice; i++) {
    int rollResult = 0;

    // Roll the die
    rollResult = getRandom(1, numSides);

    // Add the die roll to our total result
    rollTotal = rollTotal + rollResult;
  }

  // Return the result of our roll
  return rollTotal;
}
