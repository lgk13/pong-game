#ifndef PADDLE_H
#define PADDLE_H
#include "config.h"

#include<QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>


class Paddle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Paddle();
    void keyPressEvent(QKeyEvent *event);
    enum MoveType {UP, DOWN};
    Q_ENUM(MoveType)
    bool validMove(MoveType moveType);
    void move(MoveType moveType);
    void randomMove(qreal ballY);

protected:
    int m_moveStep = 15 ;

};

#endif // PADDLE_H
