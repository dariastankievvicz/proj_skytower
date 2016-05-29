#ifndef BUILDINGSITE_H //stra¿nik nag³ówka
#define BUILDINGSITE_H

class BuildingSite
{
    public:
        BuildingSite(int docelowaWysokosc);
        virtual ~BuildingSite();
        bool jestGotowy();
        void skonczDzien();
        void wyswietlInformacje();

        const int punktyNaPietro = 100;

    protected:

    private:
        double konstrukcja;
        double wykonczenie;
        int docelowaWysokosc;
        int dzien;
};

#endif // BUILDINGSITE_H
