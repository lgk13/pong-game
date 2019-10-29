#include "paddle.h"
#include <QBrush>

Paddle::Paddle()
{
    setRect(0, 0, PADDLE_WIDTH, PADDLE_HEIGHT);
    setBrush((QBrush)Qt::black);
}

void Paddle::move(Paddle::MoveType moveType)
{
    if(validMove(moveType) && moveType == UP)
        moveBy(0,-m_moveStep);
    else if(validMove(moveType) && moveType == DOWN)
        moveBy(0, m_moveStep);
}

void Paddle::randomMove(qreal ballY)
{
    if ((y()-ballY )>=15  || (y()-ballY)<= - 15)
    {
        MoveType m = ((y() - ballY) > -15) ? UP : DOWN;
        move(m);

    }
}

void Paddle::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
    case Qt::Key_Up:
        move(UP);

        break;
    case Qt::Key_Down:
        move(DOWN);

        break;
    default:
        break;
    }
}

bool Paddle::validMove(Paddle::MoveType moveType)
{
    if(moveType == UP) return (y() - m_moveStep) >= 0;
    else if(moveType == DOWN) return (y() + m_moveStep) <=520;
    else return false;
}

