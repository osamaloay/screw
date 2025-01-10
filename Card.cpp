//
// Created by Manuel Kevorkian on 14/12/2024.
//
#include "Card.h"

#include <iostream>

#include "BonusCard.h"
#include "PenaltyCard.h"
using namespace std;

Card::Card(int data) {
    this->data = data;
    isup = false;
}
int Card::get_data() {
    return this->data;
}

bool Card::get_status() {
    return this->isup;
}

void Card::toggle() {
    isup = !isup;
}
void Card::display() {
    if (this->data==-1) {
        std::cout << " ";
    } else if (!isup) {
        std::cout << "*";
    } else {
        std::cout << data;
    }
}
Card::~Card() {

}
void Card::hide() {
    isup = false;
}
void Card::reveal() {
    isup = !isup;
}
bool Card::isMatch(Card* other) {
     if (!other || dynamic_cast<PenaltyCard*>(other) || dynamic_cast<BonusCard*>(other)) {
      return false;
   }
   return (this->data == other->get_data());
}