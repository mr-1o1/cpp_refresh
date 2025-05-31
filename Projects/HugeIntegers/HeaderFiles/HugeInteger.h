#include <iostream>
#include <fstream>
using namespace std;

#pragma once

class HugeInteger {
    

public:
    int* Ds; // To store all the digits
    int totalDigits; // Represents total number of digits
    bool isNeg; // +ve or -ve number

    // Utility Functions
    void clearMemory();

    /**
     * >>> 3 'const' keywords for the below function
     * >>> 1st: Returned object should be read-only purpose
     * >>> 2nd: Passed parameter should be read-only
     * >>> 3rd: 'this' pointer should be read-only
     */
    const HugeInteger elementWiseAdd(const HugeInteger &H) const;
    const HugeInteger elementWiseSubtract(const HugeInteger &H) const;

public:
    HugeInteger();
    HugeInteger(ifstream &Rdr);
    HugeInteger(const HugeInteger&); // copy constructor
    HugeInteger(const int);

    const HugeInteger& operator=(const HugeInteger&);

    void setInteger(const HugeInteger&); // for deep copy
    void setInteger(ifstream &Rdr);
    
    friend ifstream& operator >>(ifstream &Rdr, HugeInteger &);
    friend ostream& operator << (ostream &Out, const HugeInteger &H);

    ~HugeInteger();
};
