#include <iostream>
#include "ICU.h"

using namespace std;

int main() {
    ICU icu;
    char op;

    do {
        cout << "\nMenu\n";
        cout << "n - new score\n";
        cout << "h - patient history\n";
        cout << "a - all patients\n";
        Cout << "d - discharge patient\n";
        cout << "x - exit\n";
        cin >> op;

        if (op == 'n') icu.newScore();
        else if (op == 'h') icu.patientHistory();
        else if (op == 'a') icu.listPatients();
        else if (op == 'd') icu.dischargePatient();

    } while (op != 'x');

    return 0;
}
