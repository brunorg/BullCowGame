#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }
FBullCowGame::~FBullCowGame() {}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 5;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
    return false;
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment the turn number
    MyCurrentTry++;

    // setup a return variable
    FBullCowCount BullCowCount;

    int32 HiddenWordLength = MyHiddenWord.length();

    for (int32 i = 0; i < HiddenWordLength; i++)
    {
        // loop through all letters in the guess
        for (int32 j = 0; j < HiddenWordLength; j++)
        {
            // compares letters against the hidden word
            if (MyHiddenWord[i] == Guess[j])
            { // if they match then
                if (i == j)
                {                         // if they're in the same place
                    BullCowCount.Bulls++; // increment bulls
                }
                else
                {
                    BullCowCount.Cows++; // increment cows
                }
            }
        }
    }

    return BullCowCount;
}
