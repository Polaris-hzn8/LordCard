/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-22 13:21:31
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "player/robotPlayer.h"
#include "player/userplayer.h"
#include "card/cardInfos.h"

class GameController : public QObject
{
    Q_OBJECT
    enum GameStatus {
        GS_CardDispatch,    //发牌状态
        GS_LordElection,    //地主选举
        GS_CardPlaying,     //玩家出牌中
        GS_GameOver         //游戏结束
    };
    enum PlayerStatus {
        PS_LordGrabing,        //抢地主中
        PS_CardSelecting,      //出牌中
        PS_GameOver             //游戏结束
    };
public:
    explicit GameController(QObject *parent = nullptr);

    void playerInit();          //玩家初始化
    void cardInfoInit();        //扑克牌初始化

    //玩家相关操作
    RobotPlayer*    getLeftPlayer() { return m_lRobotPlayer; }
    RobotPlayer*    getRightPlayer() { return m_rRobotPlayer; }
    UserPlayer*     getMiddlePlayer() { return m_userPlayer; }

    Player*         getCurrPlayer() { return m_currPlayer; }
    void            setCurrPlayer(Player* player) { m_currPlayer = player; }

    Player*         getPendPlayer() { return m_pendPlayer; }
    void            setPendPlayer(Player* player) { m_pendPlayer = player; }

    CardInfos       getPendCardInfos() { return m_pendCardInfos; }
    void            setPendCardInfos(CardInfos& cardInfos) { m_pendCardInfos = cardInfos; }

    //扑克牌相关操作
    CardInfo        dispatchCardInfo();
    CardInfos       dispatchRemainCardInfos();

    void            resetAdllCardInfos();

private:
    RobotPlayer*    m_lRobotPlayer;
    RobotPlayer*    m_rRobotPlayer;
    UserPlayer*     m_userPlayer;

    Player*         m_currPlayer;

    Player*         m_pendPlayer;
    CardInfos       m_pendCardInfos;

    CardInfos       m_allCardInfos;//所有卡牌集合
};

#endif // GAMECONTROLLER_H
