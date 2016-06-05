#include "BuildingSite.h"

#include <iostream>
#include "Modyfikator.h"

using namespace std;

BuildingSite::BuildingSite(int docelowaWysokosc)
{
    this->docelowaWysokosc = docelowaWysokosc;
    this->konstrukcja = 0;
    this->wykonczenie = 0;
    this->dzien = 0;
}

BuildingSite::~BuildingSite()
{
    //dtor
}

void BuildingSite::skonczDzien()
{
    cout << "Koniec dnia" << endl;

    dzien+=1;
    if
    double dziennaKonstrukcja = 100; // przydzielone
    double dzienneWykonczenie = 70; // przydzielone

    Modyfikator mod = Modyfikator::generujModyfikator(iloscRobotnikow, iloscSprzetu);
    mod.wyswietlInformacje();

    dziennaKonstrukcja=dziennaKonstrukcja+(mod.wahaniaRobotnikow/iloscRobotnikow)*dziennaKonstrukcja+(mod.wahaniaSprzetu/iloscSprzetu)*dziennaKonstrukcja;
//    dziennaKonstrukcja*=mod.mnoznikKonstrukcji;
//    dzienneWykonczenie+=mod.punktyWykonczenia;
//    dzienneWykonczenie+=mod.mnoznikWykonczeniaskróty;

    konstrukcja = min((double)docelowaWysokosc, konstrukcja+dziennaKonstrukcja/punktyNaPietro);
    wykonczenie = min(wykonczenie+dzienneWykonczenie/punktyNaPietro, konstrukcja);
}

bool BuildingSite::jestGotowy()
{
    return konstrukcja >= docelowaWysokosc
        && wykonczenie >= docelowaWysokosc;
}

void BuildingSite::wyswietlInformacje()
{
    cout << "Godzina 7:00 dnia: " << dzien << endl
         << "Konstrukcja: " << konstrukcja << endl
         << "Wykonczenie: " << wykonczenie << endl
         << "Ilosc robotnikow: " << iloscRobotnikow << endl
         << "Ilosc sprzetu: " << iloscSprzetu << endl;
}

void BuildingSite::odpytywacz()
{
    cout << "Podaj liczbe kondygnacji do wybudowania: " << endl;
    cin >> docelowaWysokosc;
    cout <<endl << "Podaj liczbe sprzetu: " << endl;
    cin >> iloscSprzetu;
    cout <<endl << "Podaj liczbe robotnikow: " << endl;
    cin >>iloscRobotnikow;
}
