// We write this to let compiler know to include this only once if haven't already
#pragma once

class MyTime {
    unsigned int hour;
    unsigned int min;
    unsigned int sec;

public:
    MyTime();
    MyTime(int, int, int);
    void setTime(int, int, int);
    void printUniversal() const;
    void printStandard() const;
};
