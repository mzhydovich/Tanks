#include "bullet.h"
#include <math.h>
static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;


Bullet::Bullet(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
}


static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Bullet::Bullet(QPointF start, QPointF target, QObject *parent)
    : QObject(parent), QGraphicsItem()
{

    this->setRotation(0);   // Устанавливаем начальный разворот
    this->setPos(start);
    //QPointF end(x,y);// Устанавливаем стартовую позицию
    // Определяем траекторию полёта пули
    QLineF lineToTarget(start, target);
    // Угол поворота в направлении к цели
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    /* Разворачиваем пули по траектории
     * */
    if (angleToTarget >= 0 && angleToTarget < Pi) {
        /// Rotate left
        setRotation(rotation() - angleToTarget * 180 /Pi);
    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
        /// Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    }
    // Инициализируем полётный таймер
    timerBullet = new QTimer();
    // И подключаем его к слоту для обработки полёта пули
    connect(timerBullet, &QTimer::timeout, this, &Bullet::slotTimerBullet);
    timerBullet->start(20);
}

Bullet::~Bullet()
{

}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,2,4);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawRect(0,0,2,4);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Bullet::slotTimerBullet()
{
    setPos(mapToParent(0, -10));

    /* Проверка выхода за границы поля
     * Если пуля вылетает за заданные границы, то пулю необходимо уничтожить
     * */


    if(this->x() < -800){
        this->deleteLater();
    }
    if(this->x() > 800){
        this->deleteLater();
    }

    if(this->y() < -800){
        this->deleteLater();
    }
    if(this->y() > 800){
        this->deleteLater();
    }
}
