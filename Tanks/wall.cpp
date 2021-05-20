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
    //QImage texture_image1(file_path + "/forest.jpg");
    //QString file_path = PRO_FILE_PWD;
    //QImage texture_image1(file_path + "/box.jpg");
    QImage texture_image(":/textures/images/bricks.png");

    //QImage texture_image;

    /*if(is_box) {
       texture_image = texture_image1;
    } else {
       texture_image = texture_image2;
    }*/

        painter->drawImage(QRectF(0, 0, 51, 51), texture_image);

        //painter->drawRect(0, 0, 50, 50);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
