#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <iostream>
#include <vector>
using namespace std;

class SearchingAlgorithm {
public:
    SearchingAlgorithm();
    virtual ~SearchingAlgorithm() = default;

    virtual int search(const vector<int>& vecteur, int cible) = 0;
    void displaySearchResults(ostream& flux, int results, int target);

    int getNumberComparisons() const;
    static int getTotalComparisons();
    static int getTotalSearch();
    static double getAverageComparisons();

protected:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;
};

#endif
