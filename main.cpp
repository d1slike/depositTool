#include <QCoreApplication>
#include <iostream>
#include "model/ratesmatrix.h"
#include "model/money.h"
#include "model/valute.h"
#include "utils/array.h"
#include "utils/section.h"

using namespace  std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    while(true)
    {
        QString name;
        cout << "Name-> "; cin >> name;
        QString info; //TODO вводить html код, наркомания, реализовать считываение из файла, позже
        //cout << "Name-> "; cin >> name;
        int height = 0;
        int width = 0;
        cout << "Matrix: height (<=3)-> "; cin >> height;
        cout << "Matrix: width (<=6)-> "; cin >> width;
        //

    }

    return a.exec();
}
