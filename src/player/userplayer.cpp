/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-19 21:17:57
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include "userplayer.h"

UserPlayer::UserPlayer(QObject *parent) : Player(parent)
{
    m_type = Player::T_User;
}

void UserPlayer::prepareCallLord()
{

}

void UserPlayer::preparePlayHand()
{

}
