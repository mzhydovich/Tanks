#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsScene>

#include "windows.h"
class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = 0);
    explicit Bullet(QPointF start, QPointF target, QObject *parent = 0);
    ~Bullet();

signals:


public slots:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QTimer *timerBullet; // Слот для обработки таймера пули
    qreal angle;
private slots:
    void slotTimerBullet(); // Слот для обработки полёта пули
};

#endif // BULLET_H

