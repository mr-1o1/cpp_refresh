#include <iostream>
#include "MyTime.h"
using namespace std;

// Assigning some values to attributes in front of class constructor name is a better syntax
// Example:  MyTime() : hour(0), min(0), sec(0)
MyTime::MyTime() : hour(0), min(0), sec(0) {
    // hour = min = sec = 0; // not a good way, because values are alreay assigned garbage!

    cout << "Constructor is working!" << endl;
}

MyTime::MyTime(int h, int m, int s) {
    if (
        (h >= 0 && h<24) &&
        (m >= 0 && m<60) &&
        (s >= 0 && s<60)
    ) {
        (*this).hour = h; // use of 'this' with *
        this->min = m;    // use of 'this' w/o *
        sec = s;          // w/o using 'this'
    } else {
        throw invalid_argument("hour, min and/or s not in range! Tu banday da putar ban ja!");
    }

}

void MyTime::setTime(int, int, int) {

}


void MyTime::printUniversal() const {

}

void MyTime::printStandard() const {

}
