#ifndef BUILDINGSITE_H //stra�nik nag��wka
#define BUILDINGSITE_H

class BuildingSite
{
    public:
        BuildingSite(int docelowaWysokosc);
        virtual ~BuildingSite();
        bool jestGotowy();
        void skonczDzien();
        void wyswietlInformacje();
        void odpytywacz();
        const int punktyNaPietro = 100;

    protected:

    private:
        double konstrukcja;
        double wykonczenie;
        int docelowaWysokosc;
        int dzien;
        int iloscRobotnikow;
        int iloscSprzetu;
};

#endif // BUILDINGSITE_H
