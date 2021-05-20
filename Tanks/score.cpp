#include "score.h"
Score::Score(){

health=30;
maxHealth=health;

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::Plain | QFrame::Box);
    label1->setStyleSheet("background-color:red;");
    label1->setText("Player1");
    label1->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    label1->setFixedHeight(50);
    QFont font1= label1->font();
    font1.setPixelSize(20);
    label1->setFont(font1);

    label1->setGeometry(0,0,100,100 );
    resize(length*health/maxHealth, this->height(),1);

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::Plain | QFrame::Box);
    label2->setStyleSheet("background-color:red;");
    label2->setText("Player2");
    label2->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    label2->setFixedHeight(50);
    QFont font2= label2->font();
    font2.setPixelSize(20);
    label2->setFont(font2);
    label2->setGeometry(SCORE_WIDTH - 100,0,100,100 );
    resize(length*health/maxHealth,this->height(),2);

    QPalette p(palette());
    p.setColor(QPalette::Window, QColor(255, 243, 240)); //bricks & box
    //p.setColor(QPalette::Window, QColor(224, 255, 224)); //forest

    this->setAutoFillBackground(true);
    this->setPalette(p);

    this->setFixedHeight(50);
}


void Score::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter1(this);
    QPainter painter2(this);

        painter1.save();
        painter1.setBrush(Qt::blue);
        if(!hp1.isNull())
            painter1.drawRect(hp1);
        painter1.restore();

        painter2.save();
        painter2.setBrush(Qt::green);
        if(!hp2.isNull())
            painter2.drawRect(hp2);
        painter2.restore();
}

void Score::slotDamage(int health,int ID){
   std::ofstream fout;
   if(ID==1){
        resize(length*health/maxHealth, this->height(),1);
        if(health<=0){
              std::ofstream fout;
                fout.open("Results.txt");
                fout << "Player2 WON!!!!";
                emit signalEndOfTheGame(2);
           }
   }
   else if(ID==2){
        resize(length*health/maxHealth,this->height(),2);
        if(health<=0){
                fout.open("Results.txt");
                fout << "Player1 WON!!!!";
                emit signalEndOfTheGame(1);
           }
   }
   fout.close();
}

void Score::resize(int width,int height,int ID){
    if (width < 0) width = 0;

    if(ID==1){
        hp1 = QRectF(100, 0, width,height);
        update();
    }else if(ID==2){
        hp2 = QRectF(SCORE_WIDTH - 100, 0, -width,height);
        update();
    }
}
