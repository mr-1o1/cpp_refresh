#include <iostream>
#include "HugeInteger.h"
using namespace std;

void readAllHugeIntegers(HugeInteger* &Hs, int &totalInts) {
    ifstream Rdr("SourceFiles/Hs.txt");

    Rdr >> totalInts;
    cout << "Total Huge Integers: " << totalInts << endl;

    Hs = new HugeInteger[totalInts];

    for (int i = 0; i < totalInts; i++) {
        Rdr >> Hs[i];
    }
}

void showAllHugeIntegers(const HugeInteger* Hs, const int &totalInts) {
    for (int i = 0; i < totalInts; i++) {
        cout << Hs[i] << endl;
    }
}

int main() {
    HugeInteger* Hs;
    int totalInts;

    readAllHugeIntegers(Hs, totalInts);
    showAllHugeIntegers(Hs, totalInts);

    return 0;
}