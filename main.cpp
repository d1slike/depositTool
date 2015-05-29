#include <QCoreApplication>
#include <iostream>
#include "templates/deposittemplate.h"
#include "model/ratesmatrix.h"
#include "model/money.h"
#include "model/valute.h"
#include "utils/array.h"
#include "utils/section.h"
#include "stdio.h"

using namespace  std;


void readBool(char *msg, bool &b)
{
    int i = 0;
    cout << msg << " (0-FALSE 1 - TRUE)-> "; cin >> i;
    b = i ? true : false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FILE* file = fopen("data.dat", "ab");
    int size = 3;
    while(size)
    {
        QString name;
        char tmp[10];
        cout << "Name-> "; cin >> tmp;
        for(int i = 0; i < strlen(tmp); i++)
            name[i] = tmp[i];
        //QString info; //TODO вводить html код, наркомания, реализовать считываение из файла, позже
        //cout << "Name-> "; cin >> name;
        int height = 0;
        //int width = 0;
        Array<RateSet, 3> rub_rates;
        Array<RateSet, 3> usd_rates;
        Array<RateSet, 3> eur_rates;
        cout << "Matrix: height (<=3)-> "; cin >> height;
        //cout << "Matrix: width (<=6)-> "; cin >> width;

        cout << "Matrix lines: <RUB>" << endl;
        for(int i = 0; i < height; i++) //
        {
            Array<int, R_SIZE> section_day;//границы по дням
            Array<double, R_SIZE> base_rates;//номинальные проценты
            Array<double, R_SIZE> effective_rates;//проценты с капитализацией
            m_long sum = 0;
            int sec_count;
            cout << i+1 << " min sum-> "; cin >> sum;
            cout << i+1 << " sections count-> "; cin >> sec_count;
            for(int j = 0; j < sec_count; j++)
            {
                cout << i+1 << "-" << j+1 << " section(min days)-> "; cin >> section_day[i];
                cout << i+1 << "-" << j+1 << " base_rates-> "; cin >> base_rates[i];
                cout << i+1 << "-" << j+1 << " effective_rates=> "; cin >> effective_rates[i];
            }
            RateSet tmp(sum, sec_count, section_day, base_rates, effective_rates);
            rub_rates[i] = tmp;
        }

        cout << "Matrix lines: <USD>" << endl;
        for(int i = 0; i < height; i++) //
        {
            Array<int, R_SIZE> section_day;//границы по дням
            Array<double, R_SIZE> base_rates;//номинальные проценты
            Array<double, R_SIZE> effective_rates;//проценты с капитализацией
            m_long sum = 0;
            int sec_count;
            cout << i+1 << " min sum-> "; cin >> sum;
            cout << i+1 << " sections count-> "; cin >> sec_count;
            for(int j = 0; j < sec_count; j++)
            {
                cout << i+1 << "-" << j+1 << " section(min days)-> "; cin >> section_day[i];
                cout << i+1 << "-" << j+1 << " base_rates-> "; cin >> base_rates[i];
                cout << i+1 << "-" << j+1 << " effective_rates=> "; cin >> effective_rates[i];
            }
            RateSet tmp(sum, sec_count, section_day, base_rates, effective_rates);
            usd_rates[i] = tmp;
        }

        cout << "Matrix lines: <EUR>" << endl;
        for(int i = 0; i < height; i++) //
        {
            Array<int, R_SIZE> section_day;//границы по дням
            Array<double, R_SIZE> base_rates;//номинальные проценты
            Array<double, R_SIZE> effective_rates;//проценты с капитализацией
            m_long sum = 0;
            int sec_count;
            cout << i+1 << " min sum-> "; cin >> sum;
            cout << i+1 << " sections count-> "; cin >> sec_count;
            for(int j = 0; j < sec_count; j++)
            {
                cout << i+1 << "-" << j+1 << " section(min days)-> "; cin >> section_day[i];
                cout << i+1 << "-" << j+1 << " base_rates-> "; cin >> base_rates[i];
                cout << i+1 << "-" << j+1 << " effective_rates=> "; cin >> effective_rates[i];
            }
            RateSet tmp(sum, sec_count, section_day, base_rates, effective_rates);
            eur_rates[i] = tmp;
        }

        RatesMatrix matrix(rub_rates, usd_rates, eur_rates);

        bool can_capitalize; //капитализация процентов
        bool can_add; //можно добавлять
        bool can_remove; //можно досрочно снимать
        bool dynam_rates;//градация по ставкам
        readBool("can_capitalize", can_capitalize);
        readBool("can_add", can_add);
        readBool("can_remove", can_remove);
        readBool("dynam_rates", dynam_rates);

        DepositTemplate templ;
        templ.setName(name);
        templ.setRates(matrix);
        templ.setCanCapitalize(can_capitalize);
        templ.setCanAdd(can_add);
        templ.setCanRemove(can_remove);
        templ.setDynamRates(dynam_rates);
        fwrite(&templ, sizeof(templ), 1, file);
        size--;

    }
    fclose(file);
    return a.exec();
}
