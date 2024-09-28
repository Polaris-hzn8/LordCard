/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:36:16
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "card/cardInfos.h"

class Player : public QObject {
    Q_OBJECT
public:
    enum Sex{ Male, Female };
    enum Role{ Lord, Farmer };
    enum Direction { D_Left, D_Right };
    enum Type { T_Robot, T_User, T_Other };

    explicit Player(QObject *parent = nullptr);
    explicit Player(QString strName, QObject *parent = nullptr);

    void setName(const QString &strName) { m_strName = strName; };
    QString getName() const { return m_strName; };

    Sex getSex() const { return m_sex; };
    void setSex(Sex sex) { m_sex = sex; };

    Role getRole() const { return m_role; };
    void setRole(Role role) { m_role = role; };

    Direction getDirection() const { return m_direction; };
    void setDirection(Direction direction) { m_direction = direction; };

    Type getType() const { return m_type; };
    void setType(Type type) { m_type = type; };

    int getScore() const { return m_score; };
    void setScore(int score) { m_score = score; };

    bool setReult() const { return m_bResult; }
    void setResult(bool result) { m_bResult = result; }

    void setPrevPlayer(Player *pPlayer) { m_pPlayerPrev = pPlayer; }
    Player* getPrevPlayer() { return m_pPlayerPrev; }

    void setNextPlayer(Player *pPlayer) { m_pPlayerNext = pPlayer; }
    Player* getNextPlayer() { return m_pPlayerNext; }

    //抢地主
    void grabLordBet(int point);
    //玩家取牌
    void storeDispatchCard(CardInfo& cardInfo) { m_cardInfos.addInfo(cardInfo); }
    void storeDispatchCard(CardInfos& cardInfos) { m_cardInfos.addInfo(cardInfos); }
    //玩家出牌
    void playHand(CardInfos& cardInfos) { m_cardInfos.removeInfo(cardInfos); }
    //获取玩家所有存储的扑克牌
    CardInfos getCardInfos() { return m_cardInfos; }
    //清空玩家手中的所有扑克牌
    void clearCardInfos() { m_cardInfos.clear(); }

    void setPendPlayer(Player* player) { m_pendPlayer = player; }
    Player* getPendPlayer() { return m_pendPlayer; }
    void setPendCardInfos(CardInfos& cardInfos) { m_pendCardInfos = cardInfos; }
    CardInfos getPendCardInfos() { return m_pendCardInfos; }
public:
    //叫地主
    virtual void prepareCallLord() {};
    //玩家出牌
    virtual void preparePlayHand() {};

protected:
    QString     m_strName;
    Sex         m_sex;
    Role        m_role;
    Direction   m_direction;        //方位
    Type        m_type;             //玩家类型 0 Robot 1 User 2 Other

    int         m_score;            //对局分数
    bool        m_bResult;          //对局结果

    Player*     m_pPlayerPrev;      //上个玩家对象
    Player*     m_pPlayerNext;      //下个玩家对象

    CardInfos   m_pendCardInfos;    //打出扑克牌
    Player*     m_pendPlayer;       //打出扑克牌所有者

    CardInfos   m_cardInfos;        //玩家手中的所有扑克牌
};

#endif // PLAYER_H
