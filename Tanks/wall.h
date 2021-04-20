#ifndef WALL_H
#define WALL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QBrush>
#include <QImage>
#include <QFile>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>


class Wall : public QObject, public QGraphicsItem
{
public:
    explicit Wall(QObject *parent = 0);
    ~Wall();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WALL_H
