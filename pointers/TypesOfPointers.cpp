#include <iostream>
#include <string>
using namespace std;

void printArray(const string msg, const int* const arr, const int size) {
    cout << msg << "{";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size-1 ? "" : ", ");
    } cout << "}\n";
}

int main() {


    /**
     * Pointers are just a variable whch holds the address of
     * some memory location.
     * 
     * There are 4 types of pointers.
     */

    // ------------------------------------------------------------
    //                           Type-1
    // ------------------------------------------------------------
    /**
     * MUTABLE (CHANGEABLE) POINTER pointing to READ/WRITE MEMORY
     * 
     * >>> Syntax: Type* pname = address;
     */

    int A[10] = {1, 2}; int size = 10;
    printArray("A[10]: ", A, size); // A[10]: {1, 2, 0, 0, 0, 0, 0, 0, 0, 0}

    int* pname = &A[0]; // copy of the address of first element of the array

    *pname = 20; // change the value at the first address
    printArray("A[10]: ", A, size); // A[10]: {20, 2, 0, 0, 0, 0, 0, 0, 0, 0} --> notice the 1st element

    pname++; // address moved to the next element --> in case of 'int' 4 would be added to the address
    *pname = 30;
    printArray("A[10]: ", A, size); // A[10]: {20, 30, 0, 0, 0, 0, 0, 0, 0, 0} --> notice the 2nd element

    *(pname + 1) = 40; // changing value without changing pointer address
    printArray("A[10]: ", A, size); // A[10]: {20, 30, 40, 0, 0, 0, 0, 0, 0, 0} --> notice the 3rd element


    cout << "\n\n";
    // ------------------------------------------------------------
    //                           Type-2
    // ------------------------------------------------------------
    /**
     * MUTABLE (CHANGEABLE) POINTER pointing to READ/WRITE MEMORY
     * 
     * >>> Syntax: const Type* pname = address;
     * 
     * The above syntax means that the pointer is given only read access on the given memory type.
     * The memory itself doesn't have to be constant. It's just the pointer is not give all rights, and
     * is given just the read access.
     * 
     * Address of the pointer can be changed and the pointer itself is not constant.
     */

    int A2[10] = {1, 2}; int size2 = 10;
    printArray("A2[10]: ", A2, size2); // A2[10]: {1, 2, 0, 0, 0, 0, 0, 0, 0, 0}

    int* pname2 = &A2[0]; // copy of the address of first element of the array

    *pname = 20; // ERROR! Cannot change value, because of READ-Only access!
    printArray("A2[10]: ", A2, size2); // A2[10]: {20, 2, 0, 0, 0, 0, 0, 0, 0, 0} --> notice the 1st element

    pname++; // address moved to the next element --> in case of 'int' 4 would be added to the address
    *pname = 30;
    printArray("A2[10]: ", A2, size2); // A2[10]: {20, 30, 0, 0, 0, 0, 0, 0, 0, 0} --> notice the 2nd element

    *(pname + 1) = 40; // changing value without changing pointer address
    printArray("A2[10]: ", A2, size2); // A2[10]: {20, 30, 40, 0, 0, 0, 0, 0, 0, 0} --> notice the 3rd element



    // ------------------------------------------------------------
    //                           Type-3
    // ------------------------------------------------------------
    /**
     * MUTABLE (CHANGEABLE) POINTER pointing to READ/WRITE MEMORY
     * 
     * >>> Syntax: Type* const pname = address;
     */


    // ------------------------------------------------------------
    //                           Type-4
    // ------------------------------------------------------------
    /**
     * MUTABLE (CHANGEABLE) POINTER pointing to READ/WRITE MEMORY
     * 
     * >>> Syntax: const Type* const pname = address;
     */

    


    return 0;
}