#pragma once
#include <map>
#include "Patient.h"

class Dashboard {
public:
    void update(const std::map<int, Patient*>& beds);
};
