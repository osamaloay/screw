//
// Created by Manuel Kevorkian on 14/12/2024.
//
#include "BonusCard.h"
#include <iostream>
using namespace std;

BonusCard::BonusCard(int data, int bonus) : Card(data) {
    this->bonus = bonus;
}

int BonusCard::get_bonus() {
    return this->bonus;
}

void BonusCard::set_bonus(int bonus) {
    this->bonus = bonus;
}

void BonusCard::display() {
    if (!this->get_status()) {
        cout << "*";
    } else {
        cout << "B";
    }
}

BonusCard::~BonusCard() {}
