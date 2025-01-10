//
// Created by manso on 11/19/2024.
//

#ifndef STANDARDCARD_H
#define STANDARDCARD_H

#include <iostream>
using namespace std;
#include "Card.h"


class StandardCard : public Card {
public :
    StandardCard(int data);
    void display() override;
    ~StandardCard();
    StandardCard()=default;
};

#endif //STANDARDCARD_H
