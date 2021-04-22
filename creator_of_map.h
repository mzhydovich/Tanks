#ifndef CREATOR_OF_MAP_H
#define CREATOR_OF_MAP_H
#include <QVector>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "wall.h"
#include <fstream>
#include <iostream>
#include <vector>

/*const QString allFileToString(QFile &aFile)
{
    if (!aFile.open(QFile::ReadOnly | QFile::Text)) {
        std::cout << "Error opening file!" << std::endl;
        return NULL;
    }
    QTextStream in(&aFile);
    return in.readAll();
}

void setDataToVector(const QStringList &aStringList,
                     QVector< QVector <int> > &aVector)
{
    size_t x = aStringList.size() - 1; // Count of line, 8
    size_t y = aStringList.at(0).count("\t") + 1; // Count of digits in line, 6
std::cout<<5;
    for (size_t i = 0; i < x; ++i) {
        QVector<int> temp_vector;
        for (size_t j = 0; j < y; ++j) {
            temp_vector.push_back(aStringList.at(i).split("\t").at(j).toInt());
        }
        aVector.push_back(temp_vector);
    }
}

void printMap(const QVector< QVector <int> > &aVector,QGraphicsScene *scene)
{

    for (int i = 0; i < aVector.size(); ++i) {


        for (int j = 0; j < aVector.at(0).size(); ++j) {

 if (aVector.at(i).at(j)==1){
      Wall* wall = new Wall(scene);
      scene->addItem(wall);
      wall->setPos(j*50,i*50);
 }
        }

    }
}
*/


/*void printMap(const std::string &file_name,QGraphicsScene *scene){
   std:: ifstream in(file_name);

    if (in.is_open())
    {
        //Если открытие файла прошло успешно

        //Вначале посчитаем сколько чисел в файле
        int count = 0;// число чисел в файле
        int temp;//Временная переменная

        while (!in.eof())// пробегаем пока не встретим конец файла eof
        {
            in >> temp;//в пустоту считываем из файла числа
            count++;// увеличиваем счетчик числа чисел
        }

        //Число чисел посчитано, теперь нам нужно понять сколько
        //чисел в одной строке
        //Для этого посчитаем число пробелов до знака перевода на новую строку

        //Вначале переведем каретку в потоке в начало файла
        in.seekg(0, std::ios::beg);
        in.clear();

        //Число пробелов в первой строчке вначале равно 0
        int count_space = 0;
        char symbol;
        while (!in.eof())//на всякий случай цикл ограничиваем концом файла
        {
            //теперь нам нужно считывать не числа, а посимвольно считывать данные
            in.get(symbol);//считали текущий символ
            if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
            if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
        }
        //cout << count_space << endl;

        //Опять переходим в потоке в начало файла
        in.seekg(0, std::ios::beg);
        in.clear();

        //Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
        //Теперь можем считать матрицу.

        int n = count / (count_space + 1);//число строк
        int m = count_space + 1;//число столбцов на единицу больше числа пробелов
        //int **x;
        //x = new int*[n];
        //for (int i = 0; i<n; i++) {x[i] = new int[m];}
        std::vector<std::vector <int> > x(n, std::vector<int> (m));


        //Считаем матрицу из файла
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                in >> x[i][j];
            }
        }

      //Выведем матрицу
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++){

                if (x[i][j]==50){
                    Wall* wall = new Wall(scene);
                                scene->addItem(wall);
                                wall->setPos(x[i][j],x[i][j]);

                }
        }}

        //for (int i = 0; i<n; i++) delete[] x[i];
        //delete[] x;

        in.close();//под конец закроем файла
    }}*/


void printMap(const std::string &file_name,QGraphicsScene *scene){
   std:: ifstream in(file_name);

    if (in.is_open())
    {

        //int x = 0;
        int row = 0; // row
        int col = 0; //column
        char  tmp = ' ';
        while (!in.eof())// пробегаем пока не встретим конец файла eof
        {
            in >> tmp;

            if (tmp == '.') {
                ++row;
                col = 0;
            } else {
                ++col;
            }

            if (tmp == '1') {
                Wall* wall = new Wall(scene);
                scene->addItem(wall);
                wall->setPos(col * 50-750, row * 50-380);
            }

        }
        in.close();
    }
}

#endif // CREATOR_OF_MAP_H
