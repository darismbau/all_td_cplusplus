#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "pokemoncard.h"

class Player
{
private:
    std::string playerName;
    std::vector<Card *> benchCards;        // deck des cartes en réserve
    std::vector<PokemonCard *> actionCard; // deck des cartes d'action Pokémon

public:
    Player(const std::string &playerName);
};

#endif
