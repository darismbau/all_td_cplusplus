#include <iostream>
#include "MatrixNumerical.h"
using namespace std;

int main()
{
    MatrixNumerical<int> a(2, 2);
    a.addElement(0, 0, 1);
    a.addElement(0, 1, 2);
    a.addElement(1, 0, 3);
    a.addElement(1, 1, 4);

    MatrixNumerical<int> b(2, 2);
    b.addElement(0, 0, 0);
    b.addElement(0, 1, 1);
    b.addElement(1, 0, 1);
    b.addElement(1, 1, 0);

    cout << "A :" << endl;
    a.Display();
    cout << "A + B :" << endl;
    (a + b).Display();
    cout << "A - B :" << endl;
    (a - b).Display();
    cout << "A * B :" << endl;
    (a * b).Display();
    cout << "det(A) = " << a.getDeterminant() << endl;
    cout << "inverse(A) :" << endl;
    a.getInverse().Display();
    cout << "A / B :" << endl;
    (a / b).Display();
    cout << "Identite 3 :" << endl;
    MatrixNumerical<int>::getIdentity(3).Display();

    MatrixNumerical<double> c(3, 3);
    double valeurs[3][3] = {{2, 0, 1}, {1, 3, 2}, {1, 1, 2}};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            c.addElement(i, j, valeurs[i][j]);
    cout << "det(C) = " << c.getDeterminant() << endl;
    cout << "C * inverse(C) :" << endl;
    (c * c.getInverse()).Display();

    try
    {
        MatrixNumerical<int> d(2, 3);
        d.getDeterminant();
    }
    catch (const char* message)
    {
        cout << "erreur : " << message << endl;
    }
    return 0;
}
