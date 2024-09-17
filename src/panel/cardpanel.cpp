/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:35:41
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include <QPainter>
#include "cardpanel.h"

CardPanel::CardPanel(QWidget *parent) : QWidget(parent)
{
    m_bSelected = false;
    m_bFront    = true;
    m_pOwner    = nullptr;
}

/**
 * @brief 设置好图片后立即进行绘制update
 * @param front 正面窗口图片
 * @param back  反面窗口图片
 */
void CardPanel::setImage(QPixmap &front, QPixmap &back)
{
    m_pixFront = front;
    m_pixBack = back;
    //设置窗口图像与大小一致
    setFixedSize(m_pixFront.size());
    //窗口重新绘制 paintEvent被调用
    update();
}

/**
 * @brief 绘图事件回调函数
 * @param paintEvent
 */
void CardPanel::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    //根据正反面情况绘制窗口图像
    if (m_bFront) {
        painter.drawPixmap(rect(), m_pixFront);
    } else {
        painter.drawPixmap(rect(), m_pixBack);
    }
}

/**
 * @brief 鼠标点击事件回调函数
 * @param mouseEvent
 */
void CardPanel::mousePressEvent(QMouseEvent *mouseEvent)
{


}


