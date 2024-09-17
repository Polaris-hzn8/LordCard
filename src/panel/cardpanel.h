/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:35:47
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include <QPixmap>
#include "card/cardInfo.h"
#include "player/player.h"

class CardPanel : public QWidget {
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);
    //窗口图案
    void setImage(QPixmap &front, QPixmap &back);
    QPixmap getFImage() { return m_pixFront; }
    QPixmap getBImage() { return m_pixBack; }
    //窗口正反面
    void setFrontFacing(bool flag) { m_bFront = flag; }
    bool isFrontFacing() { return m_bFront; }
    //窗口选中状态
    void setSelected(bool flag) { m_bSelected = flag; }
    bool isSelected() { return m_bSelected; }
    //窗口信息
    void setCardInfo(CardInfo &cardInfo) { m_cardInfo = cardInfo; }
    CardInfo getCardInfo() { return m_cardInfo; }
    //窗口拥有者
    void setOwner(Player *player) { m_pOwner = player; }
    Player* getOwner() { return m_pOwner; }
protected:
    void paintEvent(QPaintEvent *paintEvent);               // 事件处理器函数 处理Qt中的绘图事件
    void mousePressEvent(QMouseEvent *mouseEvent);          // 重写鼠标按下事件

signals:

public slots:

private:
    bool        m_bSelected;
    bool        m_bFront;
    QPixmap     m_pixFront;
    QPixmap     m_pixBack;
    CardInfo    m_cardInfo;
    Player*     m_pOwner;
};

#endif // CARDPANEL_H
