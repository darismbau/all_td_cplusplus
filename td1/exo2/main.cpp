//
// Created by dariu on 04/10/2026.
//
#include <iostream>
#include "complex2d.h"

using namespace std;

int main () {
 //   Complex2D b(3,4);
 //   cout << b.getReel() << endl;
      Complex2D a(1, 2);
      Complex2D b(3, 4);
      Complex2D somme = a + b;
      Complex2D difference = a - b;
      cout << somme.getReel() << " " << somme.getImaginaire() << endl;
      cout << difference.getReel() << " " << difference.getImaginaire() << endl;
}
