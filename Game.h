//
// Created by manso on 11/20/2024.
//

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Deck.h"
#include "Player.h"
#include "StandardCard.h"
#include "PenaltyCard.h"
#include "BonusCard.h"
#include "Card.h"

using namespace std;

class Game {
private:
    Player p1;
    Player p2;
    Deck deck;
    bool player1_turn;
    bool skipTurn;
    void handleTurn(Player& currentPlayer);
    void applyCardEffects(Player& currentPlayer, Card* card1, Card* card2);

public :
    Game();
    Game(string& name1,string& name2, int rows, int cols);
    Game(string& player1_name,string& player2_name);
    void initializeGame();
    void play();
    void announceWin();
    ~Game();

};

#endif //GAME_H
