# Card Game
Card game using player of LOL professional game team T1 and representative champion

# Code Explain
```cpp
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
```
Champion Card.cpp
<br>
This code defines a ChampionCard class with methods to print the card's information, attack another card, and receive damage. 
<br>
The attack() and receiveDamage() functions handle the combat mechanics between ChampionCard objects.
<br>
```cpp
class SkillCard : public Card {
public:
    SkillCard(const string& name, int cost, const string& effect)
        : Card(name, cost), effect(effect) {}

    void printCardInfo() const override;

private:
    string effect;
};

#endif //SKILL_CARD_H
```
Skillcard.h
<br>
The SkillCard class is a derived class of the Card class, and it adds an effect member variable to store the effect of the skill card. 
<br>
The printCardInfo() function is overridden to provide a custom implementation for printing the information of a SkillCard object.
<br>
```cpp
class Card {
public:
    Card(const string& name, int cost)
        : name(name), cost(cost) {}

    virtual ~Card() {}

    const string& getName() const { return name; }
    virtual void printCardInfo() const = 0;
    virtual void attack(Card& target) = 0; // Added

protected:
    string name;
    int cost;
};
#endif //CARD_H
```
Card.h
<br>
The Card class is an abstract base class that defines the common properties and behaviors of a card. 
<br>
Derived classes (such as ChampionCard and SkillCard) will need to provide their own implementations for the pure virtual functions printCardInfo() and attack().
