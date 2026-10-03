//
// Created by darius on 28/09/2026.
//
#include <iostream>
#include <string>
#include "afficher.h"
#include "class.h"

using namespace std;


int main() {
    cout << "Hello world" << endl;
    afficher("Hello world again !");

    My_class a;
    My_class b("Hello constructeur !");
    b.print_my_element();            //a et b sont des objets de la classe My_class

    return 0;
}