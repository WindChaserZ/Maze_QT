#include "play_maze.h"
#include <QApplication>
#include <QIcon>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString atrPATH=QApplication::applicationDirPath();
    atrPATH+="/img/df.png";
    a.setWindowIcon(QIcon(atrPATH));

    play_maze w;
    w.show();

    return a.exec();
}
