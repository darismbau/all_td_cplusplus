#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include <string>
#include "card.h"

class TrainerCard : public Card
{
private:
    std::string trainerEffect;

public:
    TrainerCard(const std::string &trainerName, const std::string &trainerEffect);

    void displayInfo() override;
};

#endif
