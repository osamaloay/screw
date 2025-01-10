//
// Created by Manuel Kevorkian on 14/12/2024.
//
#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(string name) {
    this->name = name;
    this->score = 0;
}

string Player::get_name() {
    return this->name;
}

void Player::set_name(string name) {
    this->name = name;
}

int Player::get_score() {
    return this->score;
}

void Player::set_score(int score) {
    this->score = score;
}

void Player::displayScore() {
    cout << this->name << " Score = " << this->get_score()<<endl;
}

Player::~Player() {}


void Player::increaseScore(int points) {
    score += points;
}

void Player::decreaseScore(int points) {
    score -= points;
    if (score < 0) {
        score = 0;
    }
}