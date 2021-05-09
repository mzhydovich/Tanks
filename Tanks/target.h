#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPainterPath>
#include <QGraphicsScene>

#include "windows.h"
#include <QScreen>
#include <QGuiApplication>



class Target : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Target(QObject *parent = 0);
    ~Target();
 qreal angle; //angle

    QRectF boundingRect() const;
    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);





};


#endif // TARGET_H
