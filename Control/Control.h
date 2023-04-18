//
// Created by Administrator on 2023-04-16.
//

#include "../Situation/Situation.h"
#include "../Strategy/Strategy.h"
#include "../Strategy/Random_strategy/Random_strategy.h"
#include "../Strategy/User_strategy/User_strategy.h"
#include<ctime>
#include<windows.h>
#ifndef GAMEAI_CONTROL_H
#define GAMEAI_CONTROL_H

class Controller {
private:
    bool debug = true;
    Situation s;
    Strategy* strategys[2]{};
    int cardNum[2]{};
public:
    Controller(){
      s = Situation();
      strategys[0] = new User_strategy();
      strategys[1] = new Random_strategy();
    };
    void twiceExecute(void func(Controller* controller));
    void run();
    Strategy* getCurStrategy(){
        return strategys[s.curPlayer];
    }
};

void Controller :: twiceExecute(void func(Controller* controller)) {
    func(this);
    s.changePlayer();
    func(this);
    s.changePlayer();
}

void Controller::run() {
    Random_strategy B = Random_strategy();
    User_strategy A = User_strategy();
    if (debug) {
        printf("init_end\n");
    }
    while (1)
    {
        s.show();//
        twiceExecute([](Controller* controller){ controller->cardNum[controller->s.curPlayer] = controller->getCurStrategy()->useCard(controller->s);});

        printf("%d %d",cardNum[0],cardNum[1]);
        /*
        Card tem = s.getCurPlayer().hold[x];
        s.getCurPlayer().fold.push_back(tem);
        s.getCurPlayer().hold.erase(x+s.getCurPlayer().hold.begin());

        tem = s.getOtherPlayer().hold[y];
        s.getOtherPlayer().fold.push_back(tem);
        s.getOtherPlayer().hold.erase(y+s.getOtherPlayer().hold.begin());

        printf("Player A Use Card Num %d\n",x);
        printf("Player B Use Card Num %d\n",y);
         */
        Sleep(1000);
        system("cls");
        s.show();

        break;
    }
}

#endif //GAMEAI_CONTROL_H
