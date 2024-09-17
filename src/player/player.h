/**
* Copyright (C) 2024 Polaris-hzn8 / LuoChenhao
*
* Author: luochenhao
* Email: lch2022fox@163.com
* Time: 2024-09-11 08:36:16
* Github: https://github.com/Polaris-hzn8
* Src code may be copied only under the term's of the Apache License
* Please visit the http://www.apache.org/licenses/ Page for more detail.
*
**/

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject {
    Q_OBJECT
public:
    enum Sex{ Male, Female };
    enum Role{ Lord, Farmer };
    enum Direction { Left, right };
    enum Type { Robot, User, Other };
public:
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString strName, QObject *parent = nullptr);

    void setName(const QString &strName) { m_strName = strName; };
    QString getName() const { return m_strName; };

    Sex getSex() const { return m_sex; };
    void setSex(Sex sex) { m_sex = sex; };

    Role getRole() const { return m_role; };
    void setRole(Role role) { m_role = role; };

    Direction getDirection() const { return m_direction; };
    void setDirection(Direction direction) { m_direction = direction; };

    Type getType() const { return m_type; };
    void setType(Type type) { m_type = type; };

    int getScore() const { return m_score; };
    void setScore(int score) { m_score = score; };

    bool setReult() const { return m_bResult; }
    void setResult(bool result) { m_bResult = result; }
signals:

public slots:

private:
    QString     m_strName;
    Sex         m_sex;
    Role        m_role;
    Direction   m_direction;
    Type        m_type;

    int         m_score;
    bool        m_bResult;
};

#endif // PLAYER_H
