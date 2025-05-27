#include <iostream>
using namespace std;

// Custom DataType
struct Time {
    int hour; // 4 bytes
    int min;  // 4 bytes
    int sec;  // 4 bytes
};

int main() {
    // ============================================================================================================
    //                                          Understanding Memory of Objects
    // ============================================================================================================
    
    /**
     * Revise on how memory is allocated for custom variable
     * All of the following memory will be on Stack (Heap is only used with 'new' keyword)
     */
    Time timeObj;             // 12 bytes (4+4+4) for single object
    Time timeArr[10];         // 120 bytes = 12 x 10
    Time *timePtr = &timeObj; // 4 bytes (every kind of pointers carry same size - in a 32-bit system [8 bytes ==> 64-bit system])
    Time &timeRef = timeObj;  // No new memory | Just another alias for timeObj variable

    cout << "Check the code in the file! 😃" << endl;

    return 0;
}