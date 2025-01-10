//
// Created by manso on 11/20/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
#include <string>
class Player {
private:
    string name;
    int score;
public:
    Player(string name);
    void displayScore();
    ~Player();
    Player()=default;
    void set_name(string name) ;
    string get_name();
    int get_score();
    void set_score(int score);


    void increaseScore(int points);
    void decreaseScore(int points);
};

#endif //PLAYER_H
