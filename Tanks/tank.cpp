#include "tank.h"

Tank::Tank(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
}

Tank::~Tank()
{

}

QRectF Tank::boundingRect() const
{
    return QRectF(-20, -25, 40, 50);   /// Ограничиваем область, в которой лежит треугольник
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(-15,-25,30,40);//body
    painter->setBrush(Qt::black);
    painter->drawRect(-20,-20,5,30);//left wheel
    painter->drawRect(15,-20,5,30);//right wheel
    painter->drawRect(-5,-5,10,30);//gun

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Tank::slotGameTimer1()
{
    if(GetAsyncKeyState(VK_LEFT)){
        angle -= 10;        // Задаём поворот на 10 градусов влево
        setRotation(angle); // Поворачиваем объект

        if(!(this->scene()->collidingItems(this).isEmpty())){
            angle += 10;        // Задаём поворот на 10 градусов вправо
            setRotation(angle); // Поворачиваем объект
        }
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle += 10;        // Задаём поворот на 10 градусов вправо
        setRotation(angle); // Поворачиваем объект

                /* Проверяем на столкновение,
                 * если столкновение произошло,
                 * то возвращаем героя обратно в исходную точку
                 * */
                if(!scene()->collidingItems(this).isEmpty()){
                    angle -= 10;// Задаём поворот на 10 градусов вправо
                    setRotation(angle); // Поворачиваем объект
                }
    }
    if(GetAsyncKeyState(VK_UP)){
        setPos(mapToParent(0, 5));
        /* Продвигаем объект на 5 пискселей вперёд
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
                    setPos(mapToParent(0, -5));
        }
    }
    if(GetAsyncKeyState(VK_DOWN)){
        setPos(mapToParent(0, -5));      /* Продвигаем объект на 5 пискселей назад
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
              setPos(mapToParent(0, 5));
        }
    }

    // borders check
    if(this->x() < -(width / 2)){
        this->setX(-(width / 2) + 1);       //left
    }
    if(this->x() > (width / 2)){
        this->setX((width/2) - 1);        //right
    }

    if(this->y()< -(height / 2)){
        this->setY(-(height / 2) + 1);       //up
    }
    if(this->y()> (height / 2)){
        this->setY((height / 2) - 1);        //down
    }
}



void Tank::slotGameTimer2()
{
    if(GetAsyncKeyState('A')){
        angle -= 10;        // Задаём поворот на 10 градусов влево
        setRotation(angle); // Поворачиваем объект

        if(!(this->scene()->collidingItems(this).isEmpty())){
            angle += 10;        // Задаём поворот на 10 градусов вправо
            setRotation(angle); // Поворачиваем объект
        }
    }
    if(GetAsyncKeyState('D')){
        angle += 10;        // Задаём поворот на 10 градусов вправо
        setRotation(angle); // Поворачиваем объект

                /* Проверяем на столкновение,
                 * если столкновение произошло,
                 * то возвращаем героя обратно в исходную точку
                 * */
                if(!scene()->collidingItems(this).isEmpty()){
                    angle -= 10;// Задаём поворот на 10 градусов вправо
                    setRotation(angle); // Поворачиваем объект
                }
    }
    if(GetAsyncKeyState('W')){
        setPos(mapToParent(0, 5));
        /* Продвигаем объект на 5 пискселей вперёд
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
                    setPos(mapToParent(0, -5));
        }
    }
    if(GetAsyncKeyState('S')){
        setPos(mapToParent(0, -5));      /* Продвигаем объект на 5 пискселей назад
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
              setPos(mapToParent(0, 5));
        }
    }

    // borders check
    if(this->x() - 10 < -690){
        this->setX(-689);       //left
    }
    if(this->x() + 10 > 690){
        this->setX(689);        //right
    }

    if(this->y() - 10 < -690){
        this->setY(-689);       //up
    }
    if(this->y() + 10 > 690){
        this->setY(689);        //down
    }
}
