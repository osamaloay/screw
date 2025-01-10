//
// Created by manso on 11/19/2024.
//

#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "Card.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
using namespace std;


class Deck {
private :
    vector<vector<Card*>> cards_grid;
    int row,coloumn;
public:
    Deck(int row=4,int coloumn=4);
    void shuffle();
    void displayGrid();
    ~ Deck();
    void flip();
    Deck()=default;

    void resetGrid();
    void removeCard(int row, int col);
    bool isEmpty();
    bool flipCards(int x1, int y1, int x2, int y2);
    Card* getCard(int r, int c);
};

#endif //DECK_H
