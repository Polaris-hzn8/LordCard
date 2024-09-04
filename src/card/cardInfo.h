/*************************************************************************
    > File Name: cardinfo.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 20:01:04
************************************************************************/

#ifndef CARDINFO_H
#define CARDINFO_H

//卡牌花色
enum CardSuit {
    Diamond,    //方块
    Club,       //梅花
    Heart,      //红桃
    Spade       //黑桃
};

//卡牌点数
enum CardPoint {
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
    Card_BJ     //Joker Heart
};

class CardInfo {
public:
    CardInfo();
    // 设置花色信息
    void setSuit(CardSuit suit) { m_suit = suit; }
    // 获取花色信息
    CardSuit getSuit() { return m_suit; }
    // 设置点数信息
    void setPoint(CardPoint point) { m_point = point; }
    // 获取点数信息
    CardPoint getPoint() { return m_point; }
private:
    CardSuit m_suit;     //卡牌花色
    CardPoint m_point;   //卡牌点数
};

#endif // CARDINFO_H
