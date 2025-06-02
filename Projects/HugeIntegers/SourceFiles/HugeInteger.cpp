#include "HugeInteger.h"
#include <string>
using namespace std;

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
//                              CONSTRUCTORS
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
HugeInteger::HugeInteger() {
    totalDigits = 1;
    isNeg = false;
    Ds = new int[1];
    Ds[0] = 0;
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
int HugeInteger::operator[](int index) const {
    if (index >= this->totalDigits)
        return 0;
    return this->Ds[index];
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger HugeInteger::operator+(const HugeInteger &H) const {
    HugeInteger result;

    // both numbers have same sign
    if ((*this).isNeg == H.isNeg) {
        if (this->greaterThanElementWise(H)) {
            result = this->elementWiseAdd(H);
        } else {
            result = H.elementWiseAdd(*this);
        }
        
        result.isNeg = (*this).isNeg;
    } else {
        if (this->greaterThanElementWise(H)) {
            result = this->elementWiseSubtract(H);
            result.isNeg = this->isNeg;
        } else {
            result = H.elementWiseSubtract(*this);
            result.isNeg = H.isNeg;
        }
    }

    return result;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger HugeInteger::operator+=(const HugeInteger &H) {
    *this = *this + H;
    return *this;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger HugeInteger::operator-() const {
    HugeInteger copyOfThis = *this;
    copyOfThis.isNeg = !copyOfThis.isNeg;
    return copyOfThis;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger HugeInteger::operator-(const HugeInteger &H) const {
    return *this + (-H);
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger HugeInteger::operator*(const HugeInteger &H) const {
    HugeInteger result;
    
    // TODO: ignore the sign of H for the loop!
    HugeInteger tempH = H;
    tempH.isNeg = false;

    for (HugeInteger I; I < tempH; I++) {
        result = result + *this;
    }

    result.isNeg = (this->isNeg == H.isNeg) ? false : true;
    return result;
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
bool HugeInteger::operator<(const HugeInteger &H) const {
    if (this->isNeg == true && H.isNeg == false)
        return true;
    else if (this->isNeg == false && H.isNeg == true)
        return false;
    else if (this->isNeg == false) // both numbers are +ve
        return H.greaterThanElementWise(*this);
    else if (this->isNeg == true) // both numbers are -ve
        return this->greaterThanElementWise(H);

    return false;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
bool HugeInteger::operator>(const HugeInteger &H) const {
    return H < *this;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
bool HugeInteger::operator==(const HugeInteger &H) const {
    return (*this < H == false) && (H < *this == false);
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger HugeInteger::operator++(int) {
    HugeInteger temp = *this;
    HugeInteger A; A.Ds[0] = 1;
    *this = *this + A;
    return temp;
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
const HugeInteger HugeInteger::elementWiseAdd(const HugeInteger &H) const {
    HugeInteger result(this->totalDigits + 1); // +1 could be the max size of added integers
    int carry = 0;

    for (int i = 0; i < result.totalDigits; i++) {
        result.Ds[i] = ((*this)[i] + H[i] + carry) % 10;
        carry = ((*this)[i] + H[i] + carry) / 10;
    }

    result.trim();
    return result;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
const HugeInteger HugeInteger::elementWiseSubtract(const HugeInteger &H) const {
    HugeInteger result(this->totalDigits);
    int carry = 0;

    int tempResult = 0;
    for (int i = 0; i < this->totalDigits; i++) {
        int this_n = (*this)[i];

        tempResult = this_n - H[i] - carry;

        if (tempResult < 0) {
            tempResult += 10;
            carry = 1;
        }

        result.Ds[i] = tempResult;        
    }

    result.trim();
    return result;
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
bool HugeInteger::lessThanElementWise(const HugeInteger &H) const {
    // Check if 'this' integer is greater, ignoring the sign
    // Check: *this < H

    if (this->totalDigits < H.totalDigits) // *this is smaller
        return true;
    if (this->totalDigits > H.totalDigits) // *this is greater
        return false;

    int lastIndex = this->totalDigits - 1;
    for (int i = lastIndex; i >=0; i--) {
        // Digits are stored in reverse order
        // So the most-significant-digit is on the last index
        if ((*this)[i] < H.Ds[i])
            return true;
        if ((*this)[i] > H.Ds[i])
            return false;
    }
    return false; // *this == H
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
bool HugeInteger::greaterThanElementWise(const HugeInteger &H) const {
    // *this > H
    return H.lessThanElementWise(*this);
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
bool HugeInteger::equalElementWise(const HugeInteger &H) const {
    return !lessThanElementWise(H) && !greaterThanElementWise(H);
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
void HugeInteger::trim() {
    while ((*this)[this->totalDigits - 1] == 0) {
        this->totalDigits--;
    }
}

// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
int HugeInteger::greaterDigitCount(const HugeInteger &H) const {
    if ((*this).totalDigits >= H.totalDigits)
        return (*this).totalDigits;
    if ((*this).totalDigits < H.totalDigits)
        return H.totalDigits;
    return H.totalDigits;
}


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
