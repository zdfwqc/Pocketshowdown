//
// Created by Administrator on 2023-04-16.
//
#include "../Situation/Situation.h"
#include <map>
#ifndef GAMEAI_STRATEGY_H
#define GAMEAI_STRATEGY_H


class Strategy {
public:
    virtual int useCard(Situation s) = 0;
    virtual std::map<int,int> usePoint(Situation s,int point)=0;
};


#endif //GAMEAI_STRATEGY_H
