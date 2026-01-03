#pragma once
#include <string>
#include <vector>
#include "Score.h"

class Patient {
private:
    int id;
    std::string firstName;
    std::string lastName;
    int bed;
    std::vector<Score> history;

public:
    Patient(int id, std::string fn, std::string ln, int bed);

    int getId() const;
    int getBed() const;
    std::string getName() const;

    void addScore(const Score& s);
    const std::vector<Score>& getHistory() const;
    const Score* getLastScore() const;
};
