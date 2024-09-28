/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-29 00:52:57
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QPushButton *parent = nullptr);

    void setImage(QString normal, QString hover, QString pressed);
protected:
    //重写鼠标事件
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
    void paintEvent(QPaintEvent* event);
signals:


private:
    QString m_normal;   //正常状态图片路径
    QString m_pressed;  //按下状态图片路径
    QString m_hover;    //悬停状态图片路径

    QPixmap m_button_img;
};

#endif // MYBUTTON_H
