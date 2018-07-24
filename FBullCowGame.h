#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero 
struct BullCowCount
{
  int32 Bull = 0;
  int32 Cow = 0;
};

class FBullCowGame
{

  // ^^ Please try and ignore this and focus on the interface bellow ^^
private:
  // see constructor for initialization
  int32 MyCurrentTry;
  int32 MyMaxTries;
  FString MyHiddenWord;

public:
  FBullCowGame(); // constructor
  ~FBullCowGame();

  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  bool IsGameWon() const;

  void Reset();                     // TODO make a more rich return value
  bool CheckGuessValidity(FString); // TODO make a more rich return value
  BullCowCount SubmitGuess(FString);

};
