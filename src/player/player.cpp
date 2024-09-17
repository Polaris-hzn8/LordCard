/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:36:10
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include "player.h"

Player::Player(QObject *parent) : QObject(parent) {

}

Player::Player(QString strName, QObject *parent)
{
    m_strName = strName;
}

