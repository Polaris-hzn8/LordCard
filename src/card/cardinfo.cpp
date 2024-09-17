/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:35:36
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include "cardInfo.h"

CardInfo::CardInfo()
{

}

bool lessSort(const CardInfo &info_a, const CardInfo &info_b)
{
    if (info_a.getPoint() == info_b.getPoint()) {
        return info_a.getSuit() < info_b.getSuit();
    } else {
        return info_a.getPoint() < info_b.getPoint();
    }
}

bool greaterSort(const CardInfo &info_a, const CardInfo &info_b)
{
    if (info_a.getPoint() == info_b.getPoint()) {
        return info_a.getSuit() > info_b.getSuit();
    } else {
        return info_a.getPoint() > info_b.getPoint();
    }
}

bool operator==(const CardInfo &info_a, const CardInfo &info_b)
{
    bool b_pointEql = (info_a.getPoint() == info_b.getPoint());
    bool b_suitEql = (info_a.getSuit() == info_b.getSuit());
    return b_pointEql && b_suitEql;
}

uint qHash(const CardInfo &info)
{
    return info.getPoint() * 100 + info.getSuit();
}
