#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

enum class EGuessStatus
{
  Invalid,
  OK,
  Not_Isogram,
  Wrong_Lenght,
  Not_LowerCase
};

class FBullCowGame
{

  // ^^ Please try and ignore this and focus on the interface bellow ^^
private:
  // see constructor for initialization
  int32 MyCurrentTry;
  int32 MyMaxTries;
  FString MyHiddenWord;
  bool bGameIsWon;
  bool IsIsogram(FString) const;
  bool IsLowercase(FString) const;

public:
  FBullCowGame(); // constructor
  ~FBullCowGame();

  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const;
  bool IsGameWon() const;
  EGuessStatus CheckGuessValidity(FString) const;

  void Reset();                           // TODO make a more rich return value
  FBullCowCount SubmitValidGuess(FString);
};
