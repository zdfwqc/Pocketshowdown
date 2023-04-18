//
// Created by Administrator on 2023-04-16.
//
#include "../Card/Card.h"
#include <iostream>
#include <random>
#include <vector>
#include<algorithm>

#ifndef GAMEAI_PLAYER_H
#define GAMEAI_PLAYER_H

class player {
private:

public:
    int health = 20;
    int atk = 1;
    int dec = 0;
    int poison = 0;
    int atk_cost = 1;
    std:: vector<Card_h::Card> hold ; //手牌
    std:: vector<Card_h::Card> deck ; //牌库
    std:: vector<Card_h::Card> fold ; //弃牌堆
    bool debug = false;
    player();
    void show(bool showCard);
};

player::player() {
    int i;
    for (i=1;i<=9;i++) {
        Card card = Card(i);
        this->deck.push_back(card);
    }
    std::shuffle(deck.begin(),deck.end(),std::mt19937(std::random_device()()));
    for (i=1;i<=3 ;i++) {
        hold.push_back(deck[0]);
        deck.erase(deck.begin());
    }
}


void player::show(bool showCard) {
    {
        int i;
        printf("Health:");
        for (i=1;i<= this->health;i++) {
            printf("+");
        }
        printf("\n");
        printf("Attack:");
        for (i=1;i<= this->atk;i++) {
            printf("*");
        }
        printf("\n");
        printf("Defence:");
        for (i=1;i<= this->dec;i++) {
            printf("#");
        }
        printf("\n");
        printf("DECK:");
        for(i=1;i<=deck.size();i++) printf("=");
        printf("\n");
        int foldkeep[12] = {};
        for (i=0;i<fold.size();i++) {
            foldkeep[fold[i].getNum()] = 1;
        }
        printf("HOLD:");
        for(i=0;i<hold.size();i++) {
            if (showCard) {
                printf(" |card %d| ",hold[i].getNum());
            }else {
                printf(" |card ? | ");
            }
        }
        printf("\n");
        printf("USED:");
        for (i=1;i<=9;i++) {
            if(foldkeep[i]) {
                printf("|%d|",i);
            }else {
                printf("| - |");
            }
        }
        printf("\n");

    };
}

#endif //GAMEAI_PLAYER_H
