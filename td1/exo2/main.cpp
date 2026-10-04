//
// Created by dariu on 04/10/2026.
//
#include <iostream>
#include "complex2d.h"

using namespace std;


int main()
{
    Complex2D a(1, 2);                 // 1 + 2i
    Complex2D b(3, 4);                 // 3 + 4i

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a < b : " << (a < b) << endl;   // parenthèses obligatoires autour de la comparaison
    cout << "a > b : " << (a > b) << endl;
    cout << "Complex2D(5) = " << Complex2D(5) << endl;   // constructeur à une valeur

    try
    {
        cout << a / Complex2D() << endl;         // Complex2D() vaut 0 + 0i : division par zéro
    }
    catch (const char* message)                  // on rattrape le texte lancé par throw
    {
        cout << message << endl;
    }

    return 0;
}