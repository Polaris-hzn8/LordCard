/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:35:02
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef CARDS_H
#define CARDS_H

#include "cardInfo.h"

class CardInfos
{
public:
    enum SortType {
        ST_ASC,
        ST_DESC,
        ST_NOSORT
    };
public:
    CardInfos();

    // 扑克牌数据添加 发牌
    void addInfo(const CardInfo& cardInfo);
    void addInfo(const CardInfos& CardInfos);

    // 扑克牌数据删除 出牌
    void removeInfo(CardInfo& cardInfo);
    void removeInfo(CardInfos& CardInfos);

    // 将多条数据存储到对象中 借鉴cout输出 重载操作符<<
    CardInfos& operator<<(const CardInfo& cardInfo);
    CardInfos& operator<<(const CardInfos& CardInfos);
public:
    // 卡牌集合操作1
    bool empty() { return m_cardSet.empty(); }
    void clear() { return m_cardSet.clear(); }
    int count() { return m_cardSet.size(); }

    // 卡牌集合操作2
    CardInfo::CardPoint getMinPoint();
    CardInfo::CardPoint getMaxPoint();

    int countPoint(const CardInfo::CardPoint point);
    bool cardExist(const CardInfo cardInfo);
    bool cardsExist(const CardInfos cardInfos);

    // 卡牌集合操作3
    CardInfo getRandCardInfo();    // 随机发牌

    CardList reArrangeCardInfo(SortType sortType = ST_DESC);  // 卡牌排序

private:
    CardSet m_cardSet;//存储数据
};

#endif // CARDS_H


