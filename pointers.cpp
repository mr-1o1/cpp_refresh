/*
 * This file is to help with revision of
 * C++ concepts of pointers
 */


#include <iostream> // handles input/output streams
#include <fstream> // library to read from files
#include <string> // to work with strings
#include "utils/helpers.h"
using namespace std; // this removes the use of 'std::' with cout/cin

// =================================================================================
//                              Alias (Pointers)
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
//                              Pointers | Arrays | Functions
// =================================================================================

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

// =================================================================================
//                              Pointers | Files
// =================================================================================
/**
 * TAKING INPUT FROM A FILE
 *
 * @param name : Name of the input text file
 * @param A : Array given by user (int* A - only the address of first location)
 * @param Capacity : Max capacity of the array
 * @param Size : Current size of the array
 */
void LoadingInput(string name, int A[], int Capacity, int &Size) {
    ifstream Rdr(name);

    if (!Rdr) {
        cout << "Error opening file " << name << endl;
        return;
    }

    Size = 0;
    for (int i = 0; i < Capacity; i++) {
        int tempInput;
        Rdr >> tempInput; // taking input from file to local variable | '>>' read until space or a linebreak
        if (tempInput == -1)
            break;
        A[Size] = tempInput; Size++;
    }
}

void HowPointersWorkWithTextFiles() {
    int tempArray[100]; int tempArrayCapacity = 100; int tempSize = 0;

    LoadingInput("input.txt", tempArray, tempArrayCapacity, tempSize);
    ShowArray(tempArray, tempSize);

    // SortIntArrayAsc(tempArray, tempSize); // testing ascending sorting function
    // ShowArray(tempArray, tempSize);
    // SortIntArrayDesc(tempArray, tempSize);  // testing descending sorting function
    // ShowArray(tempArray, tempSize);
    // SortIntArray(tempArray, tempSize, true); // testing sorting function with type flag
    // ShowArray(tempArray, tempSize);
    // SortIntArray(tempArray, tempSize, false); // testing sorting function with type flag
    // ShowArray(tempArray, tempSize);
}

int main() {
    // HowAliasAndReferenceWorks();

    // HowArraysAndPointersWork();

    HowPointersWorkWithTextFiles();
}
