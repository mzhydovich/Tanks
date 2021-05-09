#include "bullet.h"
#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;


Bullet::Bullet(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 50;     // Задаём угол поворота графического объекта
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

Bullet::Bullet(QPointF start, qreal angle, QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    qreal x=start.x()+10;
    qreal y=start.y()+ sqrt(pow((10 / cos(angle * 180 / Pi)), 2) - 100);
    this->setRotation(0);   // Устанавливаем начальный разворот
    this->setPos(start);
    QPointF end(x,y);// Устанавливаем стартовую позицию
    // Определяем траекторию полёта пули
    QLineF lineToTarget(start, end);
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
    timerBullet->start(7);
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
    if(this->x() < -690){
        this->deleteLater();
    }
    if(this->x() > 690){
        this->deleteLater();
    }

    if(this->y() < -690){
        this->deleteLater();
    }
    if(this->y() > 690){
        this->deleteLater();
    }
}
