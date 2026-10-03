#include "class.h"
#include <iostream>
#include <string>

using namespace std;

My_class::My_class() : imprimer("")
{
}

My_class::My_class(string _valeur) : imprimer(_valeur)
{
}

void My_class::print_my_element() {
    cout << imprimer << endl;
}
