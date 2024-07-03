#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

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

