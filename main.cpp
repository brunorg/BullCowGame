#include <iostream>
#include <string>

using namespace std;

int main()
{

    // introduce the game
    constexpr int WORLD_LENGTH = 9;

    cout << "Welcome to Bulls and Cows, a fun word game" << endl;
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << " letter isogram I'm thinking of?" << endl;
    cout << endl;

    // get a guess from the player
    cout << "Enter you guess: ";
    string Guess = "";
    getline(cin, Guess);
    // repeat the guess back to them
    cout << "Your guess was: " << Guess << endl;

    // get a guess from the player
    cout << "Enter you guess: ";
    getline(cin, Guess);
    // repeat the guess back to them
    cout << "Your guess was: " << Guess << endl;

    cout << endl;
    return 0;
}
