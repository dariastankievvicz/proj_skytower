#include "BuildingSite.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    //char c;
    BuildingSite bud(10);
    bud.odpytywacz();
    bud.wyswietlInformacjePoczatkowe();
    while(!bud.jestGotowy())
    {
        bud.skonczDzien();
        Sleep(1000);
    }
    cout << "Budynek gotowy!" << endl;
    bud.wyswietlInformacje();
    return 0;
}
