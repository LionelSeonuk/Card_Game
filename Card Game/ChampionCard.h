#ifndef CHAMPION_CARD_H
#define CHAMPION_CARD_H
#include "Card.h"
using namespace std;

class ChampionCard : public Card {
public:
    ChampionCard(const string& name, int cost, int health, int attackPower, int defense)
        : Card(name, cost), health(health), attackPower(attackPower), defense(defense) {}

    int getHealth() const { return health; }
    void printCardInfo() const override;
    void attack(Card& target) override; // Override here
    void receiveDamage(int damage);

private:
    int health;
    int attackPower;
    int defense;
};

#endif //CHAMPION_CARD_H

