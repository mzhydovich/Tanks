#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPainterPath>
#include <QGraphicsScene>

#include "windows.h"
#include <QScreen>
#include <QGuiApplication>
#include "target.h"
#include <QKeyEvent>

class Tank : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Tank(QObject *parent = 0);
    ~Tank();
    Target* target;
    void hit(int damdge);

    static int num_of_tanks;

signals:
 void signalBullet(QPointF start ,QPointF target);
 void signalDamage(int health,int ID);

public slots:
    void slotGameTimer1(); //moving by VK
    void slotGameTimer2(); //moving by WASD

protected:
    QRectF boundingRect() const;
    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int width = QGuiApplication::screens().at(0)->availableGeometry().width();
    int height = QGuiApplication::screens().at(0)->availableGeometry().height();

    qreal angle; //angle
int health;
int maxhealth;

int tank_ID;
};

#endif // TANK_H
