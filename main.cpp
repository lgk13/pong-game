#include <QApplication>
#include <QMessageBox>
#include "gameplay.h"
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gameplay * game = new Gameplay();

    return a.exec();
}
