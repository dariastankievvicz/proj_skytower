#ifndef MODYFIKATOR_H
#define MODYFIKATOR_H

#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>

class Modyfikator
{
    public:
        Modyfikator(int wRobotnikow,
                    int wSprzetu,
                    bool bNaCzas,
                    double pPogody,
                    bool wypadek);
        virtual ~Modyfikator();

        Modyfikator generujIWyswietlModyfikator();
        static Modyfikator generujModyfikator(int iRobotnikow, int iSprzetu);
        void wyswietlInformacje();

        int wahaniaRobotnikow;
        int wahaniaSprzetu;
        bool betonNaCzas;
        double punktyPogody;
        bool wypadek;


    protected:

    private:
};

#endif // MODYFIKATOR_H
