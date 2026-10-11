#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

template <class T>
class MatrixBase {
public:
    MatrixBase();
    MatrixBase(size_t _rows, size_t _cols);
    MatrixBase(const MatrixBase<T>& autre);
    virtual ~MatrixBase() = default;

    void addElement(size_t ligne, size_t colonne, const T& valeur);
    T getElement(size_t ligne, size_t colonne) const;
    size_t getRows() const;
    size_t getCols() const;
    void Display(ostream& flux = cout) const;

protected:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;
};

template <class T>
MatrixBase<T>::MatrixBase() : data(), rows(0), cols(0)
{
}

template <class T>
MatrixBase<T>::MatrixBase(size_t _rows, size_t _cols)
    : data(_rows, vector<T>(_cols)), rows(_rows), cols(_cols)
{
}

template <class T>
MatrixBase<T>::MatrixBase(const MatrixBase<T>& autre)
    : data(autre.data), rows(autre.rows), cols(autre.cols)
{
}

template <class T>
void MatrixBase<T>::addElement(size_t ligne, size_t colonne, const T& valeur)
{
    if (ligne >= rows || colonne >= cols)
        throw "indice hors limites";
    data[ligne][colonne] = valeur;
}

template <class T>
T MatrixBase<T>::getElement(size_t ligne, size_t colonne) const
{
    if (ligne >= rows || colonne >= cols)
        throw "indice hors limites";
    return data[ligne][colonne];
}

template <class T>
size_t MatrixBase<T>::getRows() const
{
    return rows;
}

template <class T>
size_t MatrixBase<T>::getCols() const
{
    return cols;
}

template <class T>
void MatrixBase<T>::Display(ostream& flux) const
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
            flux << data[i][j] << "\t";
        flux << endl;
    }
}

#endif
