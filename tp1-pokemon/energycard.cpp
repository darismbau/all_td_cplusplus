#include <iostream>
#include "energycard.h"

// Le nom de la carte est toujours "Energy" dans la classe de base
EnergyCard::EnergyCard(const std::string &energyType)
    : Card("Energy"), energyType(energyType)
{
}

void EnergyCard::displayInfo()
{
    std::cout << cardName << " : " << energyType << std::endl;
}
