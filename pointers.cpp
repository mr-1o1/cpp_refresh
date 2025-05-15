/*
 * This file is to help you revise your
 * C++ concepts regarding pointers
 */


#include <iostream>
using namespace std;


void TakingInput(int A[], int Capacity, int &size) {

}

int main() {
    // =================================================================================
    //                              Making Alias (Pointers)
    // =================================================================================

    int i = 5; // this is a simple integer

    // this is a reference to integer `i` | alias of 'i'
    int&iRef = i; // any change in this would put change in 'i' too

    cout << "i: " << i << endl;
    cout << "iRef: " << iRef << endl; // this would output the same value as 'i'

    cout << "Changing iRef value to 10 \n";

    iRef = 10;
    cout << "i: " << i << endl; // value in 'i' is also changed
    cout << "iRef: " << iRef << endl;

    // =================================================================================
    //                              Making Alias (Pointers)
    // =================================================================================

    return 0;
}
