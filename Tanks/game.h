#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QTextLayout>
#include <QDebug>
#include "mainscene.h"
#include "score.h"

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    //virtual ~Game1() {};
QTextLayout * textLayout;
protected:
     void keyPressEvent(QKeyEvent *e);

signals:
    void openmenu();
    void GameOver(int ID);
private slots:
    void SlotEndOfTheGame(int ID);
};

#endif // GAME_H
