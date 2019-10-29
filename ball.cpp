#include "ball.h"
#include "config.h"

#include <QBrush>
#include <QTimer>
#include <QList>

Ball::Ball()
{

    setRect(0, 0, BALL_WIDTH, BALL_HEIGHT);
    setBrush((QBrush)Qt::darkBlue);
    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000/35);

    dx = -1;
    dy = -1;
    m_speed = 12;
    angle = 0;
    c_stop=false;
    score1 = 0;
    score2 = 0;

}


void Ball::setPaddles(Paddle *player, Paddle *computer)
{
    m_player = player;
    m_computer = computer;
}

bool Ball::insideBoard()
{
    if (x()>BALL_WIDTH/2+PADDLE_WIDTH/2 && x()<BOARD_WIDTH - BALL_WIDTH-PADDLE_WIDTH/2)
    return true;
}


int Ball::speed()
{
    return m_speed;
}

void Ball::move()
{
//    if( score1==1) timer->stop();
    //шарик сталкивается с ракеткой
    if(collidesWithItem(m_computer) || collidesWithItem(m_player)){
        if(collidesWithItem(m_computer)) c_stop=true;
        if(collidesWithItem(m_player)) c_stop=false;
        dx = -dx ;
        angle = (rand()%4+1) *0.25;
        int k = rand()%4;
        if(dy == 0.0) {dy=(rand()%3-1);}
        else if(k == 0) dy = (rand()%3-1);

    }
    //шарик ударяется об верхнюю или нижнюю стену поля
    else if(y()>=BOARD_HEIGHT - BALL_HEIGHT || y()<=BALL_HEIGHT) {
        dy = -dy;
    }
    else if(x()<BALL_WIDTH){addScore(1);}
    else if(x()> BOARD_WIDTH - BALL_WIDTH){addScore(2);}
    moveBy(m_speed * dx, m_speed * dy*angle);
    if(!c_stop) m_computer->randomMove(y());
}

void Ball::addScore(int score){
    switch (score) {
     case 1:
        score1++;
        break;
     case 2:
        score2++;
        break;
    }
timer->stop();
if(score1!=5 || score2!=5) {
QTimer::singleShot(2000,timer,SLOT(start()));
setPos(BOARD_WIDTH/2.0,BOARD_HEIGHT/2.0);
dx =-dx;
dy =(rand()%3-1);
angle =1;
c_stop = false;
}
}

