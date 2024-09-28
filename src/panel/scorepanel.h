/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-29 00:53:05
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef SCOREPANEL_H
#define SCOREPANEL_H

#include <QWidget>

namespace Ui {
class ScorePanel;
}

class ScorePanel : public QWidget
{
    Q_OBJECT

public:
    explicit ScorePanel(QWidget *parent = nullptr);
    ~ScorePanel();

private:
    Ui::ScorePanel *ui;
};

#endif // SCOREPANEL_H
