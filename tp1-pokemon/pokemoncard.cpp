#include <iostream>
#include "pokemoncard.h"

// Le nom du Pokémon est affecté à cardName dans la classe de base.
// Les PV actuels (hp) démarrent au maximum.
PokemonCard::PokemonCard(const std::string &pokemonName,
                         const std::string &pokemonType,
                         const std::string &familyName,
                         int evolutionLevel,
                         int maxHP,
                         const Attack &attack1,
                         const Attack &attack2)
    : Card(pokemonName),
      pokemonType(pokemonType),
      familyName(familyName),
      evolutionLevel(evolutionLevel),
      maxHP(maxHP),
      hp(maxHP),
      attacks{attack1, attack2}
{
}

void PokemonCard::displayInfo()
{
    std::cout << "Pokémon : " << cardName << std::endl;
    std::cout << "Type : " << pokemonType << std::endl;
    std::cout << "Famille : " << familyName << std::endl;
    std::cout << "Niveau d'évolution : " << evolutionLevel << std::endl;
    std::cout << "PV : " << hp << "/" << maxHP << std::endl;

    for (std::size_t i = 0; i < attacks.size(); i++)
    {
        const Attack &a = attacks[i];
        std::cout << "Attaque " << i + 1 << " : " << std::get<2>(a)
                  << " | coût énergie : " << std::get<1>(a) << "/" << std::get<0>(a)
                  << " | dégâts : " << std::get<3>(a) << std::endl;
    }
}
