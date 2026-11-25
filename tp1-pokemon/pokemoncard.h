#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <string>
#include <tuple>
#include <vector>
#include "card.h"

// Attaque : (coût en énergie, coût en énergie actuel, description, dégâts)
using Attack = std::tuple<int, int, std::string, int>;

class PokemonCard : public Card
{
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<Attack> attacks; // exactement deux attaques

public:
    PokemonCard(const std::string &pokemonName,
                const std::string &pokemonType,
                const std::string &familyName,
                int evolutionLevel,
                int maxHP,
                const Attack &attack1,
                const Attack &attack2);

    void displayInfo() override;
};

#endif
