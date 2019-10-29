#include "gameplay.h"
#include "config.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "paddle.h"
#include "ball.h"


Gameplay::Gameplay()
{

    // create a game scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, BOARD_WIDTH, BOARD_HEIGHT);
    scene->setBackgroundBrush(Qt::white);

    // add game objects
    Paddle *player = new Paddle();
    player->setPos(0, ( BOARD_HEIGHT / 2.0) - PADDLE_HEIGHT);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    Paddle *computer = new Paddle();
    computer->setPos(BOARD_WIDTH - PADDLE_WIDTH , ( BOARD_HEIGHT / 2) - PADDLE_HEIGHT);

    Ball *ball = new Ball();
    ball->setPaddles(player, computer);
    ball->setPos(BOARD_WIDTH/2.0,BOARD_HEIGHT/2.0);


    scene->addItem(player);
    scene->addItem(computer);
    scene->addItem(ball);
    scene->addRect(0,0,BOARD_WIDTH,BOARD_HEIGHT);



    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setGeometry(0, 0, BOARD_WIDTH,  BOARD_HEIGHT);
    view->show();
}

