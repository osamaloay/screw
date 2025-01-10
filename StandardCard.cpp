//
// Created by Manuel Kevorkian on 14/12/2024.
//
#include "StandardCard.h"
#include <iostream>
using namespace std;


StandardCard::StandardCard(int data) : Card(data) {

}

void StandardCard::display() {
    Card::display();
}

StandardCard::~StandardCard() {

}
