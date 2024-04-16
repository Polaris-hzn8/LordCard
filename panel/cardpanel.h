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
#include "card/cardInfo.h"
#include "player/player.h"

class CardPanel : public QWidget {
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);

    // 设置窗口的正面与反面图案
    void setImage(QPixmap &front, QPixmap &back);
    // 获取窗口的正面图案
    QPixmap getImage() { return m_pixFront; }

    // 设置窗口显示为正面还是反面
    void setFront(bool flag) { m_bIsfront = flag; }
    //获取窗口的显示正反情况
    bool isFront() { return m_bIsfront; }

    // 设置窗口的选中状态
    void setSelected(bool flag) { m_bSelected = flag; }
    // 获取窗口的选中状态
    bool isSelected() { return m_bSelected; }

    // 设置窗口的牌面数据
    void setCardInfo(CardInfo &cardInfo) { m_cardInfo = cardInfo; }
    // 设置窗口的牌面数据
    CardInfo getCardInfo() { return m_cardInfo; }

    // 设置窗口所属者
    void setOwner(Player *player) { m_owner = player; }
    // 获取窗口所属者
    Player* getOwner() { return m_owner; }

protected:
    // 事件处理器函数 处理Qt中的绘图事件
    void paintEvent(QPaintEvent *paintEvent);
    // 重写鼠标按下事件
    void mousePressEvent(QMouseEvent *mouseEvent);
signals:

public slots:

private:
    bool m_bSelected;           // 窗口选中状态
    bool m_bIsfront;            // 窗口正反面状态
    QPixmap m_pixFront;         // 窗口正面图案
    QPixmap m_pixBack;          // 窗口反面图案
    CardInfo m_cardInfo;        // 卡牌信息数据
    Player* m_owner;            // 窗口所属玩家
};

#endif // CARDPANEL_H
