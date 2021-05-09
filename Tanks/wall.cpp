#include "wall.h"

Wall::Wall(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Wall::~Wall()
{

}

QRectF Wall::boundingRect() const
{
    return QRectF(0, 0, 51, 51);   /// Ограничиваем область, в которой лежит треугольник
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QImage texture_image("C:\\Users\\user\\Desktop\\kursovaya\\Tanks\\Tanks\\bricks.png");
        //QBrush texture_brush(Qt::TexturePattern);
        painter->drawImage(QRectF(0, 0, 51, 51), texture_image);
        //painter->drawRect(0, 0, 50, 50);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
