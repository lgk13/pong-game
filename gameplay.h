#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include "ball.h"
#include "paddle.h"


class Gameplay : public QObject
{
    Q_OBJECT

public:
    Gameplay();
};

#endif // MAINWINDOW_H
