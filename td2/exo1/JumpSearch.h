#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "SearchingAlgorithm.h"

class JumpSearch : public SearchingAlgorithm {
public:
    JumpSearch();
    virtual ~JumpSearch() = default;
    virtual int search(const vector<int>& vecteur, int cible) override;
};

#endif
