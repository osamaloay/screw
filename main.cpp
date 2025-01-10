
#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    cout << "Welcome to the Memory Match Game!\n" << endl;

    // Prompt for player names
    string player1_name, player2_name;
    cout << "Enter Player 1's name: ";
    cin >> player1_name;
    cout << "Enter Player 2's name: ";
    cin >> player2_name;

    // Create a game instance with a 4x4 grid
    Game game(player1_name, player2_name);

    // Initialize and start the game
    //game.initializeGame();
    game.play();

    return 0;
}


