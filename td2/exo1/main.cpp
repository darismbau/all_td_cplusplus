#include <iostream>
#include <vector>
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"
using namespace std;

int main()
{
    vector<int> donnees = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};

    LinearSearch lineaire;
    JumpSearch saut;
    BinarySearch binaire;

    SearchingAlgorithm* algorithmes[] = {&lineaire, &saut, &binaire};
    const char* noms[] = {"LinearSearch", "JumpSearch", "BinarySearch"};
    int cibles[] = {13, 4};

    for (int a = 0; a < 3; ++a)
    {
        for (int c = 0; c < 2; ++c)
        {
            cout << noms[a] << " : ";
            int resultat = algorithmes[a]->search(donnees, cibles[c]);
            algorithmes[a]->displaySearchResults(cout, resultat, cibles[c]);
            cout << endl;
        }
    }
    return 0;
}
