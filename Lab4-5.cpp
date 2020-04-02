#include "Service.h"
#include "Spending.h"
#include <iostream>
#include "Tests.h"
#include "UI.h"

using namespace std;

//void printMenu()
//{
//    cout << "\n 1 - Adauga Cheltuiala\n";
//    cout << " 2 - Afisare Cheltuieli\n";
//    cout << " 3 - Sterge Cheltuiala\n";
//    cout << " 4 - Actualizeaza cheltuiala\n";
//    cout << " x - Inchide\n\n";
//}

void callTests()
{
    tests_Spending();
    tests_Repo();
    tests_Service();
}

int main()
{
    callTests();

    UI userInterfce;
    userInterfce.runUI();
}