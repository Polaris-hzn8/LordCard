/*************************************************************************
    > File Name: cardpanel.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 19:45:21
************************************************************************/

#include <QPainter>
#include "cardpanel.h"

CardPanel::CardPanel(QWidget *parent) : QWidget(parent) {
    m_bIsfront = true;//默认窗口为正面
}

/**
 * @brief 设置好图片后立即进行绘制update
 * @param front 正面窗口图片
 * @param back  反面窗口图片
 */
void CardPanel::setImage(QPixmap &front, QPixmap &back) {
    m_pixFront = front;
    m_pixBack = back;
    update();
    setFixedSize(m_pixFront.size());

}

void CardPanel::paintEvent(QPaintEvent *paintEvent) {
    QPainter painter(this);
    if (m_bIsfront) {
        painter.drawPixmap(rect(), m_pixFront);
    } else {
        painter.drawPixmap(rect(), m_pixBack);
    }
}
