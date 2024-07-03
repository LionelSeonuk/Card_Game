#include "ChampionCard.h"
#include <iostream>
using namespace std;

void ChampionCard::printCardInfo() const {
    cout << "ChampionCard: " << name << ", Cost: " << cost << ", Health: " << health << ", AttackPower: " << attackPower << ", Defense: " << defense << '\n';
}

void ChampionCard::attack(Card& target) {
    cout << name << " attacks " << target.getName() << " for " << attackPower << " damage.\n";
    ChampionCard* champTarget = dynamic_cast<ChampionCard*>(&target);
    if (champTarget) {
        champTarget->receiveDamage(attackPower);
    }
}

void ChampionCard::receiveDamage(int damage) {
    int actualDamage = damage - defense;
    if (actualDamage > 0) {
        health -= actualDamage;
        cout << name << " receives " << actualDamage << " damage. Current health: " << health << '\n';
    } else {
        cout << name << "'s defense is too high. No damage received.\n";
    }
}

