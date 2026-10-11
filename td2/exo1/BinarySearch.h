#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm {
public:
    BinarySearch();
    virtual ~BinarySearch() = default;
    virtual int search(const vector<int>& vecteur, int cible) override;
};

#endif
