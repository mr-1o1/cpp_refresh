#include "HugeInteger.h"
#include <string>
using namespace std;

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
//                              CONSTRUCTORS
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
HugeInteger::HugeInteger() {
    totalDigits = -1;
    isNeg = false;
    Ds = nullptr;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
HugeInteger::HugeInteger(ifstream &Rdr) {
    setInteger(Rdr);
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
HugeInteger::HugeInteger(const HugeInteger &H) {
    this->setInteger(H);
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
HugeInteger::HugeInteger(const int totalDigits) {
    this->totalDigits = totalDigits;
    this->Ds = new int[this->totalDigits];
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
//                              CLASS METHODS
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger& HugeInteger::operator=(const HugeInteger&H) {
    if (this == &H)
        return *this;
    
    this->setInteger(H);
    return *this;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
void HugeInteger::setInteger(const HugeInteger&H) {
    this->isNeg = H.isNeg;
    this->totalDigits = H.totalDigits;

    this->Ds = new int[this->totalDigits];

    // int lastIndex = this->totalDigits - 1;

    for (int i = 0; i < this->totalDigits; i++) {
        this->Ds[i] = H.Ds[i];
    }
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// For deep copy
void HugeInteger::setInteger(ifstream &Rdr) {
    this->clearMemory();

    char sign;
    string aline;

    Rdr >> sign;
    this->isNeg = sign == '-' ? true : false;

    Rdr >> aline;
    this->totalDigits = aline.size();
    this->Ds = new int[this->totalDigits];

    int lastIndex = this->totalDigits - 1;

    for (int i=0; i<this->totalDigits; i++) {
        this->Ds[lastIndex - i] = aline[i] - '0'; // convert from ascii to integer
    }
}


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
//                              UTILITY METHODS
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// const HugeInteger HugeInteger::elementWiseAdd(const HugeInteger &H) const {
//     HugeInteger result(this->totalDigits + 1); // +1 could be the max size of added integers
//     int carry = 0;

//     for (int i = 0; i < result.totalDigits; i++) {

//     }

// }

// // ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// const HugeInteger HugeInteger::elementWiseSubtract(const HugeInteger &H) const {

// }


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
void HugeInteger::clearMemory() {
    delete[] Ds;
    isNeg = false;
    totalDigits = -1;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
//                                    DESTRUCTOR
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
HugeInteger::~HugeInteger() {
    clearMemory();
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
//                              GLOBAL (FRIEND) METHODS
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
ifstream& operator >> (ifstream &Rdr, HugeInteger &H) {
    H.setInteger(Rdr);
    return Rdr;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
ostream& operator << (ostream &OUT, const HugeInteger &H) {
    int lastIndex = H.totalDigits - 1;

    OUT << (H.isNeg? '-' : '+');
    for (int i = 0; i < H.totalDigits; i++) {
        cout << H.Ds[lastIndex - i];
    }
    return cout; // || OUT
}
