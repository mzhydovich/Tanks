#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout* menu_layout = new QVBoxLayout();
    QPushButton* play = new QPushButton("Play");
    QPushButton* settings = new QPushButton("Settings");
    QPushButton* exit = new QPushButton("Exit");

    int WINDOW_WIDTH = QGuiApplication::screens().at(0)->availableGeometry().width();
    int WINDOW_HEIGHT = QGuiApplication::screens().at(0)->availableGeometry().height();

    this->setAutoFillBackground(true);
    QPalette palette = this->palette();

    palette.setBrush(QPalette::Window, QBrush
                     (QPixmap(":/bg/images/menu.png").scaled(QSize(WINDOW_WIDTH, WINDOW_HEIGHT), Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

    menu_layout->setContentsMargins(WINDOW_WIDTH/3, WINDOW_HEIGHT/4, WINDOW_WIDTH/3, WINDOW_HEIGHT/4);
    play->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    exit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    menu_layout->addWidget(play);
    menu_layout->addWidget(settings);
    menu_layout->addWidget(exit);

    this->setLayout(menu_layout);

    connect(play, &QPushButton::clicked, this, &Menu::play);
    connect(settings, &QPushButton::clicked, this, &Menu::settings);
    connect(exit, &QPushButton::clicked, this, &Menu::exit);
}
