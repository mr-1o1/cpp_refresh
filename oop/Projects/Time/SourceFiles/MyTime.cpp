#include <iostream>
#include "MyTime.h"
using namespace std;

MyTime::MyTime() {
    MyTime(0, 0, 0);
}

MyTime::MyTime(int h) {
    MyTime(h, 0, 0);
}

MyTime::MyTime(int h, int m) {
    MyTime(h, m, 0);
}

MyTime::MyTime(int h, int m, int s) {
    try
    {
        this->setTime(h, m, s);
    }
    catch(const std::exception& e)
    {
        cerr << "Exception: " << e.what() << '\n';
    }
}

// 
void MyTime::setTime(int h, int m, int s) {
    (*this).setHour(h);   // use of 'this' with *
    this->setMinute(m); // use of 'this' w/o *
    setSecond(s); // w/o using 'this'
}

void MyTime::setHour(int h) {
    if (h >= 0 && h<24) {
        (*this).hour = h; // use of 'this' with *
    } else {
        throw invalid_argument("hour must be 0-23! Tu banday da putar ban ja!");
    }
}

void MyTime::setMinute(int m) {
    if (m >= 0 && m<60) {
        this->min = m; // use of 'this' w/o *
    } else {
        throw invalid_argument("min must be 0-59! Tu banday da putar ban ja!");
    }
}

void MyTime::setSecond(int s) {
    if (s >= 0 && s<60) {
        sec = s;          // w/o using 'this'
    } else {
        throw invalid_argument("sec must be 0-59! Tu banday da putar ban ja!");
    }
}


void MyTime::printUniversal() const {

}

void MyTime::printStandard() const {

}
