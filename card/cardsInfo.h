/*************************************************************************
    > File Name: cards.h
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2024-03-13 07:59:26
************************************************************************/

#ifndef CARDS_H
#define CARDS_H

#include <QSet>
#include "card/cardinfo.h"

class CardsInfo
{
public:
    CardsInfo();

    // 扑克牌数据添加 发牌
    void increase(CardInfo& cardInfo);
    void increase(CardsInfo& cardsInfo);
    // 一次性插入多个数据 重载操作符<<
    CardsInfo& operator<<(const CardInfo& cardInfo);
    CardsInfo& operator<<(const CardsInfo& cardsInfo);

    // 扑克牌数据删除 出牌
    void decrease(CardInfo& cardInfo);
    void decrease(CardsInfo& cardsInfo);



private:
    QSet<CardInfo> m_cardsInfo;
};

#endif // CARDS_H
