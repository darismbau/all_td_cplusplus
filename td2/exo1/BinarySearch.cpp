#include "BinarySearch.h"

BinarySearch::BinarySearch() : SearchingAlgorithm()
{
}

int BinarySearch::search(const vector<int>& vecteur, int cible)
{
    numberComparisons = 0;
    totalSearch++;

    int bas = 0;
    int haut = static_cast<int>(vecteur.size()) - 1;

    while (bas <= haut)
    {
        int milieu = bas + (haut - bas) / 2;
        numberComparisons++;
        if (vecteur[milieu] == cible)
            return milieu;
        numberComparisons++;
        if (vecteur[milieu] < cible)
            bas = milieu + 1;
        else
            haut = milieu - 1;
    }
    return -1;
}
