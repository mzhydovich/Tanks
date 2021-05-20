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

#include <string>


class MainScene : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MainScene(QWidget *parent = 0);
signals:
  //  void signalDamage(int);
    void signalConnect(int,int);
private:

static QList<QGraphicsItem *> target_tank1;//target list
static QList<QGraphicsItem *> target_tank2;//target list
    QGraphicsScene      *scene;     // Declaring the scene for rendering
    Tank* tank1;
    QTimer          *timer;
    Tank* tank2;
    QTimer          *timer2;

    /* We declare a game timer, thanks to which
                                 * the position of the object on the scene will be changed
                                 * When acted on by keyboard keys
                                 * */

private slots:
    void slotBullet(QPointF start,QPointF target);
     static void slothit(QGraphicsItem *item);

};

#endif // MAINSCENE_H
