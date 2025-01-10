//
// Created by manso on 11/19/2024.
//


#ifndef PENALTYCARD_H
#define PENALTYCARD_H
#include <iostream>
#include "Card.h"
using namespace std;
class PenaltyCard :public Card {
private:
    int deduct;
public :
    PenaltyCard(int data,int deduct);
    void display() override;
    ~PenaltyCard();
    void set_deduct(int deduct);
    int get_deduct();
    PenaltyCard()=default;
};


#endif //PENALTYCARD_H
