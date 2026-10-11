#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
public:
    LinearSearch();
    virtual ~LinearSearch() = default;
    virtual int search(const vector<int>& vecteur, int cible) override;
};

#endif
