//
// Created by Administrator on 2023-04-16.
//
#include "Player.h"
#ifndef GAMEAI_SITUATION_H
#define GAMEAI_SITUATION_H

class Situation {
public:
    // 注意 局面要对策略隐藏，所以所有属性都是private
    player players[2];
    int curPlayer = 0 ;
    player getCurPlayer(){
        return players[curPlayer];
    }
    player getOtherPlayer() {
        return players[1-curPlayer];
    }
    void changePlayer() {
        curPlayer = 1- curPlayer;
    }

public:
    Situation(){
        players[0] = player();
        players[1] = player();
    };
    void show() {
        printf("________OTHER____PLAYER_________\n");
        getOtherPlayer().show(false);
        printf("______________YOU_______________\n");
        getCurPlayer().show(true);
    }


};


#endif //GAMEAI_SITUATION_H
