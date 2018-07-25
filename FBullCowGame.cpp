#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }
FBullCowGame::~FBullCowGame() {}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 5;
    const FString HIDDEN_WORD = "ant";

    MyMaxTries = MAX_TRIES;
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

    int32 HiddenWordLength = GetHiddenWordLength();

    for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
    {
        // loop through all letters in the guess
        for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
        {
            // compares letters against the hidden word
            if (Guess[GChar] == MyHiddenWord[MHWChar])
            { // if they match then
                if (MHWChar == GChar)
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
