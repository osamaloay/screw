//
// Created by manso on 11/19/2024.
//

#ifndef BONUSCARD_H
#define BONUSCARD_H

#include "Card.h"
#include <iostream>
using namespace std;
class BonusCard :public Card{
private:
    int bonus;
public :
    BonusCard(int data,int bonus);
    void display() override;
    ~BonusCard();
    int get_bonus();
    void set_bonus(int bonus);
    BonusCard()=default;
};

#endif //BONUSCARD_H
