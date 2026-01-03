#pragma once
#include "Parameters.h"
#include "Score.h"

class Calculator {
public:
    int calculateNEWS(const Parameters& p, bool& redScore);
    RiskLevel determineRisk(int score, bool redScore);
};
