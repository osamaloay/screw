//
// Created by Manuel Kevorkian on 14/12/2024.
//
#include "PenaltyCard.h"
#include <iostream>
using namespace std;


PenaltyCard::PenaltyCard(int data, int deduct) : Card(data) {
    this->deduct = deduct;
}

int PenaltyCard::get_deduct() {
    return this->deduct;
}

void PenaltyCard::set_deduct(int deduct) {
    this->deduct = deduct;
}

void PenaltyCard::display() {
    if (!this->get_status()) {
        cout << "*";
    } else {
        cout <<"P";
    }
}

PenaltyCard::~PenaltyCard() {

}
