#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <string>
#include "card.h"

class PokemonCard : public Card
{
public:
    PokemonCard(const std::string &pokemonName);

    void displayInfo() override;
};

#endif
