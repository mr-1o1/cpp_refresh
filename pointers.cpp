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

// =================================================================================
//                              Pointers & References
// =================================================================================
void HowPointersAndReferencesWork() {
    int var = 10;
    
    // reference is just another name for the same variable
    // it is not a new variable, but an alias of the original variable
    // it is created using '&' symbol
    // it must be initialized when declared
    // it cannot be changed to refer to another variable
    // it cannot be null
    // it is not a pointer, but it can be used like one
    int &ref = var; // reference to var | alias of 'var'

    // pointer is a variable that stores the address of another variable
    // it is created using '*' symbol
    // it can be initialized to null
    // it can be changed to point to another variable
    // it can be dereferenced using '*' symbol
    // it can be used to access the value of the variable it points to
    // it can be used to access the address of the variable it points to
    // it can be used to access the address of the pointer itself
    int *ptr = &var; // pointer to var

    cout << "Value of var: " << var << endl;
    cout << "Value of ref: " << ref << endl; // this will output the same value as 'var'
    cout << "Value of ptr: " << *ptr << endl; // this will output the same value as 'var'

    cout << "-------------------------" << endl;

    cout << "Address of var        : " << &var << endl;
    cout << "Address of ref        : " << &ref << endl; // this will output the same address as 'var'
    cout << "Address stored in ptr : " << ptr << endl; // this will output the same address as 'var'
    cout << "Address of ptr        : " << &ptr << endl; // this will output the address of 'ptr'
}

// =================================================================================
//                              Pointers w.r.t. Arrays
// =================================================================================
void PointersWithArrays() {
    int A[5] = {1, 2, 3, 4, 5}; // array of integers

    // pointer to the first element of the array
    int *ptr = A; // this will point to the first element of the array

    cout << "Address of A  : " << A << endl; // this will output the address of the first element of the array
    cout << "Address of ptr: " << ptr << endl; // this will output the address of the first element of the array

    cout << "Value of A  : " << *A << endl; // this will output the value of the first element of the array
    cout << "Value of ptr: " << *ptr << endl; // this will output the value of the first element of the array

    cout << "-------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        // *(A + i) is same as A[i]
        cout << *(A + i) << " "; // this will output all elements of the array
    } cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << A[i] << " | " << i[A] << endl;
    } cout << endl;
}

void CharacterPointersAndArrays() {
    char C[5] = { 'A', 'B', 'C' };

    // In case of characters, instead of address of first element,
    // it will start printing until it finds a nullptr, which in
    // this case is after character 'C'.
    cout << "C     : " << C << endl; // start printing array from 'A'
    cout << "C + 1 : " << C + 1 << endl; // start printing array from 'B'
    cout << "C + 2 : " << C + 2 << endl; // start printing array from 'C'
    cout << "C + 3 : " << C + 3 << endl; // start printing array from nullptr, so it will show nothign

    // But how to display the address of a character?
    // Following is a method to display address of a character

    // Just add (void*) with the character.
    // It essentially tells the compiler to treat the following variable as a pointer.
    // Here is some examples,
    cout << "Address of C     : " << (void*) C << endl; // start printing array from 'A'
    cout << "Address of C + 1 : " << (void*) (C + 1) << endl; // start printing array from 'B'
    cout << "Address of C + 2 : " << (void*) (C + 2) << endl; // start printing array from 'C'
    cout << "Address of C + 3 : " << (void*) (C + 3) << endl; // start printing array from nullptr, so it will show nothign
}


// =================================================================================
// =================================================================================
// =================================================================================
//                                  Main Function
// =================================================================================
// =================================================================================
// =================================================================================
int main() {
    // HowAliasAndReferenceWorks();
    // HowArraysAndPointersWork();
    // HowPointersWorkWithTextFiles();
    // HowPointersAndReferencesWork();
    // PointersWithArrays();
    CharacterPointersAndArrays();
}
