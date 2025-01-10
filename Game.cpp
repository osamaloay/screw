//
// Created by Manuel Kevorkian on 14/12/2024.
//
#include "Game.h"
#include <iostream>
using namespace std;


Game::Game(string& player1_name, string& player2_name): deck(4, 4), p1(player1_name), p2(player2_name) {
    player1_turn = true;
    skipTurn = false;
}


//void Game::initializeGame() {
    //deck.shuffle();
    //deck.displayGrid();
    //deck.flip();
//}


void Game::play() {
    //initializeGame();
    while (!deck.isEmpty()) {

        //cout << "Current Grid:";
        deck.displayGrid();
        p1.displayScore();
        p2.displayScore();
        cout << (player1_turn ? p1.get_name() : p2.get_name()) << " 's turn: "<<endl;

        if (skipTurn) {

            cout << "Turn skipped!"<<endl;
            skipTurn = false;
            player1_turn = !player1_turn;
            continue;
        }
        handleTurn(player1_turn ? p1 : p2);

        if (deck.isEmpty()) {
            cout << "All cards have been matched"<<endl;
            break;
        }
        player1_turn = !player1_turn;
    }
    announceWin();

}



void Game::handleTurn(Player& currentPlayer) {
    int x1, y1, x2, y2;

    while (true) {
        cout << "Enter coordinates of the first card"<<endl;
        cin >> x1 >> y1;
        x1--;
        y1--;
        cout << "Enter coordinates of the second card"<<endl;;
        cin >> x2 >> y2;
        x2--;
        y2--;

        if (x1 < 0 || x1 >= 4 || y1 < 0 || y1 >= 4 || deck.getCard(x1, y1) == nullptr|| deck.getCard(x1, y1)->get_data() == -1) {
            cout << "Invalid coordinates or no card at this position. Please try again."<<endl;
            continue;
        }
        if (x2 < 0 || x2 >= 4 || y2 < 0 || y2 >= 4 || deck.getCard(x2, y2) == nullptr|| deck.getCard(x1, y1)->get_data() == -1) {
            cout << "Invalid coordinates or no card at this position. Please try again."<<endl;
            continue;
        }
        if (x1 == x2 && y1 == y2) {
            cout << "You cannot select the same card twice. Please try again."<<endl;
            continue;
        }

        if (!deck.flipCards(x1, y1, x2, y2)) {
            cout << "Invalid selection. Try again."<<endl;
            continue;
        }


        deck.displayGrid();

        Card* card1 = deck.getCard(x1, y1);
        Card* card2 = deck.getCard(x2, y2);

        if (card1 && card2) {

            //matching cards
            if (card1->isMatch(card2)) {
                cout << "It's a match!"<<endl;
                currentPlayer.increaseScore(1);
                deck.removeCard(x1, y1);
                deck.removeCard(x2, y2);

                if (deck.isEmpty()) {
                    cout << "All cards have been matched. The game is over!"<<endl;
                    return;
                }

                deck.displayGrid();
                cout << currentPlayer.get_name() <<"'s turn!: "<<endl;
                currentPlayer.displayScore();
                continue;
            }
            //bonus and standard
            if ((dynamic_cast<BonusCard*>(card1) && dynamic_cast<StandardCard*>(card2)) ||
                (dynamic_cast<BonusCard*>(card2) && dynamic_cast<StandardCard*>(card1))) {
                cout << "Bonus Card and Standard Card!"<<endl;
                currentPlayer.increaseScore(1);
                if (dynamic_cast<StandardCard*>(card1)) {
                    card1->hide();
                    deck.removeCard(x2, y2);
                } else if (dynamic_cast<StandardCard*>(card2)) {
                    card2->hide();
                    deck.removeCard(x1, y1);
                }
                //deck.displayGrid();
                break;
                }
            //bonus and bonus
            if (dynamic_cast<BonusCard*>(card1) && dynamic_cast<BonusCard*>(card2)) {
                cout << "2 Bonus Cards!"<<endl;
                deck.removeCard(x1, y1);
                deck.removeCard(x2, y2);
                char input;
                cout << "+2 (press 'A') |+1 & turn (press 'B')? "<<endl;
                cin >> input;
                if (input == 'A' || input == 'a') {
                    currentPlayer.increaseScore(2);
                } else if (input == 'B' || input == 'b') {
                    currentPlayer.increaseScore(1);
                    continue;
                }
                deck.displayGrid();
                break;
            }

            //penalty and standard
            if ((dynamic_cast<PenaltyCard*>(card1) && dynamic_cast<StandardCard*>(card2)) ||
                (dynamic_cast<PenaltyCard*>(card2) && dynamic_cast<StandardCard*>(card1))) {
                cout << "Penalty Card and Standard Card!"<<endl;
                currentPlayer.decreaseScore(1);
                if (dynamic_cast<StandardCard*>(card1)) {
                    card1->hide();
                    deck.removeCard(x2, y2);
                } else if (dynamic_cast<StandardCard*>(card2)) {
                    card2->hide();
                    deck.removeCard(x1, y1);
                }
                //deck.removeCard(x1, y1);
                //deck.getCard(x2, y2)->hide();
                //deck.getCard(x1, y1)->hide();
                //deck.displayGrid();
                break;
                }

            //penalty and penalty
            if (dynamic_cast<PenaltyCard*>(card1) && dynamic_cast<PenaltyCard*>(card2)) {
                cout << "2 Penalty Cards!"<<endl;
                char input;
                cout << "-2 points (press 'A') | -1 point & skip turn (press 'B')? "<<endl;
                cin >> input;

                if (input == 'A' || input == 'a') {
                    currentPlayer.decreaseScore(2);
                } else if (input == 'B' || input == 'b') {
                    currentPlayer.decreaseScore(1);
                    skipTurn = true;
                }
                deck.removeCard(x1, y1);
                deck.removeCard(x2, y2);
                deck.displayGrid();
                break;
            }
            //bonus and penalty
            if ((dynamic_cast<BonusCard*>(card1) && dynamic_cast<PenaltyCard*>(card2)) ||
               (dynamic_cast<BonusCard*>(card2) && dynamic_cast<PenaltyCard*>(card1))) {
                cout << "Bonus Card and Penalty Card!"<<endl;

                deck.removeCard(x1, y1);
                deck.removeCard(x2, y2);
                break;
               }

            else {
                //standard and standard not matching
                cout << "The cards do not match. Press Enter" <<endl;
                cin.ignore();
                cin.get();
                deck.getCard(x1, y1)->hide();
                deck.getCard(x2, y2)->hide();
                break;
                //deck.displayGrid();
            }
        }
        break;
    }
}

void Game::announceWin(){
    cout << "Finish"<<endl;
    p1.displayScore();
    p2.displayScore();

    if (p1.get_score() > p2.get_score()) {
        cout << p1.get_name() << " wins!"<<endl;
    } else if (p2.get_score() > p1.get_score()) {
        cout << p2.get_name() << " wins!"<<endl;
    } else {
        cout << "Both!"<<endl;
    }
}

Game::~Game() {

    }
