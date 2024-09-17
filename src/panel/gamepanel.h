/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:36:01
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GamePanel; }
QT_END_NAMESPACE

class GamePanel : public QMainWindow {
    Q_OBJECT
public:
    GamePanel(QWidget *parent = nullptr);
    ~GamePanel();
private:
    Ui::GamePanel *ui;
};

#endif // GAMEPANEL_H
