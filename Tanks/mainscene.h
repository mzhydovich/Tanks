#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPainter>
#include "wall.h"
#include "tank.h"
#include "bullet.h"
#include "target.h"
#include <QSize>
#include <QWidget>


class MainScene : public QGraphicsView
{
public:
    explicit MainScene(QWidget *parent = 0);

private:


    QGraphicsScene      *scene;     // Объявляем сцену для отрисовки
    Tank* tank1;
    QTimer          *timer;
    Tank* tank2;
    QTimer          *timer2;

    /* Объявляем игровой таймер, благодаря которому
                                 * будет производиться изменения положения объекта на сцене
                                 * При воздействии на него клавишами клавиатуры
                                 * */
private slots:
    void slotBullet(QPointF start,QPointF target);
};

#endif // MAINSCENE_H
