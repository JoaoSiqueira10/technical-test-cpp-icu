#include "LED.h"
#include <iostream>

using namespace std;

void LED::update(const map<int, Patient*>& beds) {
    RiskLevel highest = RiskLevel::LOW;

    for (auto& [_, p] : beds) {
        if (p && p->getLastScore()) {
            if ((int)p->getLastScore()->risk > (int)highest)
                highest = p->getLastScore()->risk;
        }
    }

    string color = "Green";
    if (highest == RiskLevel::LOW_MEDIUM) color = "Yellow";
    else if (highest == RiskLevel::MEDIUM) color = "Orange";
    else if (highest == RiskLevel::HIGH) color = "Red";

    cout << "Highest Risk Level: " << color << endl;
}
