#pragma once
#include <string>

using namespace std;

class FBullCowGame
{

    // ^^ Please try and ignore this and focus on the interface bellow ^^
  private:
    int MyCurrentTry;
    int MyMaxTries;

  public:
    FBullCowGame(/* args */);
    ~FBullCowGame();
    void Reset(int Word); // TODO make a more rich return value
    int GetMaxTries();
    int GetCurrentTry();
    bool IsGameWon();
    bool CheckGuessValidity(string); // TODO make a more rich return value
};

FBullCowGame::FBullCowGame(/* args */)
{
}

FBullCowGame::~FBullCowGame()
{
}
