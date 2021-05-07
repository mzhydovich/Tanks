
#include "mainwindow.h"
#include <QPalette>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->showMaximized();
    //this->setGeometry(QGuiApplication::screens().at(0)->availableGeometry());

    // виджет с игровым окном
    QWidget* game_window = new QWidget();
    QVBoxLayout* game_layout = new QVBoxLayout(game_window);
    game_layout->setContentsMargins(0, 0, 0, 0);
    game_layout->setSpacing(0);


    //виджет со счётом, заливка просто для выделения
    QWidget* score = new QWidget();
    QPalette p(palette());
    p.setColor(QPalette::Window, QColor(255, 212, 105));
    score->setAutoFillBackground(true);
    score->setPalette(p);
    score->setFixedHeight(50);
    game_layout->addWidget(score);

    //виджет со сценой
    MainScene* main_scene = new MainScene();
    //main_scene->setFixedWidth(this->width());
    game_layout->addWidget(main_scene);

    this->setCentralWidget(game_window);

}

//MainWindow::~MainWindow()
//{
    //delete ui;
//}
