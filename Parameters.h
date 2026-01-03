#pragma once

enum class Consciousness {
    A, V, P, U
};

class Parameters {
public:
    int respirationRate;
    int oxygenSaturation;
    bool supplementalOxygen;
    double temperature;
    int systolicBP;
    int heartRate;
    Consciousness consciousness;

    bool isValid() const;
};
