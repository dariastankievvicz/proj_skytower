#include "BuildingSite.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{

    BuildingSite bud(0);
    bud.odpytywacz();
    bud.wyswietlInformacjePoczatkowe();
    while(!bud.jestGotowy())
    {
        bud.skonczDzien();
        Sleep(1000);
    }
    cout << "Budynek gotowy!" << endl;
    return 0;
}
