#include "SkillCard.h"
#include <iostream>
using namespace std;

void SkillCard::printCardInfo() const {
    cout << "SkillCard: " << name << ", Cost: " << cost << ", Effect: " << effect << '\n';
}

