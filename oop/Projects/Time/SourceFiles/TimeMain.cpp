#include "MyTime.h"
#include <iostream>
using namespace std;

int main() {
    MyTime T; // All arguments are defaulted
    MyTime T2(12); // min & sec are defaulted
    MyTime T3(12, 3); // only sec argument is defaulted
    MyTime T4(12, 3, 45); // only sec argument is defaulted

    return 0;
}
