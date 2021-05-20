#include "game.h"
#include "windows.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* game_layout = new QVBoxLayout(this);
    game_layout->setContentsMargins(0, 0, 0, 0);
    game_layout->setSpacing(0);

    //WIDGET WITH SCORE
    Score* score = new Score();
    game_layout->addWidget(score);


    //widget with scene
    MainScene* main_scene = new MainScene();
    game_layout->addWidget(main_scene);
    connect (main_scene,&MainScene::signalConnect,score,&Score::slotDamage);
    connect (score,&Score::signalEndOfTheGame,this,&Game::SlotEndOfTheGame);
    this->setLayout(game_layout);
}

void Game::keyPressEvent(QKeyEvent *e)
{
    if( e->key() == Qt::Key_Escape)
        {
            emit openmenu();
        }
}
void Game::SlotEndOfTheGame(int ID){
 emit GameOver(ID);
}
