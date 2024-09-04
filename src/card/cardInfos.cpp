/*************************************************************************
    > File Name: cards.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2024-03-13 07:59:05
************************************************************************/

#include "cardInfos.h"

CardInfos::CardInfos()
{

}

/**
 * @brief 添加扑克牌信息
 * @param cardInfo
 */
void CardInfos::increase(CardInfo &cardInfo)
{
    m_CardInfos.insert(cardInfo);
}

/**
 * @brief 添加扑克牌信息集合
 * @param CardInfos
 */
void CardInfos::increase(CardInfos &CardInfos)
{
    m_CardInfos.unite(CardInfos.m_CardInfos);
}

/**
 * @brief CardInfos::operator << 添加多张扑克牌
 * @param cardInfo
 * @return
 */
CardInfos &CardInfos::operator<<(CardInfo &cardInfo)
{
    increase(cardInfo);
    return *this;
}

/**
 * @brief CardInfos::operator << 添加多个扑克牌集合
 * @param CardInfos
 * @return
 */
CardInfos &CardInfos::operator<<(CardInfos &cardInfos)
{
    increase(cardInfos);
    return *this;
}

/**
 * @brief CardInfos::decrease
 * @param cardInfo
 */
void CardInfos::decrease(CardInfo &cardInfo)
{
    m_CardInfos.remove(cardInfo);
}

void CardInfos::decrease(CardInfos &CardInfos)
{
    m_CardInfos.subtract(CardInfos.m_CardInfos);
}
