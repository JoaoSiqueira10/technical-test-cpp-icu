#pragma once
#include <map>
#include "Patient.h"

class LED {
public:
    void update(const std::map<int, Patient*>& beds);
};
