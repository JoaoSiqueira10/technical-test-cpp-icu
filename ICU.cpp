#include "ICU.h"
#include <iostream>
#include <ctime>

using namespace std;

string now() {
    time_t t = time(nullptr);
    return string(ctime(&t)).substr(0, 16);
}

ICU::ICU() {
    for (int i = 1; i <= 6; i++)
        beds[i] = nullptr;
}

ICU::~ICU() {
    for (auto& [_, p] : beds)
        delete p;
}

void ICU::newScore() {
    int bed;
    cout << "Bed (1-6): ";
    cin >> bed;

    if (!beds[bed]) {
        int id;
        string fn, ln;
        cout << "ID: "; cin >> id;
        cout << "First name: "; cin >> fn;
        cout << "Last name: "; cin >> ln;
        beds[bed] = new Patient(id, fn, ln, bed);
    }

    Parameters p;
    char ox, c;

    cout << "Respiration rate: "; cin >> p.respirationRate;
    cout << "Oxygen saturation: "; cin >> p.oxygenSaturation;
    cout << "Supplemental oxygen (y/n): "; cin >> ox;
    p.supplementalOxygen = (ox == 'y');
    cout << "Temperature: "; cin >> p.temperature;
    cout << "Systolic BP: "; cin >> p.systolicBP;
    cout << "Heart rate: "; cin >> p.heartRate;
    cout << "Consciousness (A/V/P/U): "; cin >> c;
    p.consciousness = (Consciousness)c;

    bool red;
    int score = calculator.calculateNEWS(p, red);
    RiskLevel risk = calculator.determineRisk(score, red);

    beds[bed]->addScore(Score(score, risk, now()));

    dashboard.update(beds);
    led.update(beds);
}

void ICU::patientHistory() {
    int id;
    cout << "Patient ID: ";
    cin >> id;

    for (auto& [_, p] : beds) {
        if (p && p->getId() == id) {
            for (auto& s : p->getHistory())
                cout << s.timestamp << " - NEWS: "
                     << s.value << endl;
            return;
        }
    }

    cout << "No Patient with ID: " << id << endl;
}

void ICU::listPatients() {
    for (auto& [bed, p] : beds) {
        if (p && p->getLastScore()) {
            cout << "Bed " << bed << " - "
                 << p->getName()
                 << " - NEWS: "
                 << p->getLastScore()->value << endl;
        }
    }
}
