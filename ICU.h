#pragma once
#include <map>
#include "Patient.h"
#include "Calculator.h"
#include "Dashboard.h"
#include "LED.h"

class ICU {
private:
    std::map<int, Patient*> beds;
    Calculator calculator;
    Dashboard dashboard;
    LED led;

public:
    ICU();
    ~ICU();

    void newScore();
    void patientHistory();
    void listPatients();
};
