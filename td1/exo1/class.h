//
// Created by dariu on 28/09/2026.
//

#ifndef TD1_CLASS_H
#define TD1_CLASS_H
#include <string>
#include <iostream>
using namespace std;


class My_class {
public:
    My_class();
    My_class(string valeur);

    void print_my_element();

private:
    string imprimer;
};

#endif //TD1_CLASS_H
