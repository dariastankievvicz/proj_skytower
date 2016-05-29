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

    double dziennaKonstrukcja = 100; // przydzielone
    double dzienneWykonczenie = 100; // przydzielone

    cout << "Modyfikatory:" <<endl;
    vector<Modyfikator> mods = Modyfikator::losujModyfikatory();
    for(Modyfikator mod : mods)
    {
        cout << mod.nazwa << ": "
             << mod.punktyKonstrukcji << " "
             << mod.punktyWykonczenia << " "
             << mod.mnoznikKonstrukcji << " "
             << mod.mnoznikWykonczenia << endl;

        dziennaKonstrukcja+=mod.punktyKonstrukcji;
        dziennaKonstrukcja*=mod.mnoznikKonstrukcji;
        dzienneWykonczenie+=mod.punktyWykonczenia;
        dzienneWykonczenie+=mod.mnoznikWykonczenia;
    }

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
    cout << "Dzien nr " << dzien << endl
         << "Konstrukcja: " << konstrukcja << endl
         << "Wykonczenie: " << wykonczenie << endl;
}
