#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0)
{
}

void SearchingAlgorithm::displaySearchResults(ostream& flux, int results, int target)
{
    totalComparisons += numberComparisons;
    if (totalSearch > 0)
        averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    if (results == -1)
        flux << target << " non trouve apres " << numberComparisons << " comparaisons" << endl;
    else
        flux << target << " trouve a l'indice " << results << " apres " << numberComparisons << " comparaisons" << endl;

    flux << "Total des comparaisons : " << totalComparisons << endl;
    flux << "Moyenne des comparaisons : " << averageComparisons << endl;
}

int SearchingAlgorithm::getNumberComparisons() const
{
    return numberComparisons;
}

int SearchingAlgorithm::getTotalComparisons()
{
    return totalComparisons;
}

int SearchingAlgorithm::getTotalSearch()
{
    return totalSearch;
}

double SearchingAlgorithm::getAverageComparisons()
{
    return averageComparisons;
}
