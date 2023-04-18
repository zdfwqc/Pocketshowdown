//
// Created by Administrator on 2023-04-16.
//

#include "../Strategy.h"
#ifndef GAMEAI_RANDOM_STRATEGY_H
#define GAMEAI_RANDOM_STRATEGY_H


class Random_strategy :public Strategy{
public:
    int useCard(Situation s) override{
        return rand() % s.getCurPlayer().hold.size();
    };

     std::map<int,int> usePoint(Situation s,int point) override
    {
        std :: map<int,int> m1;
        m1[0] =0;
        m1[1] = 0;
        m1[2] = 0;
        m1[3] = 0;
        m1[4] = point;
        return m1;
    }
};


#endif //GAMEAI_RANDOM_STRATEGY_H
