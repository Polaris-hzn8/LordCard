/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:35:31
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef CARDINFO_H
#define CARDINFO_H

#include <QSet>
#include <QVector>

class CardInfo {
public:
    //卡牌花色
    enum CardSuit {
        Suit_Begin,
        Diamond,    //方块
        Club,       //梅花
        Heart,      //红桃
        Spade,       //黑桃
        Suit_End
    };
    //卡牌点数
    enum CardPoint {
        Card_Begin,
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
        Card_SJ,    //Joker Spade
        Card_BJ,    //Joker Heart
        Card_End
    };
public:
    CardInfo();
    // 设置花色信息
    void setSuit(CardSuit suit) { m_suit = suit; }
    // 获取花色信息
    CardSuit getSuit() const { return m_suit; }
    // 点数信息设置
    void setPoint(CardPoint point) { m_point = point; }
    // 获取点数信息
    CardPoint getPoint() const { return m_point; }
private:
    CardSuit m_suit;     //卡牌花色
    CardPoint m_point;   //卡牌点数
};

using CardSet = QSet<CardInfo>;
using CardList = QVector<CardInfo>;

bool lessSort(const CardInfo &info_a, const CardInfo &info_b);
bool greaterSort(const CardInfo &info_a, const CardInfo &info_b);

//操作符重载
bool operator==(const CardInfo &info_a, const CardInfo &info_b);
//重写全局函数qHash
uint qHash(const CardInfo &info);

#endif // CARDINFO_H
