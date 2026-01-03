#include <gtest/gtest.h>
#include "Calculator.h"
#include "Parameters.h"

TEST(CalculatorTest, HighRiskPatient) {
    Calculator calc;
    Parameters p;

    p.respirationRate = 30;
    p.oxygenSaturation = 90;
    p.supplementalOxygen = false;
    p.temperature = 39.5;
    p.systolicBP = 85;
    p.heartRate = 140;
    p.consciousness = Consciousness::V;

    bool redScore = false;
    int news = calc.calculateNEWS(p, redScore);
    RiskLevel risk = calc.determineRisk(news, redScore);

    EXPECT_GE(news, 7);
    EXPECT_EQ(risk, RiskLevel::HIGH);
}
