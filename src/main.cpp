#include "BuildingSite.h"
#include <iostream>

using namespace std;

int main()
{
    char c;
    BuildingSite budynek(10);
    while(!budynek.jestGotowy())
    {
        budynek.wyswietlInformacje();
        // ustawianie rzeczy
        budynek.skonczDzien();
        cout << endl;
        cin >> c;
    }
    cout << "Budynek gotowy!" << endl;
    budynek.wyswietlInformacje();
    return 0;
}
