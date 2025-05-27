// We write this to let compiler know to include this only once if haven't already
#pragma once

class MyTime {
    unsigned int hour;
    unsigned int min;
    unsigned int sec;

public:
    MyTime(int = 0, int = 0, int = 0);
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    void printUniversal() const;
    void printStandard() const;
};
