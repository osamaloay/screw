//
// Created by manso on 11/19/2024.
//

#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
class Card {
private:
    bool isup;
    int data;
public:
    Card(int data);
    virtual void display() ;
    virtual bool isMatch(Card* other);
    bool get_status();
    int get_data();
    virtual ~Card();
    void toggle();
    Card()=default;

    void reveal();
    void hide();

};

#endif //CARD_H
