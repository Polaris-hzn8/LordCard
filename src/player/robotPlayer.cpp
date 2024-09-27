/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-19 21:07:47
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include "robotPlayer.h"

RobotPlayer::RobotPlayer(QObject *parent) : Player(parent)
{
    m_type = Player::T_Robot;
}

void RobotPlayer::prepareCallLord()
{

}

void RobotPlayer::preparePlayHand()
{

}
