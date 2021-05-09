#include "target.h"
Target::Target(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
}

Target::~Target()
{

}

QRectF Target::boundingRect() const
{
    return QRectF(-20, -25, 40, 50);   /// Ограничиваем область, в которой лежит треугольник
}

QPainterPath Target::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{painter->setBrush(Qt::black);
    painter->drawEllipse(-5,-5,10,10);
    painter->setBrush(Qt::red);
painter->drawRect(-5,-1,10,2);//horizontal line
painter->drawRect(-1,-5,2,10);//vertical line

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


