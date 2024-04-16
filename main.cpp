/*************************************************************************
    > File Name: main.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 19:05:54
************************************************************************/

#include "panel/gamepanel.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GamePanel w;
    w.show();
    return a.exec();
}
