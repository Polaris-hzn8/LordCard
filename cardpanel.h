/*************************************************************************
    > File Name: cardpanel.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 19:45:31
************************************************************************/

#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include <QPixmap>
#include "cardinfo.h"

class CardPanel : public QWidget {
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);
    //image setting
    void setImage(QPixmap &front, QPixmap &back);
    QPixmap image() { return _front; }
    //side setting
    void setFront(bool flag) { _isfront = flag; }
    bool isFront() { return _isfront; }
    //selected setting
    void setSelected(bool flag) { _selected = flag; }
    bool isSelected() { return _selected; }

    //card content setting
    void setCard(CardInfo &cardInfo) { _cardInfo = cardInfo; }
    CardInfo cardInfo() { return _cardInfo; }
    //card owner setting


protected:
    //draw image
    void paintEvent(QPaintEvent *event);
signals:

public slots:

private:
    bool _selected;
    bool _isfront;
    QPixmap _front;
    QPixmap _back;
    CardInfo _cardInfo;
};

#endif // CARDPANEL_H
