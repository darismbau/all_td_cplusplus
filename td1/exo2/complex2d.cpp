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