/*************************************************************************
    > File Name: gamepanel.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 19:05:35
************************************************************************/

#include "gamepanel.h"
#include "ui_gamepanel.h"

GamePanel::GamePanel(QWidget *parent):QMainWindow(parent), ui(new Ui::GamePanel) {
    ui->setupUi(this);
}

GamePanel::~GamePanel() {
    delete ui;
}

