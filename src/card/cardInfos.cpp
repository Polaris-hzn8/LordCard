/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:35:20
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include <QRandomGenerator>
#include "cardInfos.h"

CardInfos::CardInfos()
{

}

void CardInfos::addInfo(const CardInfo& cardInfo)
{
    m_cardSet.insert(cardInfo);
}

void CardInfos::addInfo(const CardInfos& cardInfos)
{
    m_cardSet.unite(cardInfos.m_cardSet);
}

void CardInfos::removeInfo(CardInfo& cardInfo)
{
    m_cardSet.remove(cardInfo);
}

void CardInfos::removeInfo(CardInfos& cardInfs)
{
    m_cardSet.subtract(cardInfs.m_cardSet);
}

CardInfos &CardInfos::operator<<(const CardInfo& cardInfo)
{
    addInfo(cardInfo);
    return *this;
}

CardInfos &CardInfos::operator<<(const CardInfos &cardInfos)
{
    addInfo(cardInfos);
    return *this;
}

CardInfo::CardPoint CardInfos::getMinPoint()
{
    CardInfo::CardPoint minPoint = CardInfo::CardPoint::Card_End;
    if (!m_cardSet.empty()) {
        for (auto it = m_cardSet.begin(); it != m_cardSet.end(); ++it) {
            CardInfo::CardPoint tmpPoint = it->getPoint();
            if (tmpPoint < minPoint) {
                minPoint = tmpPoint;
            }
        }
    }
    return minPoint;
}

CardInfo::CardPoint CardInfos::getMaxPoint()
{
    CardInfo::CardPoint maxPoint = CardInfo::CardPoint::Card_Begin;
    if (!m_cardSet.empty()) {
        for (auto it = m_cardSet.begin(); it != m_cardSet.end(); ++it) {
            CardInfo::CardPoint tmpPoint = it->getPoint();
            if (tmpPoint > maxPoint) {
                maxPoint = tmpPoint;
            }
        }
    }
    return maxPoint;
}

int CardInfos::countPoint(const CardInfo::CardPoint point)
{
    int nCardNum = 0;
    if (!m_cardSet.empty()) {
        for (auto it = m_cardSet.begin(); it != m_cardSet.end(); ++it) {
            CardInfo::CardPoint tmpPoint = it->getPoint();
            if (tmpPoint == point) {
                nCardNum++;
            }
        }
    }
    return nCardNum;
}

bool CardInfos::cardExist(const CardInfo cardInfo)
{
    return m_cardSet.contains(cardInfo);
}

bool CardInfos::cardsExist(const CardInfos cardInfos)
{
    return m_cardSet.contains(cardInfos.m_cardSet);
}

// 取出第nRandom张牌
CardInfo CardInfos::getRandCardInfo()
{
    int nRandom = QRandomGenerator::global()->bounded(m_cardSet.size());

    CardSet::const_iterator cit = m_cardSet.constBegin();
    for (int i = 0; i < nRandom; ++i) ++cit;
    CardInfo cardInfo = *cit;

    m_cardSet.erase(cit);

    return cardInfo;
}

// 对卡牌信息进行排序
CardList CardInfos::reArrangeCardInfo(SortType sortType)
{
    CardList cardList;
    if (!empty()) {
        for (auto &cardInfo : m_cardSet)
            cardList.push_back(cardInfo);
        if (sortType == ST_ASC) {
            std::sort(cardList.begin(), cardList.end(), lessSort);
        } else if (sortType == ST_DESC) {
            std::sort(cardList.begin(), cardList.end(), greaterSort);
        }
    }
    return cardList;
}

