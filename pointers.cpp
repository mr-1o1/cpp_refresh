/*
 * This file is to help you revise your
 * C++ concepts regarding pointers
 */


#include <iostream>
using namespace std;

// =================================================================================
//                              Making Alias (Pointers)
// =================================================================================
void HowAliasAndReferenceWorks() {
    int i = 5; // this is a simple integer

    // this is a reference to integer `i` | alias of 'i'
    int&iRef = i; // any change in this would put change in 'i' too

    cout << "i: " << i << endl;
    cout << "iRef: " << iRef << endl; // this would output the same value as 'i'

    cout << "Changing iRef value to 10 \n";

    iRef = 10; // changing value in the reference variable
    cout << "i: " << i << endl; // value in 'i' will also be changed
    cout << "iRef: " << iRef << endl;
}

// =================================================================================
//                              Arrays & Pointers
// =================================================================================

// Helping Function
void ShowArray(int A[], const int size) {
    cout << "=============================================\n";
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
}

/**
 *
 * @param A : contains the first address of array (int * A)
 * @param Capacity : Total numbers of integers array can hold
 * @param size : Current size of array
 *
 * prototype for this function would look like this:
 * void TakingInput(int *A, int Capacity, int &size)
 *
 * Notice that for array, only the address of first location is passed.
 */
void TakingInput(int A[], int Capacity, int &size) {
    cout << A << endl; // this will display the address of 1st location (base address) of array

    // this will display the address of 2nd location of array
    cout << A + 1 << endl; // notice the jump of 4 locations (due to integer size)

    cout << "Enter values for array(-1 to stop): " << endl;
    for (int i = 0; i < Capacity; i++) {
        int tempInput = 0;
        cin >> tempInput;

        if (tempInput == -1)
            break;
        A[size] = tempInput; size++;
    }

    ShowArray(A, size);
}

void HowArraysAndPointersWork() {
    int tempArray[100]; int tempArrayCapacity = 100; int tempSize = 0;

    // Whole array is not passed into the function.
    // Only the address of 1st location of array is passed to the function.
    TakingInput(tempArray, tempArrayCapacity, tempSize);
}

int main() {
    // HowAliasAndReferenceWorks();

    HowArraysAndPointersWork();
}
