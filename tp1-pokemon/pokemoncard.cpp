#include <iostream>
#include "pokemoncard.h"

// Le nom du Pokémon est affecté à cardName dans la classe de base
PokemonCard::PokemonCard(const std::string &pokemonName) : Card(pokemonName) {}

void PokemonCard::displayInfo()
{
    std::cout << "Pokémon : " << cardName << std::endl;
}
