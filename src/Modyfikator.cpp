#include "Modyfikator.h"

#include <iostream>
using namespace std;

Modyfikator::Modyfikator(int wRobotnikow,
                         int wSprzetu,
                         bool bNaCzas,
                         double pPogody,
                         bool wypadek)
{
    this->wahaniaRobotnikow = wRobotnikow;
    this->wahaniaSprzetu = wSprzetu;
    this->betonNaCzas = bNaCzas;
    this->punktyPogody = pPogody;
    this->wypadek = wypadek;
}

Modyfikator::~Modyfikator()
{
    //dtor
}

Modyfikator Modyfikator::generujModyfikator(int iRobotnikow, int iSprzetu)
{
    srand(time(NULL));
    int d = rand()%(iRobotnikow);
    int f = rand()%(iSprzetu);
    bool g = rand()%2;
    double h = rand()%101;
    bool i = rand()%2;

    cout << "Tego dnia pracuje:" << endl;

    return Modyfikator(d, f, g, h, i);
};

void Modyfikator::wyswietlInformacje()
{
    cout << "Ubylo robotnikow: " << wahaniaRobotnikow << endl
         << "Ubylo sprzetu: " << wahaniaSprzetu << endl
         << "Beton na czas: " << betonNaCzas << endl
         << "Pogoda: " << punktyPogody << endl
         << "Nieszczesliwy wypadek: " << wypadek << endl;

}
