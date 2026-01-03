#include "Patient.h"

Patient::Patient(int i, std::string fn, std::string ln, int b)
    : id(i), firstName(fn), lastName(ln), bed(b) {}

int Patient::getId() const { return id; }
int Patient::getBed() const { return bed; }

std::string Patient::getName() const {
    return firstName + " " + lastName;
}

void Patient::addScore(const Score& s) {
    history.push_back(s);
}

const std::vector<Score>& Patient::getHistory() const {
    return history;
}

const Score* Patient::getLastScore() const {
    if (history.empty()) return nullptr;
    return &history.back();
}
