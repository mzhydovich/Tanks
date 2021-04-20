#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    main_scene = new MainScene();
    this->setCentralWidget(main_scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

