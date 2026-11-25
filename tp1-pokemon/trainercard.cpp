#include <iostream>
#include "trainercard.h"

// Le nom du trainer est affecté à cardName dans la classe de base
TrainerCard::TrainerCard(const std::string &trainerName, const std::string &trainerEffect)
    : Card(trainerName), trainerEffect(trainerEffect)
{
}

void TrainerCard::displayInfo()
{
    std::cout << "Trainer : " << cardName << std::endl;
    std::cout << "Effet : " << trainerEffect << std::endl;
}
