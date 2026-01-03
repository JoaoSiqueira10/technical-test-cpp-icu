#pragma once
#include <string>

enum RiskLevel {
    LOW,
    LOW_MEDIUM,
    MEDIUM,
    HIGH
};

class Score {
public:
    int value;
    RiskLevel risk;
    std::string timestamp;

    Score(int v, RiskLevel r, const std::string& time);
};
