#include "BuildingSite.h"
#include <iostream>

using namespace std;

int main()
{
    char c;
    BuildingSite bud(10);
    bud.odpytywacz();
    while(!bud.jestGotowy())
    {
        bud.wyswietlInformacje();
        bud.skonczDzien();
        cout << endl;
        cin >> c;
    }
    cout << "Budynek gotowy!" << endl;
    bud.wyswietlInformacje();
    return 0;
}
