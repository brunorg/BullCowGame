#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{

  // ^^ Please try and ignore this and focus on the interface bellow ^^
private:
  // see constructor for initialization
  int32 MyCurrentTry;
  int32 MyMaxTries;

public:
  FBullCowGame(); // constructor
  ~FBullCowGame();

  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  bool IsGameWon() const;

  void Reset();                     // TODO make a more rich return value
  bool CheckGuessValidity(FString); // TODO make a more rich return value
                                    // TODO provide a method for counting Bulls & Cows, and increase turn #
};
