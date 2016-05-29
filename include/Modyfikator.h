#ifndef MODYFIKATOR_H
#define MODYFIKATOR_H

#include <vector>
#include <string>

class Modyfikator
{
    public:
        Modyfikator(double punktyKonstrukcji,
                    double punktyWykonczenia,
                    double mnoznikKonstrukcji,
                    double mnoznikWykonczenia,
                    std::string nazwa);
        virtual ~Modyfikator();
        static std::vector<Modyfikator> generujModyfikatory();
        static std::vector<Modyfikator> losujModyfikatory();

        std::string nazwa;
        double punktyKonstrukcji;
        double punktyWykonczenia;
        double mnoznikKonstrukcji;
        double mnoznikWykonczenia;

    protected:

    private:
};

#endif // MODYFIKATOR_H
