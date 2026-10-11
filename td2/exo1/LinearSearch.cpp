#include "LinearSearch.h"

LinearSearch::LinearSearch() : SearchingAlgorithm()
{
}

int LinearSearch::search(const vector<int>& vecteur, int cible)
{
    numberComparisons = 0;
    totalSearch++;

    for (size_t i = 0; i < vecteur.size(); ++i)
    {
        numberComparisons++;
        if (vecteur[i] == cible)
            return static_cast<int>(i);
    }
    return -1;
}
