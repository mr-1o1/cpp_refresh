#include <iostream>
#include <iomanip> // for setw && setfill functions
using namespace std;

int main() {
    // ============================================================================================================
    //                                          setw && setfill
    // ============================================================================================================

    /**
     * setfill('<charactor>') :
     *      • Sets the filling character for empty space
     *      • Only need to set it once
     * setw(<# of required characters>) :
     *      • Sets the additional characters with the 'setfill' character
     *      • need to call every time
     * 
     * Following are the use cases of these two functions.
     */

    cout << setfill('$'); // empty spaces will be filled with this character

    // String data
    cout << setw(5) << "Land" << endl; // will print '$Land'
    cout << setw(7) << "Hello" << endl; // will print '$$Hello'
    cout << setw(4) << "Hello" << endl; // will print 'Hello'

    // Numeric data
    cout << setw(5) << 456 << endl; // will print '$$456'
    cout << setw(7) << 90 << endl; // will print '$$$$$90'
    cout << setw(4) << 12345 << endl; // will print '12345'

    return 0;
}