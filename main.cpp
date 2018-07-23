#include <iostream>

using namespace std;

int main()
{
    constexpr int WORLD_LENGTH = 5;

    cout << "Welcome to Bulls and Cows, a fun word game" << endl;
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << " letter isogram I'm thinking of?" << endl;

    return 0;
}
