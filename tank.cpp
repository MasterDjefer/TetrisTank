#include "tank.h"

Tank::Tank(int x, int y, int formWidth, int formHeight, int sizeBlock) : QPoint(x, y),
    mFormWidth(formWidth), mFormHeight(formHeight), mSizeBlock(sizeBlock),
    mWhichMove(3), mFire(nullptr)
{

}

Tank::~Tank()
{
    delete mFire;
}

QRect Tank::getTank() const
{
    return QRect(this->x(), this->y(), mSizeBlock, mSizeBlock);
}

int Tank::sizeBlock() const
{
    return mSizeBlock;
}

void Tank::moveUp()
{
    if (this->y() - mSizeBlock >= 0)
    {
        this->setY(this->y() - mSizeBlock);
    }
    if (!mFire)
        mWhichMove = 2;
}

void Tank::moveDown()
{
    if (this->y() + mSizeBlock < mFormHeight)
    {
        this->setY(this->y() + mSizeBlock);
    }
    if (!mFire)
        mWhichMove = 4;
}

void Tank::moveLeft()
{
    if (this->x() - mSizeBlock >= 0)
    {
        this->setX(this->x() - mSizeBlock);
    }
    if (!mFire)
        mWhichMove = 1;
}

void Tank::moveRight()
{
    if (this->x() + mSizeBlock < mFormWidth)
    {
        this->setX(this->x() + mSizeBlock);
    }
    if (!mFire)
        mWhichMove = 3;
}

void Tank::fire()
{
    if (!mFire)
    {
        mFire = new QPoint(this->x(), this->y());
    }
}

QRect Tank::getFire() const
{
    if (!mFire)
        return QRect(0, 0, 0, 0);

    return QRect(mFire->x(), mFire->y(), mSizeBlock, mSizeBlock);
}

bool Tank::isGameOver(Tank *tankBot)
{
    if (tankBot->x() == this->x() && tankBot->y() == this->y())
        return true;
    return false;
}

void Tank::fireMove()
{
    if (!mFire)
        return;

    switch(mWhichMove)
    {
        case 1:
            mFire->setX(mFire->x() - 10);
            break;
        case 2:
            mFire->setY(mFire->y() - 10);
            break;
        case 3:
            mFire->setX(mFire->x() + 10);
            break;
        case 4:
            mFire->setY(mFire->y() + 10);
            break;
        default:
            break;
    }

    if (mFire->x() > mFormWidth || mFire->x() + mSizeBlock < 0 ||
        mFire->y() > mFormHeight || mFire->y() + mSizeBlock < 0)
    {
        delete mFire;
        mFire = nullptr;
    }
}
