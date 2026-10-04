//
// Created by darius on 04/10/2026.
//

#include "complex2d.h"
#include <iostream>

using namespace std;

Complex2D::Complex2D(): reel(0), imaginaire(0) {
}
Complex2D::Complex2D(double _reel, double _imaginaire) : reel(_reel), imaginaire(_imaginaire) {
}

Complex2D::Complex2D(const Complex2D& autre) : reel(autre.reel), imaginaire(autre.imaginaire){
}

Complex2D::Complex2D(double _valeur) : reel(_valeur), imaginaire(_valeur) {}   // ma lecture : la valeur sert aux deux

double Complex2D::getReel() const {
    return reel;
}

double Complex2D::getImaginaire() const {
    return imaginaire;
}

void Complex2D::setReel(double _reel) {
    reel = _reel;
}

void Complex2D::setImaginaire(double _imaginaire) {
    imaginaire = _imaginaire;
}

Complex2D Complex2D::operator+(const Complex2D& autre) const {

    return Complex2D((reel+autre.reel), (imaginaire+autre.imaginaire));
}

Complex2D Complex2D::operator-(const Complex2D& autre) const {
    return Complex2D((reel-autre.reel), (imaginaire-autre.imaginaire));
}

Complex2D Complex2D::operator*(const Complex2D& autre) const
{
    return Complex2D(reel * autre.reel - imaginaire * autre.imaginaire,       // x*u - y*v
                     reel * autre.imaginaire + imaginaire * autre.reel);      // x*v + y*u
}

Complex2D Complex2D::operator/(const Complex2D& autre) const
{
    double denominateur = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;   // u*u + v*v
    if (denominateur == 0)
        throw "division par zero";                                            // diviseur nul : on lance une erreur
    return Complex2D((reel * autre.reel + imaginaire * autre.imaginaire) / denominateur,
                     (imaginaire * autre.reel - reel * autre.imaginaire) / denominateur);
}

bool Complex2D::operator<(const Complex2D& autre) const
{
    double mon_module2 = reel * reel + imaginaire * imaginaire;               // module au carré (évite sqrt)
    double autre_module2 = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;
    return mon_module2 < autre_module2;                                       // mon choix : on compare les modules
}

bool Complex2D::operator>(const Complex2D& autre) const
{
    return autre < *this;                                                     // a > b revient à b < a
}

ostream& operator<<(ostream& flux, const Complex2D& c)
{
    flux << c.getReel() << " + " << c.getImaginaire() << "i";
    return flux;                                                              // on rend le flux pour pouvoir enchaîner
}
