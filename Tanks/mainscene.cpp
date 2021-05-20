#include "mainscene.h"
#include "map_creator.h"

#include <QApplication>
#include <QDebug>

QList<QGraphicsItem *> MainScene::target_tank1;
QList<QGraphicsItem *> MainScene::target_tank2;
MainScene::MainScene(QWidget *parent)
    : QGraphicsView(parent) {

    //Get the size of the widget
    int w = QGuiApplication::screens().at(0)->availableGeometry().width() /2;
    int h = QGuiApplication::screens().at(0)->availableGeometry().height() /2;

    scene = new QGraphicsScene();   // Initialize the scene for rendering
    this->resize(w*2, h*2 - 75);

    //Set the scene size
    scene->setSceneRect(-w,-h+75,w*2 -2,h*2 - 75);

    this->setScene(scene);

    this->setRenderHint(QPainter::Antialiasing); //Use Antialiasing
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable the horizontal scrollbar
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Disable the vertical scrollbar
    this->setAlignment(Qt::AlignCenter);                        // Binding the content to the center
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


    QBrush back_brush(QColor(255, 243, 240)); //bricks & box
    //QBrush back_brush(QColor(224, 255, 224)); //forest

    scene->setBackgroundBrush(back_brush);

    scene->addLine(-w,-h + 75, w,-h + 75, QPen(Qt::black));//upper bound
    scene->addLine(-w,h, w,h, QPen(Qt::black));//lower bound
    scene->addLine(-w,-h + 75, -w,h, QPen(Qt::black));//left bound
    scene->addLine( w,-h + 75, w,h, QPen(Qt::black));//right bound


    MapCreator map_creator;
    map_creator.setFile("C:\\Users\\user\\Desktop\\kursovaya\\Tanks\\Tanks\\maps\\map_1_2.txt");
    map_creator.CreateMap(scene);

    Tank::num_of_tanks = 0;
    tank1 = new Tank();
    tank2 = new Tank();

Target* target1=new Target();
tank1->target=target1;
scene->addItem(tank1->target);
target_tank1.push_back(tank1);


Target* target2=new Target();
tank2->target=target2;
scene->addItem(tank2->target);
target_tank2.push_back(tank2);


scene->addItem(tank1);   // Add a tank to the scene
tank1->setPos(-690,-300);  // Place the tank in the center of the scene
scene->addItem(tank2);
tank2->setPos(730,330);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, tank1, &Tank::slotGameTimer1);


    connect(timer, &QTimer::timeout, tank2, &Tank::slotGameTimer2);
    timer->start(1000 / 50);

    this->setScene(scene);
    connect (tank1,&Tank::signalBullet,this,&MainScene::slotBullet);
    connect (tank2,&Tank::signalBullet,this,&MainScene::slotBullet);

    connect (tank1,&Tank::signalDamage,this,&MainScene::signalConnect);
    connect (tank2,&Tank::signalDamage,this,&MainScene::signalConnect);
}

void MainScene::slotBullet(QPointF start,QPointF target)
{
//Add a bullet to the scene
   Bullet *bullet=new Bullet(start,target);
scene->addItem(bullet);
connect (bullet,&Bullet::signalhit,this,&MainScene::slothit);
}

void MainScene::slothit(QGraphicsItem *item)
{
    /* Received a signal from Bullet
     * We iterate over the entire list of targets and random damage on it
     * */

   foreach (QGraphicsItem *targ1,target_tank1 ) {

            if(targ1 ==item){

                // Casting an object from the list into the Tank class
                Tank *t = qgraphicsitem_cast <Tank *> (targ1);
                t->hit(2); // We inflict damage
            }
}
   foreach (QGraphicsItem *targ2,target_tank2 ) {

            if(targ2 ==item){

                Tank *t = qgraphicsitem_cast <Tank *> (targ2);
                t->hit(2);
            }
}
}
