#include "Modyfikator.h"

Modyfikator::Modyfikator(double pKonstrukcji,
                         double pWykonczenia,
                         double mKonstrukcji,
                         double mWykonczenia,
                         std::string nazwa)
{
    this->punktyKonstrukcji = pKonstrukcji;
    this->punktyWykonczenia = pWykonczenia;
    this->mnoznikKonstrukcji = mKonstrukcji;
    this->mnoznikWykonczenia = mWykonczenia;
    this->nazwa = nazwa;
}

Modyfikator::~Modyfikator()
{
    //dtor
}

std::vector<Modyfikator> Modyfikator::generujModyfikatory()
{
    std::vector<Modyfikator> mods;

    mods.push_back(Modyfikator(0, 0, 1, 1, "Wszystko w normie"));
    mods.push_back(Modyfikator(35, -20, 1.4, 0.5, "Bonus do konstrukcji"));

    return mods;
}

std::vector<Modyfikator> Modyfikator::losujModyfikatory()
{
    std::vector<Modyfikator> all = generujModyfikatory();

    return all;
}
