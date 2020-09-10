#include "tankbot.h"

TankBot::TankBot(int x, int y, int formWidth, int formHeight, int sizeBlock) :
    Tank(x, y, formWidth, formHeight, sizeBlock)
{

}

void TankBot::moveRand()
{
    int r = rand() % 4 + 1;

    switch(r)
    {
        case 1:
            moveLeft();
            break;
        case 2:
            moveUp();
            break;
        case 3:
            moveRight();
            break;
        case 4:
            moveDown();
            break;
        default:
            break;
    }
}
