#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsScene>

#include "tank.h"
#include "windows.h"

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = 0);
    explicit Bullet(QPointF start, QPointF target, QObject *parent = 0);
    ~Bullet();
signals:
void signalhit(QGraphicsItem *item);

public slots:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QTimer *timerBullet; // Bullet timer processing
    qreal angle;
    Target *target;
private slots:
    void slotTimerBullet(); // Slot for processing bullet flight
};

#endif // BULLET_H

