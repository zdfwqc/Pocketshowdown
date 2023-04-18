#include <iostream>
#include "Control/Control.h"
int main()
{
    srand(time(0));
   Controller controller = Controller();
   controller.run();

}