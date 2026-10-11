#include "JumpSearch.h"
#include <algorithm>
#include <cmath>

JumpSearch::JumpSearch() : SearchingAlgorithm()
{
}

int JumpSearch::search(const vector<int>& vecteur, int cible)
{
    numberComparisons = 0;
    totalSearch++;

    int taille = static_cast<int>(vecteur.size());
    if (taille == 0)
        return -1;

    int pas = static_cast<int>(sqrt(taille));
    int precedent = 0;
    int suivant = pas;

    while (precedent < taille)
    {
        int fin = min(suivant, taille) - 1;
        numberComparisons++;
        if (vecteur[fin] >= cible)
            break;
        precedent = suivant;
        suivant += pas;
    }

    for (int i = precedent; i < min(suivant, taille); ++i)
    {
        numberComparisons++;
        if (vecteur[i] == cible)
            return i;
    }
    return -1;
}
