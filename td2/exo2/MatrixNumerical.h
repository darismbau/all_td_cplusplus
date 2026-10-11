#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

template <class T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical();
    MatrixNumerical(size_t _rows, size_t _cols);
    MatrixNumerical(const MatrixNumerical<T>& autre);
    virtual ~MatrixNumerical() = default;

    T getDeterminant() const;
    MatrixNumerical<double> getInverse() const;

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& autre) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& autre) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& autre) const;
    MatrixNumerical<double> operator/(const MatrixNumerical<T>& autre) const;

    static MatrixNumerical<T> getIdentity(int taille);
};

template <class T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& matrice, size_t ligne, size_t colonne)
{
    size_t n = matrice.getRows();
    MatrixNumerical<T> mineure(n - 1, n - 1);
    size_t a = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (i == ligne)
            continue;
        size_t b = 0;
        for (size_t j = 0; j < n; ++j)
        {
            if (j == colonne)
                continue;
            mineure.addElement(a, b, matrice.getElement(i, j));
            ++b;
        }
        ++a;
    }
    return mineure;
}

template <class T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>()
{
}

template <class T>
MatrixNumerical<T>::MatrixNumerical(size_t _rows, size_t _cols) : MatrixBase<T>(_rows, _cols)
{
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] = T();
}

template <class T>
MatrixNumerical<T>::MatrixNumerical(const MatrixNumerical<T>& autre) : MatrixBase<T>(autre)
{
}

template <class T>
T MatrixNumerical<T>::getDeterminant() const
{
    if (this->rows != this->cols)
        throw "matrice non carree";
    size_t n = this->rows;
    if (n == 0)
        throw "matrice vide";
    if (n == 1)
        return this->data[0][0];
    if (n == 2)
        return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];

    T determinant = T();
    for (size_t j = 0; j < n; ++j)
    {
        T terme = this->data[0][j] * getCoFactor(*this, 0, j).getDeterminant();
        if (j % 2 == 0)
            determinant = determinant + terme;
        else
            determinant = determinant - terme;
    }
    return determinant;
}

template <class T>
MatrixNumerical<double> MatrixNumerical<T>::getInverse() const
{
    if (this->rows != this->cols)
        throw "matrice non carree";
    size_t n = this->rows;
    double determinant = static_cast<double>(getDeterminant());
    if (determinant == 0)
        throw "matrice non inversible";

    MatrixNumerical<double> inverse(n, n);
    if (n == 1)
    {
        inverse.addElement(0, 0, 1.0 / determinant);
        return inverse;
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            double signe = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            double cofacteur = signe * static_cast<double>(getCoFactor(*this, i, j).getDeterminant());
            inverse.addElement(j, i, cofacteur / determinant);
        }
    }
    return inverse;
}

template <class T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& autre) const
{
    if (this->rows != autre.rows || this->cols != autre.cols)
        throw "dimensions incompatibles";
    MatrixNumerical<T> resultat(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultat.data[i][j] = this->data[i][j] + autre.data[i][j];
    return resultat;
}

template <class T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& autre) const
{
    if (this->rows != autre.rows || this->cols != autre.cols)
        throw "dimensions incompatibles";
    MatrixNumerical<T> resultat(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultat.data[i][j] = this->data[i][j] - autre.data[i][j];
    return resultat;
}

template <class T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& autre) const
{
    if (this->cols != autre.rows)
        throw "dimensions incompatibles";
    MatrixNumerical<T> resultat(this->rows, autre.cols);
    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < autre.cols; ++j)
        {
            T somme = T();
            for (size_t k = 0; k < this->cols; ++k)
                somme = somme + this->data[i][k] * autre.data[k][j];
            resultat.data[i][j] = somme;
        }
    }
    return resultat;
}

template <class T>
MatrixNumerical<double> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& autre) const
{
    MatrixNumerical<double> gauche(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            gauche.addElement(i, j, static_cast<double>(this->data[i][j]));
    return gauche * autre.getInverse();
}

template <class T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int taille)
{
    if (taille <= 0)
        throw "taille invalide";
    MatrixNumerical<T> identite(taille, taille);
    for (int i = 0; i < taille; ++i)
        identite.addElement(i, i, T(1));
    return identite;
}

#endif
