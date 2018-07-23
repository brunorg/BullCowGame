#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() { return MyMaxTries; }

int FBullCowGame::GetCurrentTry() { return MyCurrentTry; }

void FBullCowGame::Reset(int Word)
{
    return;
}

bool FBullCowGame::IsGameWon()
{
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}
