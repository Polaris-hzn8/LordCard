/*************************************************************************
    > File Name: cards.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2024-03-13 07:59:05
************************************************************************/

#include "cardsInfo.h"

CardsInfo::CardsInfo()
{

}

/**
 * @brief 添加扑克牌信息
 * @param cardInfo
 */
void CardsInfo::increase(CardInfo &cardInfo)
{
    m_cardsInfo.insert(cardInfo);
}

/**
 * @brief 添加扑克牌信息集合
 * @param cardsInfo
 */
void CardsInfo::increase(CardsInfo &cardsInfo)
{
    m_cardsInfo.unite(cardsInfo.m_cardsInfo);
}

/**
 * @brief CardsInfo::operator << 添加多张扑克牌
 * @param cardInfo
 * @return
 */
CardsInfo &CardsInfo::operator<<(const CardInfo &cardInfo)
{
    increase(cardInfo);
    return *this;
}

/**
 * @brief CardsInfo::operator << 添加多个扑克牌集合
 * @param cardsInfo
 * @return
 */
CardsInfo &CardsInfo::operator<<(const CardsInfo &cardsInfo)
{
    increase(cardsInfo);
    return *this;
}

void CardsInfo::decrease(CardInfo &cardInfo)
{
    m_cardsInfo.remove(cardInfo);
}

void CardsInfo::decrease(CardsInfo &cardsInfo)
{
    m_cardsInfo.subtract(cardsInfo.m_cardsInfo);
}
