#include "widget.h"

Widget::Widget()
{
    int sizeBlock = 40;
    this->setFixedSize(sizeBlock * 12, sizeBlock * 20);

    mMyTank = new Tank(0, 0, this->width(), this->height(), sizeBlock);
    mTankBot = new TankBot(this->width() / 2, this->height() / 2, this->width(),
                           this->height(), sizeBlock);

    connect(&mTimerBotMove, &QTimer::timeout, this, &Widget::onTimeOutBotMove);
    mTimerBotMove.start(1000);

    connect(&mTimerFireMove, &QTimer::timeout, this, &Widget::onTimeOutFireMove);
    mTimerFireMove.start(10);
}

Widget::~Widget()
{
    delete mMyTank;
    delete mTankBot;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(mMyTank->getTank());

    painter.setBrush(QBrush(Qt::blue));
    painter.drawRect(mTankBot->getTank());

    painter.setBrush(QBrush(Qt::yellow));
    painter.drawRect(mMyTank->getFire());
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_4:
            mMyTank->moveLeft();
            break;
        case Qt::Key_6:
            mMyTank->moveRight();
            break;
        case Qt::Key_8:
            mMyTank->moveUp();
            break;
        case Qt::Key_2:
            mMyTank->moveDown();
            break;
        case Qt::Key_5:
            mMyTank->fire();
            break;
        default:
            break;
    }
    if (mMyTank->isGameOver(mTankBot))
    {
        this->close();
    }

    this->update();
}

void Widget::onTimeOutBotMove()
{
    mTankBot->moveRand();
    if (mMyTank->isGameOver(mTankBot))
    {
        this->close();
    }

    this->update();
}

void Widget::onTimeOutFireMove()
{
    mMyTank->fireMove();

    this->update();
}
