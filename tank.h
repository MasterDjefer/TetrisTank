#ifndef TANK_H
#define TANK_H
#include <QPoint>
#include <QRect>
#include <QDebug>

class Tank : public QPoint
{
protected:
    const int mFormWidth;
    const int mFormHeight;
    const int mSizeBlock;
    int mWhichMove;
    QPoint *mFire;

public:
    Tank(int x, int y, int formWidth, int formHeight, int sizeBlock);
    ~Tank();
    QRect getTank() const;
    int sizeBlock() const;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void fire();
    void fireMove();
    QRect getFire() const;
    bool isGameOver(Tank *tankBot);
};

#endif // TANK_H
