#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include "paddle.h"

class Ball: public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    Ball();
    void setPaddles(Paddle *player, Paddle *computer);
    bool insideBoard();
    int speed();
    bool c_stop;

    QTimer * timer;

    int score1, score2;
    void addScore(int score);

public slots:
    void move();

private:
    Paddle *m_player;
    Paddle *m_computer;
    qreal dx, dy, m_speed, angle;
};

#endif // BALL_H
