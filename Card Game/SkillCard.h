#ifndef SKILL_CARD_H
#define SKILL_CARD_H
#include "Card.h"
using namespace std;

class SkillCard : public Card {
public:
    SkillCard(const string& name, int cost, const string& effect)
        : Card(name, cost), effect(effect) {}

    void printCardInfo() const override;

private:
    string effect;
};

#endif //SKILL_CARD_H

