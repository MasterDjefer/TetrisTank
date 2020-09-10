#ifndef WIDGET_H
#define WIDGET_H
#include "tank.h"
#include "tankbot.h"
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();
    ~Widget();

private:
    Tank *mMyTank;
    TankBot *mTankBot;
    QTimer mTimerBotMove;
    QTimer mTimerFireMove;

private:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void onTimeOutBotMove();
    void onTimeOutFireMove();

};

#endif // WIDGET_H
