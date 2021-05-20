#include "tank.h"

int Tank::num_of_tanks=0;
Tank::Tank(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

    angle = 0;     //   Setting the rotation angle of the graphic object
    setRotation(angle);  // Set the angle of rotation of the graphic object
    target= new Target();
    health = 30;
    maxhealth = health;
    ++num_of_tanks;
    tank_ID = num_of_tanks;
}

Tank::~Tank()
{

}

QRectF Tank::boundingRect() const
{
    return QRectF(-20, -25, 40, 50);   // Limiting the area in which the tank lies
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (tank_ID == 1) {
       painter->setBrush(Qt::blue);
    } else if (tank_ID == 2) {
       painter->setBrush(Qt::green);
    }

    painter->drawRect(-15,-25,30,40);//body
    painter->setBrush(Qt::black);
    painter->drawRect(-20,-20,5,30);//left wheel
    painter->drawRect(15,-20,5,30);//right wheel
    painter->drawRect(-5,-5,10,30);//gun
    target->setPos(mapToParent(0, 2000));


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Tank::slotGameTimer1()
{
    if(GetAsyncKeyState(VK_LEFT)){
        angle -= 10;        // Set the rotation 10 degrees to the left
        setRotation(angle); // Rotating the object
        target->angle -= 10;
        target->setRotation(target->angle);
        if(!(this->scene()->collidingItems(this).isEmpty())){
            angle += 10;        // Set the rotation 10 degrees to the right
            setRotation(angle);
            // Rotating the object
        }
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle += 10;        // Set the rotation 10 degrees to the right
        setRotation(angle); // Rotating the object
        target->angle += 10;        // Set the rotation 10 degrees to the left
       target->setRotation(target->angle);
                /* Checking for a collision
                 * if a collision has occurred,
                 * then we return the hero back to the starting point
                 * */
                if(!scene()->collidingItems(this).isEmpty()){
                    angle -= 10;// Set the rotation 10 degrees to the right
                    setRotation(angle); // Rotating the object
                }
    }
    if(GetAsyncKeyState(VK_UP)){
        setPos(mapToParent(0, 5));
      //  target->setPos(target->mapToParent(0, 5));
        /*Move the object 5 pixels forward
                                         * by translating them into the coordinate system
                                         * graphic scene
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
                    setPos(mapToParent(0, -5));
        }
    }
    if(GetAsyncKeyState(VK_DOWN)){
        setPos(mapToParent(0, -5));      /* Move the object 5 pixels back
                                         * by translating them into the coordinate system
                                         * graphic scene
                                         * */
         // target->setPos(target->mapToParent(0, -5));
        if(!scene()->collidingItems(this).isEmpty()){
              setPos(mapToParent(0, 5));
        }
    }

    if(GetAsyncKeyState('K')){
    emit signalBullet(/*QPointF(this->x(),this->y())*/mapToScene(0,25),QPointF(target->x(),target->y()));

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
        angle -= 10;
        setRotation(angle);

        if(!(this->scene()->collidingItems(this).isEmpty())){
            angle += 10;
            setRotation(angle);
        }
    }
    if(GetAsyncKeyState('D')){
        angle += 10;
        setRotation(angle);


                if(!scene()->collidingItems(this).isEmpty()){
                    angle -= 10;
                    setRotation(angle);
                }
    }
    if(GetAsyncKeyState('W')){
        setPos(mapToParent(0, 5));

        if(!scene()->collidingItems(this).isEmpty()){
                    setPos(mapToParent(0, -5));
        }
    }
    if(GetAsyncKeyState('S')){
        setPos(mapToParent(0, -5));
        if(!scene()->collidingItems(this).isEmpty()){
              setPos(mapToParent(0, 5));
        }
    }
    if(GetAsyncKeyState('C')){
    emit signalBullet(mapToScene(0,25),QPointF(target->x(),target->y()));
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
    health -= damage;   // Reduce Target Health
    emit signalDamage(health,this->tank_ID);
    if(health <= 0) this->deleteLater();

}
