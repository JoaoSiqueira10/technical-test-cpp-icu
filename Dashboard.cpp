#include "Dashboard.h"
#include <iostream>

using namespace std;

string riskToString(RiskLevel r) {
    if (r == RiskLevel::LOW) return "Low";
    if (r == RiskLevel::LOW_MEDIUM) return "Low-Medium";
    if (r == RiskLevel::MEDIUM) return "Medium";
    return "High";
}

void Dashboard::update(const map<int, Patient*>& beds) {
    cout << "\n--- DASHBOARD ---\n";
    for (auto& [bed, p] : beds) {
        if (p && p->getLastScore()) {
            cout << "Bed " << bed << " - "
                 << p->getName()
                 << " - Risk: "
                 << riskToString(p->getLastScore()->risk)
                 << " - "
                 << p->getLastScore()->timestamp
                 << endl;
        }
    }
}
