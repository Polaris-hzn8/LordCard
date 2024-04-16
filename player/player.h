/*************************************************************************
    > File Name: player.h
    > Author: luochenhao
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-10 20:31:32
************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject {
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);

signals:

public slots:

};

#endif // PLAYER_H
