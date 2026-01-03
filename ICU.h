#pragma once
#include <map>
#include "Patient.h"
#include "Calculator.h"

class ICU {
private:
    std::map<int, Patient*> beds;
    Calculator calculator;

public:
    ICU();
    ~ICU();

    void newScore();
    void patientHistory();
    void listPatients();
};
