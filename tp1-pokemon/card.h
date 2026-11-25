#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
protected:
    std::string cardName;

public:
    Card(const std::string& name);
    virtual ~Card();

    // Fonction virtuelle pure : chaque type de carte affiche ses propres infos
    virtual void displayInfo() = 0;
};

#endif
