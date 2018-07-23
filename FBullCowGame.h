#pragma once
#include <string>

class FBullCowGame
{

    // ^^ Please try and ignore this and focus on the interface bellow ^^
  private:
    // see constructor for initialization
    int MyCurrentTry;
    int MyMaxTries;

  public:
    FBullCowGame();
    ~FBullCowGame();
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset();                         // TODO make a more rich return value
    bool CheckGuessValidity(std::string); // TODO make a more rich return value
};
