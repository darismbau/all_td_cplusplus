//
// Created by dariu on 04/10/2026.
//

#ifndef COMPLEX2D_H
#define COMPLEX2D_H


class Complex2D {
public:
    Complex2D();
    Complex2D(double _reel, double _imaginaire);
    Complex2D(const Complex2D& autre);

    double getReel () const;
    double getImaginaire () const;
    void setReel(double _reel);
    void setImaginaire(double _imaginaire);

    Complex2D operator+(const Complex2D& autre) const;
    Complex2D operator-(const Complex2D& autre) const;

private:
    double reel;
    double imaginaire;
};


#endif //COMPLEX2D_H
