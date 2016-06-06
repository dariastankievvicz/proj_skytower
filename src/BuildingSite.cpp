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
    //if
    double dziennaKonstrukcja; // przydzielone
    double dzienneWykonczenie; // przydzielone
    double mnoznikKonstrukcji=1;
    double mnoznikWykonczenia=1;
    double minWykonczenie=0;

    Modyfikator mod = Modyfikator::generujModyfikator(iloscRobotnikow, iloscSprzetu);
    mod.wyswietlInformacje();

    iloscRobotnikow=iloscRobotnikow-mod.wahaniaRobotnikow;
    iloscSprzetu=iloscSprzetu-mod.wahaniaSprzetu;

    if (iloscSprzetu>=0 && iloscSprzetu <5)
        mnoznikKonstrukcji=30; //b słabo zmechanizowana buowa
    if (iloscSprzetu>=5 && iloscSprzetu <10)
        mnoznikKonstrukcji=50; //słabo zmechanizowana budowa
    if (iloscSprzetu>=10 && iloscSprzetu <15)
        mnoznikKonstrukcji=60; //średnio zmechanizowana budowa
    if (iloscSprzetu>=15 && iloscSprzetu <=20)
        mnoznikKonstrukcji=90; //dobrze zmechanizowana budowa

    mnoznikWykonczenia=0.8*mnoznikKonstrukcji;

    dziennaKonstrukcja=iloscRobotnikow;
    dzienneWykonczenie=iloscRobotnikow;

    if (mod.wypadek==1)
        konstrukcja=konstrukcja - 0.1;
    if (konstrukcja<0)
        konstrukcja=0;
    if (mod.betonNaCzas=0)
        dziennaKonstrukcja=0;

    dziennaKonstrukcja*=mnoznikKonstrukcji/punktyNaPietro;
    dzienneWykonczenie+=mnoznikWykonczenia/punktyNaPietro;

    konstrukcja = min((double)docelowaWysokosc, konstrukcja+dziennaKonstrukcja/punktyNaPietro);
    wykonczenie = min(wykonczenie+dzienneWykonczenie/punktyNaPietro, (double)docelowaWysokosc);

    if (wykonczenie>konstrukcja)
        wykonczenie=konstrukcja-0.05;
    if (wykonczenie<0)
        wykonczenie=minWykonczenie;
    wyswietlInformacje();
}

bool BuildingSite::jestGotowy()
{
    return konstrukcja >= docelowaWysokosc
        && wykonczenie >= docelowaWysokosc;
}

void BuildingSite::wyswietlInformacje()
{
    cout << "......................." << endl
         << "......................." << endl
         << "Godzina 7:00 dnia: " << dzien << endl
         << "Wykonana konstrukcja: " << konstrukcja << endl
         << "Wykonane wykonczenie: " << wykonczenie << endl
         << "Obecna ilosc robotnikow: " << iloscRobotnikow << endl
         << "Obecna ilosc sprzetu: " << iloscSprzetu << endl;
}

void BuildingSite::wyswietlInformacjePoczatkowe()
{
    cout << "......................." << endl <<"Start budowy" << endl
         << "Planowana wysokość konstrukcji: " << docelowaWysokosc << endl
         << "Planowa ilosc robotnikow: " << iloscRobotnikow << endl
         << "Planowa ilosc sprzetu: " << iloscSprzetu << endl
         << "......................." << endl;
}

void BuildingSite::odpytywacz()
{
    cout << "Podaj liczbe kondygnacji do wybudowania: " << endl;
    cin >> docelowaWysokosc;
    cout <<endl << "Podaj liczbe sprzetu: (od zera do 20)" << endl;
    cin >> iloscSprzetu;
    cout <<endl << "Podaj liczbe robotnikow: (od zera do 100)" << endl;
    cin >>iloscRobotnikow;
}
