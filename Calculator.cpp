#include "Calculator.h"

int Calculator::calculateNEWS(const Parameters& p, bool& redScore) {
    int score = 0;
    redScore = false;

    if (p.respirationRate <= 8 || p.respirationRate >= 25) {
        score += 3; redScore = true;
    }

    if (p.oxygenSaturation <= 91) {
        score += 3; redScore = true;
    }

    if (p.supplementalOxygen)
        score += 2;

    if (p.temperature <= 35.0 || p.temperature >= 39.1) {
        score += 3; redScore = true;
    }

    if (p.systolicBP <= 90 || p.systolicBP >= 220) {
        score += 3; redScore = true;
    }

    if (p.heartRate <= 40 || p.heartRate >= 131) {
        score += 3; redScore = true;
    }

    if (p.consciousness != Consciousness::A) {
        score += 3;
        redScore = true;
    }

    return score;
}

RiskLevel Calculator::determineRisk(int score, bool redScore) {
    if (score >= 7) return RiskLevel::HIGH;
    if (score >= 5) return RiskLevel::MEDIUM;
    if (redScore) return RiskLevel::LOW_MEDIUM;
    return RiskLevel::LOW;
}
