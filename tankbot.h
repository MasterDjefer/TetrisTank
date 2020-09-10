#ifndef TANKBOT_H
#define TANKBOT_H
#include "tank.h"
#include <cstdlib>
#include <ctime>

class TankBot : public Tank
{
public:
    TankBot(int x, int y, int formWidth, int formHeight, int sizeBlock);
    void moveRand();
};

#endif // TANKBOT_H
