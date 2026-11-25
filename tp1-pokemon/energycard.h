#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include <string>
#include "card.h"

class EnergyCard : public Card
{
private:
    std::string energyType;

public:
    EnergyCard(const std::string &energyType);

    void displayInfo() override;
};

#endif
