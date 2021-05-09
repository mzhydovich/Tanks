#include "mainscene.h"
#include "map_creator.h"

#include <QApplication>
#include <QDebug>

MainScene::MainScene(QWidget *parent)
    : QGraphicsView(parent) {

    int w = QGuiApplication::screens().at(0)->availableGeometry().width() /2;
    int h = QGuiApplication::screens().at(0)->availableGeometry().height() /2;
    //this->setFixedSize(w,h);    /// Фиксируем размеры виджета

    scene = new QGraphicsScene();   // Initialize the scene for rendering
    this->resize(w*2, h*2 - 75);
    scene->setSceneRect(-w,-h+75,w*2 -2,h*2 - 75); /// Устанавливаем область графической сцены
    this->setScene(scene);

    this->setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


    //QImage back_image(":/images/vova.jpg");
    //back_image = back_image.scaled(size());
    //QBrush back_brush(Qt::TexturePattern);
    //back_brush.setTextureImage(back_image);
    //scene->setBackgroundBrush(back_brush);

    scene->addLine(-w,-h + 75, w,-h + 75, QPen(Qt::black));//верхняя граница
    scene->addLine(-w,h, w,h, QPen(Qt::black));//нижняя граница
    scene->addLine(-w,-h + 75, -w,h, QPen(Qt::black));//левая
    scene->addLine( w,-h + 75, w,h, QPen(Qt::black));//правая

    //scene->addLine(0,0, this->width() ,this->height(), QPen(Qt::black));//верхняя граница

    MapCreator map_creator;
    map_creator.setFile("C:\\Users\\user\\Desktop\\kursovaya\\Tanks\\Tank\\map.txt");
    map_creator.CreateMap(scene);

    tank1 = new Tank();
    tank2 = new Tank();

Target* target1=new Target();
tank1->target=target1;
scene->addItem(tank1->target);
//tank1->target->setPos(-35,40);

Target* target2=new Target();
tank2->target=target2;
scene->addItem(tank2->target);
//tank2->target->setPos(50,-30);

    scene->addItem(tank1);   /// Добавляем на сцену треугольник
    tank1->setPos(-680,-300);      /// Устанавливаем треугольник в центр сцены
    scene->addItem(tank2);   /// Добавляем на сцену треугольник
    tank2->setPos(700,330);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, tank1, &Tank::slotGameTimer1);

    connect(timer, &QTimer::timeout, tank2, &Tank::slotGameTimer2);
    timer->start(1000 / 50);

    connect(tank1,&Tank::signalBullet,this,&MainScene::slotBullet);


    this->setScene(scene);
    connect (tank1,&Tank::signalBullet,this,&MainScene::slotBullet);
    connect (tank2,&Tank::signalBullet,this,&MainScene::slotBullet);

}

void MainScene::slotBullet(QPointF start,QPointF target)
{
// Добавляем на сцену пулю
scene->addItem(new Bullet(start,target));
}

void MainScene::slotBullet(QPointF start,qreal angle)
{
// Добавляем на сцену пулю
scene->addItem(new Bullet(start,angle));
}
