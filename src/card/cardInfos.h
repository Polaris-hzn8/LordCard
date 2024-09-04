/*************************************************************************
    > File Name: cards.h
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2024-03-13 07:59:26
************************************************************************/

#ifndef CARDS_H
#define CARDS_H

#include <QSet>
#include "cardInfo.h"

class CardInfos
{
public:
    CardInfos();

    // 扑克牌数据添加 发牌
    void increase(CardInfo& cardInfo);
    void increase(CardInfos& CardInfos);
    // 一次性插入多个数据 重载操作符<<
    CardInfos &operator<<(CardInfo& cardInfo);
    CardInfos &operator<<(CardInfos& CardInfos);

    // 扑克牌数据删除 出牌
    void decrease(CardInfo& cardInfo);
    void decrease(CardInfos& CardInfos);



private:
    QSet<CardInfo> m_CardInfos;
};

#endif // CARDS_H
