//
// Created by Manuel Kevorkian on 14/12/2024.
//
#include "Deck.h"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

Deck::Deck(int row, int coloumn) :row(row),coloumn(coloumn){
    vector<Card*>
    screw;
    for (int i = 0; i < 6; ++i) {
        screw.push_back(new StandardCard(i + 1));
        screw.push_back(new StandardCard(i + 1));

        // the 1->6 standard , 7,8 bonuss and penalty
    }
    screw.push_back(new BonusCard(7,1));
    screw.push_back(new BonusCard(7,1));

    screw.push_back(new PenaltyCard(8,1));
    screw.push_back(new PenaltyCard(8,1));
    // another solution for shuffling is BogoSort shuffling
    random_device rd;
    mt19937 g(rd());
    std::shuffle(screw.begin(),screw.end(),g);

    auto it = screw.begin();

    for (int r = 0; r < row; ++r) {
        std::vector<Card*> row;
        for (int c = 0; c < coloumn; ++c) {
            row.push_back(*it++);

        }
        cards_grid.push_back(row);
    }
}
void Deck::shuffle()  {
    std::vector<Card*> cards;

    for (auto& row : cards_grid) {
        for (auto& card : row) {
            cards.push_back(card);
        }
    }

    // Shuffle the cards
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);

    // Assign back to the grid
    auto it = cards.begin();
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < coloumn; ++c) {
            cards_grid[r][c] = *it++;
        }
    }

}

void Deck::displayGrid() {
    for (auto& row : cards_grid) {
        for (const auto& card : row) {
            card->display();
            cout<<" ";
        }
        std::cout <<"\n";
    }
}

Deck::~Deck() {
    for (auto& row : cards_grid) {
        for (auto& card : row) {
            delete card;
        }
    }
}




// Flip the cards at the specified coordinates
bool Deck::flipCards(int x1, int y1, int x2, int y2) {
    // Validate coordinates
    if (x1 < 0 || x1 >= row || y1 < 0 || y1 >= coloumn ||
        x2 < 0 || x2 >= row || y2 < 0 || y2 >= coloumn ||
        !cards_grid[x1][y1] || !cards_grid[x2][y2] ||
        (x1 == x2 && y1 == y2)) {
        return false; // Invalid input
        }

    // Flip the selected cards
    cards_grid[x1][y1]->reveal();
    cards_grid[x2][y2]->reveal();

    return true;
}


void Deck::flip() {
    for (auto& row : cards_grid) {
        for (auto& card : row) {
            card->toggle();
        }
    }
}
// Reset the grid by flipping all cards face-down
void Deck::resetGrid() {
    for (auto& gridRow : cards_grid) {
        for (auto& card : gridRow) {
            if (card) {
                card->hide();
            }
        }
    }
}
// Remove a card from the grid by its coordinates
void Deck::removeCard(int r1, int c1) {
    if (r1 >= 0 && r1 < row && c1 >= 0 && c1 < coloumn && cards_grid[r1][c1] != nullptr ) {
        delete cards_grid[r1][c1]; // Free the memory allocated for the first card
        cards_grid[r1][c1] = new Card(-1); // Replace with a blank card


    }
}

// Check if all cards have been removed
bool Deck::isEmpty() {
    for (const auto& gridRow : cards_grid) {
        for (const auto& card : gridRow) {
            // Check if the card is not nullptr and not a blank card
            if (card != nullptr && card->get_data() != -1) {
                return false; // Found a valid card
            }
        }
    }
    return true; // All cards are either nullptr or blank
}
// Get a pointer to the card at the specified coordinates
Card* Deck::getCard(int r, int c){
    if (r >= 0 && r < row && c >= 0 && c < coloumn) {
        return cards_grid[r][c];
    }
    return nullptr;
}