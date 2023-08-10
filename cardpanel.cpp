/*************************************************************************
    > File Name: cardpanel.cpp
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 19:45:21
************************************************************************/

#include <QPainter>
#include "cardpanel.h"

CardPanel::CardPanel(QWidget *parent) : QWidget(parent) {
    _isfront = true;//默认窗口为正面
}

void CardPanel::setImage(QPixmap &front, QPixmap &back) {
    //设置好图片后立即进行绘制update
    _front = front;
    _back = back;
    update();
    setFixedSize(_front.size());

}

void CardPanel::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (_isfront) {
        painter.drawPixmap(rect(), _front);
    } else {
        painter.drawPixmap(rect(), _back);
    }
}
