#include <iostream>
#include <string>
using namespace std;

// =================================================================================
//                                      Class
// =================================================================================
/**
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Objects in C++ are very close to how we perceive things.
 * We perceive real world objects with their attributes and their functions.
 * Both of these things can be defined in C++ classes.
 * 
 * In Addition to that, there are some attributes and functions(methods) that we can
 * hide (won't be visible to other objects/users)
 * 
 * Following is a very simple example of how objects work in C++.
 */
class Time {
    /**
     * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
     * These are the attributes of the class.
     * By default, these are private, unless mentioned otherwise explicitly. 
     */
    int hour, min, sec;
    bool timeSet;

    /**
     * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
     * To make anything visible in a class, 'public' keyword is used.
     * Below this keyword, every attribute and method would be visible.
    */
    public:

    /**
     * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
     * These are default constructors for the class.
     * Notice:
     *      1. No return type
     *      2. Just the name of the class
     *      3. It can have parameters
     */
    // ---------------------------------------------
    Time() {
        (*this).hour = 0;
        this->min = 0;
        sec = 0;
        timeSet = false;
    }

    // ---------------------------------------------
    Time(int h, int m, int s) {
        (*this).SetTime(h, m, s);
        this->SetTime(h, m, s);
        SetTime(h, m, s);
    }

    /**
     * Another thing to notice is that every class method has one
     * hidden parameter, which is 'this' parameter.
     * 
     * For example, for the following method, compiler would build something like,
     * `void SetTime(Time* this, int h, int m, int s)`
     */
    // ---------------------------------------------
    void SetTime(int h, int m, int s) {
        hour = (h>=0 && h<=23) ? h : 0;
        min = (m>=0 && m<=59) ? m : 0;
        sec = (s>=0 && s<=23) ? s : 0;

        timeSet = true;
    }

    // ---------------------------------------------
    void PrintTime(string msg = "") {
        if (timeSet) {
            if (!msg.empty())
                cout << msg;
            cout << hour << ":" << min << ":" << sec << endl;
        } else {
            cout << "ERROR: Time is not set yet!\n";
        }
    }
};


// =================================================================================
// =================================================================================
// =================================================================================
//                                  Main Function
// =================================================================================
// =================================================================================
// =================================================================================
int main() {
    Time Bfast = Time();
    Time Lunch = Time(13, 10, 3); // Time(&Lunch, 13, 10, 3) <-- This is how constructor calls
    Time Dinner = Time(20, 77, 88);

    Bfast.PrintTime("BreakFast: "); // Time::PrintTime(&Bfast, "BreakFast: ") <-- constructor call
    Bfast.SetTime(8, 456, 30);
    Bfast.PrintTime("BreakFast: ");
    Lunch.PrintTime("Lunch: ");
    Dinner.PrintTime("Dinner: ");
    
    return 0;
}