/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-19 21:08:24
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H

#include <QObject>
#include "player.h"

class RobotPlayer : public Player
{
    Q_OBJECT
public:
    using Player::Player;//继承构造函数
    explicit RobotPlayer(QObject *parent = nullptr);
    void prepareCallLord() override;
    void preparePlayHand() override;
};

#endif // ROBOTPLAYER_H
