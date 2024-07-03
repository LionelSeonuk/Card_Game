#include <iostream>
#include <vector>
#include "Card.h"
#include "ChampionCard.h"
#include "SkillCard.h"
using namespace std;

void fightAgainstBaron(vector<Card*>& cards) {
    ChampionCard* baron = new ChampionCard("Baron", 10, 25, 20, 10);
    string cardName;

    while (baron->getHealth() > 0) {
        cout << "Available cards:\n";
        for (Card* card : cards) {
            ChampionCard* champCard = dynamic_cast<ChampionCard*>(card);
            if (champCard) {
                cout << champCard->getName() << "\n";
            }
        }

        cout << "Enter the name of the card you want to attack with: ";
        getline(cin, cardName);

        ChampionCard* selectedCard = nullptr;

        for (Card* card : cards) {
            ChampionCard* champCard = dynamic_cast<ChampionCard*>(card);
            if (champCard && champCard->getName() == cardName) {
                selectedCard = champCard;
                break;
            }
        }

        if (selectedCard != nullptr && selectedCard->getHealth() > 0) {
            cout << "You selected " << selectedCard->getName() << "!\n";
            selectedCard->attack(*baron);
        } else {
            cout << "Invalid card name or the card is not alive.\n";
        }

        // Baron attacks back
        if (selectedCard && selectedCard->getHealth() > 0) {
            baron->attack(*selectedCard);
        }

        // Print Baron's health
        cout << "Baron's health: " << baron->getHealth() << '\n';
    }

    cout << "You defeated Baron!\n";
    delete baron;
}

int main() {
    vector<Card*> cards;
    cards.push_back(new ChampionCard("Zeus's Jayce", 5, 15, 20, 5));
    cards.push_back(new ChampionCard("Gumayusi's Jinx", 4, 10, 25, 3));
    cards.push_back(new ChampionCard("Keria's Thresh", 6, 6, 7, 4));
    cards.push_back(new ChampionCard("Oner's Leesin", 5, 9, 11, 4));
    cards.push_back(new ChampionCard("Faker's Leblanc", 7, 15, 15, 5));

    cout << "Welcome to the League of Legends Card Game!\n";
    cout << "Choose your favorite champion from the T1 players:\n";
    cout << "1. Zeus's Jayce\n";
    cout << "2. Gumayusi's Jinx\n";
    cout << "3. Keria's Thresh\n";
    cout << "4. Oner's Leesin\n";
    cout << "5. Faker's Leblanc\n";
    cout << "Enter the number of your favorite champion: ";

    int choice;
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cout << "Invalid choice. Exiting the game.\n";
        return 0;
    }

    ChampionCard* selectedChampion = dynamic_cast<ChampionCard*>(cards[choice - 1]);
    if (!selectedChampion) {
        cout << "Invalid champion card. Exiting the game.\n";
        return 0;
    }

    cout << "You have selected " << selectedChampion->getName() << "!\n";

    fightAgainstBaron(cards);

    for (Card* card : cards) {
        delete card;
    }

    return 0;
}



