#pragma once
#include <string>

class FBullCowGame
{

    // ^^ Please try and ignore this and focus on the interface bellow ^^
  private:
    int MyCurrentTry = 1;
    int MyMaxTries = 5;

  public:
    FBullCowGame(/* args */);
    ~FBullCowGame();
    void Reset(int Word); // TODO make a more rich return value
    int GetMaxTries();
    int GetCurrentTry();
    bool IsGameWon();
    bool CheckGuessValidity(std::string); // TODO make a more rich return value
};

FBullCowGame::FBullCowGame(/* args */)
{
}

FBullCowGame::~FBullCowGame()
{
}
