#include "mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QGraphicsView(parent) {

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки


    //QImage back_image(":/images/vova.jpg");
    //back_image = back_image.scaled(size());
    //QBrush back_brush(Qt::TexturePattern);
    //back_brush.setTextureImage(back_image);
    //scene->setBackgroundBrush(back_brush);

    scene->addLine(-300,-300, 300,-300, QPen(Qt::black));
    scene->addLine(-300, 300, 300, 300, QPen(Qt::black));
    scene->addLine(-300,-300,-300, 300, QPen(Qt::black));
    scene->addLine( 300,-300, 300, 300, QPen(Qt::black));

    Wall* wall1 = new Wall(scene);
    Wall* wall2 = new Wall(scene);
    Wall* wall3 = new Wall(scene);
    tank = new Tank();
    scene->addItem(wall1);
    scene->addItem(wall2);
    scene->addItem(wall3);
    wall1->setPos(100, 50);
    wall2->setPos(150, 50);
    wall3->setPos(200, 50);

    scene->addItem(tank);   /// Добавляем на сцену треугольник
    tank->setPos(-50,0);      /// Устанавливаем треугольник в центр сцены

    /* Инициализируем таймер и вызываем слот обработки сигнала таймера
     * у Треугольника 20 раз в секунду.
     * Управляя скоростью отсчётов, соответственно управляем скоростью
     * изменения состояния графической сцены
     * */
    timer = new QTimer();
    connect(timer, &QTimer::timeout, tank, &Tank::slotGameTimer);
    timer->start(1000 / 50);

    this->setScene(scene);
}

