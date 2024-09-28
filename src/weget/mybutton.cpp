/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-29 00:52:48
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#include "mybutton.h"
#include <QPainter>
#include <QMouseEvent>

MyButton::MyButton(QPushButton *parent)
    : QPushButton(parent)
{

}

void MyButton::setImage(QString normal, QString hover, QString pressed)
{
    m_normal = normal;
    m_pressed = pressed;
    m_hover = hover;

    m_button_img.load(m_normal);
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_button_img.load(m_pressed);
        update();
    }
    QPushButton::mousePressEvent(event);
}

void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_button_img.load(m_normal);
        update();
    }
    QPushButton::mouseReleaseEvent(event);
}

void MyButton::enterEvent(QEvent *event)
{
    m_button_img.load(m_hover);
    update();
}

void MyButton::leaveEvent(QEvent *event)
{
    m_button_img.load(m_normal);
    update();
}

void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_button_img);
}
