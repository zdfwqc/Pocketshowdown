//
// Created by Administrator on 2023-04-16.
//

#include "../Strategy.h"
#ifndef GAMEAI_USER_STRATEGY_H
#define GAMEAI_USER_STRATEGY_H


class User_strategy : public Strategy{
public:
    int useCard(Situation s)  override{
        system("cls");
        int a;
        s.show();
        printf("Choose card to use\n");
        scanf("%d",&a);
        return a;
    };

    std::map<int,int> usePoint(Situation s,int point) override
    {
        system("cls");
        int a,b;
        std :: map<int,int> m1;
        s.show();
        printf("Choose Point to use\n");
        printf("a-b mean use b points in a\n");
        printf("1->ack 2->dec 3->cure 4->damage\n");
        while (point >=0) {
            scanf("%d-%d",&a,&b);
            if (b > point) {
                printf("error! retry!\n");
                continue;
            }
            m1[a] = b;
            point -= b;
            printf("use success!");
        }


        return m1;
    }
};


#endif //GAMEAI_USER_STRATEGY_H
