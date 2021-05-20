#include "gamemenu.h"

GameMenu::GameMenu(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* menu_layout = new QVBoxLayout();
    QPushButton* play = new QPushButton("Play");
    QPushButton* newgame = new QPushButton("New Game");
    QPushButton* settings = new QPushButton("Settings");
    QPushButton* exit = new QPushButton("Exit");
    //play->setEnabled(false);
    //settings->setEnabled(false);

    int WINDOW_WIDTH = QGuiApplication::screens().at(0)->availableGeometry().width();
    int WINDOW_HEIGHT = QGuiApplication::screens().at(0)->availableGeometry().height();

    this->setAutoFillBackground(true);
    QPalette palette = this->palette();

    //QString file_path = PRO_FILE_PWD;
    palette.setBrush(QPalette::Window, QBrush
                     (QPixmap(":/bg/images/gamemenu.jpg").scaled(QSize(WINDOW_WIDTH, WINDOW_HEIGHT), Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

    menu_layout->setContentsMargins(WINDOW_WIDTH/3, WINDOW_HEIGHT/5, WINDOW_WIDTH/3, WINDOW_HEIGHT/5);
    play->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    newgame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    exit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    menu_layout->addWidget(play);
    menu_layout->addWidget(newgame);
    menu_layout->addWidget(settings);
    menu_layout->addWidget(exit);

    this->setLayout(menu_layout);

    connect(play, &QPushButton::clicked, this, &GameMenu::play);
    connect(newgame, &QPushButton::clicked, this, &GameMenu::newgame);
    connect(settings, &QPushButton::clicked, this, &GameMenu::settings);
    connect(exit, &QPushButton::clicked, this, &GameMenu::exit);
}



