//
// Created by darius on 28/09/2026.
//
#include <iostream>
#include <string>
#include "afficher.h"

using namespace std;


void afficher(string imprimer) {
    cout << imprimer << endl;
}

int main() {
    cout << "Hello world" << endl;
    afficher("Hello world again !");
    return 0;
}