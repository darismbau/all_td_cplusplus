#ifndef COMPLEX2D_H
#define COMPLEX2D_H
#include <iostream>
using namespace std;

class Complex2D {
public:
    Complex2D();                                      // défaut
    Complex2D(double _reel, double _imaginaire);      // valué
    Complex2D(double _valeur);                        // une valeur pour les 2
    Complex2D(const Complex2D& autre);                // recopie

    double getReel() const;
    double getImaginaire() const;
    void setReel(double _reel);
    void setImaginaire(double _imaginaire);

    Complex2D operator+(const Complex2D& autre) const;
    Complex2D operator-(const Complex2D& autre) const;
    Complex2D operator*(const Complex2D& autre) const;
    Complex2D operator/(const Complex2D& autre) const;
    bool operator<(const Complex2D& autre) const;
    bool operator>(const Complex2D& autre) const;

private:
    double reel;
    double imaginaire;
};

ostream& operator<<(ostream& flux, const Complex2D& c);   // hors classe, pour cout << c

#endif