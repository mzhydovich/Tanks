#include "tank.h"

static int normalizeAngle(qreal angle)
{
    if(angle < 0) {
        while (angle < -90) {
            angle += 90;
        }
    }
    if(angle > 0) {
        while (angle > 90) {
            angle -= 90;
        }
    }
    return angle;
}

Tank::Tank(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);  // Устанавилваем угол поворота графического объекта
    target= new Target();
    health = 7;
    maxhealth = health;
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
     target->setPos(mapToParent(0, 100));
   // target->paint(painter, option, widget);
     painter->setPen(Qt::NoPen);
         painter->setBrush(Qt::red);
         painter->drawRect(-20,-35, (int) 40*health/maxhealth,5);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Tank::slotGameTimer1()
{
    if(GetAsyncKeyState(VK_LEFT)){
        angle -= 10;        // Задаём поворот на 10 градусов влево
        setRotation(angle); // Поворачиваем объект


        if (angle == -360) {
            angle = 0;
        }


        target->angle -= 10;
        target->setRotation(target->angle);

        if(!(this->scene()->collidingItems(this).isEmpty())){
            angle += 10;        // Задаём поворот на 10 градусов вправо
            setRotation(angle);
            // Поворачиваем объект
        }
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle += 10;        // Задаём поворот на 10 градусов вправо
        setRotation(angle); // Поворачиваем объект

        if (angle == 360) {
            angle = 0;
        }

        target->angle += 10;        // Задаём поворот на 10 градусов влево
       target->setRotation(target->angle);

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
      //  target->setPos(target->mapToParent(0, 5));
        /* Продвигаем объект на 5 пискселей вперёд
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
                    setPos(mapToParent(0, -5));
                    if (normalizeAngle(angle) < 0) {
                        setPos(mapToParent(5, 0));
                    }
                    if (normalizeAngle(angle) > 0) {
                        setPos(mapToParent(-5, 0));
                    }
        }
    }
    if(GetAsyncKeyState(VK_DOWN)){
        setPos(mapToParent(0, -5));      /* Продвигаем объект на 5 пискселей назад
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
         // target->setPos(target->mapToParent(0, -5));
        if(!scene()->collidingItems(this).isEmpty()){
              setPos(mapToParent(0, 5));
        }
    }

    if(GetAsyncKeyState('K')){
    emit signalBullet(QPointF(this->x(),this->y()),QPointF(target->x(),target->y()));
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
    if(GetAsyncKeyState('C')){
    emit signalBullet(QPointF(this->x(),this->y()),QPointF(target->x(),target->y()));
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

void Tank::hit(int damage)
{
    health -= damage;   // Уменьшаем здоровье мишени
    this->update(QRectF(-20,-20,40,40));    // Перерисовываем мишень
    // Если здоровье закончилось, то инициируем смерть мишени
    if(health <= 0) this->deleteLater();
}
