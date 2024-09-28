/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-22 13:21:45
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include "gamecontroller.h"
#include "QRandomGenerator"

GameController::GameController(QObject *parent) : QObject(parent)
{

}

void GameController::playerInit()
{
    //玩家对象实例化
    m_rRobotPlayer = new RobotPlayer("robot_a", this); //指定父对象 自动释放
    m_lRobotPlayer = new RobotPlayer("robot_b", this);
    m_userPlayer = new UserPlayer("userPlayer", this);

    //玩家头像显示位置
    m_rRobotPlayer->setDirection(Player::D_Right);
    m_lRobotPlayer->setDirection(Player::D_Left);
    m_userPlayer->setDirection(Player::D_Right);

    //玩家性别设置
    Player::Sex sex;
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_rRobotPlayer->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_lRobotPlayer->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_userPlayer->setSex(sex);

    //玩家出牌顺序设置为顺时针出牌
    m_userPlayer->setNextPlayer(m_lRobotPlayer);
    m_userPlayer->setPrevPlayer(m_rRobotPlayer);

    m_rRobotPlayer->setNextPlayer(m_userPlayer);
    m_rRobotPlayer->setPrevPlayer(m_lRobotPlayer);

    m_lRobotPlayer->setNextPlayer(m_rRobotPlayer);
    m_lRobotPlayer->setPrevPlayer(m_userPlayer);

    //设置初始状态当前玩家
    m_currPlayer = m_userPlayer;
}

void GameController::cardInfoInit()
{
    m_allCardInfos.clear();
    //普通扑克牌
    for (int point = CardInfo::CardPoint::Card_Begin + 1; point < CardInfo::Card_SJ; ++point) {
        for (int suit = CardInfo::Card_Begin + 1; suit < CardInfo::Card_End; ++suit) {
            CardInfo cardInfo((CardInfo::CardPoint)point, (CardInfo::CardSuit)suit);
            m_allCardInfos.addInfo(cardInfo);
        }
    }
    //Joker初始化
    m_allCardInfos.addInfo(CardInfo(CardInfo::Card_SJ, CardInfo::Suit_Begin));
    m_allCardInfos.addInfo(CardInfo(CardInfo::Card_BJ, CardInfo::Suit_Begin));
}

CardInfo GameController::dispatchCardInfo()
{
    return m_allCardInfos.getRandCardInfo();
}

CardInfos GameController::dispatchRemainCardInfos()
{
    return m_allCardInfos;
}

void GameController::resetAdllCardInfos()
{
    cardInfoInit();
    m_rRobotPlayer->clearCardInfos();
    m_lRobotPlayer->clearCardInfos();
    m_userPlayer->clearCardInfos();

    m_pendPlayer = nullptr;
    m_pendCardInfos.clear();
}

void GameController::startLordElection()
{
    // m_currPlayer->prepareCallLord();
}

void GameController::startLordConfirm(Player* player)
{
    player->setRole(Player::Lord);
    player->getNextPlayer()->setRole(Player::Farmer);
    player->getPrevPlayer()->setRole(Player::Farmer);

    CardInfos remainCardInfos = dispatchRemainCardInfos();
    player->storeDispatchCard(remainCardInfos);

    m_currPlayer = player;

    m_currPlayer->preparePlayHand();
}
void GameController::resetScore()
{
    m_rRobotPlayer->setScore(0);
    m_lRobotPlayer->setScore(0);
    m_userPlayer->setScore(0);
}

