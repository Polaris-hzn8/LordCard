/*************************************************************************
    > File Name: cardinfo.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 20:01:04
************************************************************************/

#ifndef CARDINFO_H
#define CARDINFO_H

enum CardSuit {
    Diamond,        //方块
    Club,           //梅花
    Heart,          //红桃
    Spade           //黑桃
};

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
    Card_SJ,        //Joker Spade
    Card_BJ         //Joker Heart
};

class CardInfo {
public:
    CardInfo();
    void setSuit(CardSuit suit) { _suit = suit; }
    CardSuit suit() { return _suit; }
    void setPoint(CardPoint point) { _point = point; }
    CardPoint point() { return _point; }
private:
    CardSuit _suit;
    CardPoint _point;
};

#endif // CARDINFO_H

