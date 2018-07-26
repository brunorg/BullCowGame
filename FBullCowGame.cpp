#pragma once
#include "FBullCowGame.h"
#include <map>

// to make syntax Unreal friendly
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }
FBullCowGame::~FBullCowGame() {}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
    TMap<int32, int32> WordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "plant"; // This must be an isogram
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess))
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowercase(Guess))
    {
        return EGuessStatus::Not_LowerCase;
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Lenght;
    }
    else
    {
        return EGuessStatus::OK;
    }
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length();
    MyCurrentTry++;

    // loop through all letters in hidden word
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    { // compares letters against guess
        for (int32 GChar = 0; GChar < WordLength; GChar++)
        { // if they match then
            if (Guess[GChar] == MyHiddenWord[MHWChar])
            { // if they're in the same place
                if (MHWChar == GChar)
                {
                    BullCowCount.Bulls++; // increment bulls
                }
                else
                {
                    BullCowCount.Cows++; // must be a cow
                }
            }
        }
    }

    bGameIsWon = (BullCowCount.Bulls == WordLength);

    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{   // treat 0 an 1 letter words as isograms
    if (Word.length() <= 1) { return true; }

    TMap<char, bool> LetterSeen;

    // loop through all letters in Word
    for (auto Letter : Word)
    {
        Letter = tolower(Letter);
        if (LetterSeen[Letter])
        {
            return false;
        }
        else
        {
            LetterSeen[Letter] = true;
        }
    }

    return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{ 
    // loop through all letters in Word
    for (auto Letter : Word)
    {
        if (!islower(Letter))
        {
            return false;
        }
    }

    return true;
}
