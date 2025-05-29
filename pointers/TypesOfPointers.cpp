#include <iostream>
#include <string>
using namespace std;

void printArray(const string msg, const int* const arr, const int size) {
    cout << msg << "{";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size-1 ? "" : ", ");
    } cout << "}\n";
}

void type1Pointers();
void type2Pointers();
void type3Pointers();
void type4Pointers();

int main() {


    /**
     * Pointers are just a variable whch holds the address of
     * some memory location.
     * 
     * There are 4 types of pointers.
     */

    type1Pointers();
    type2Pointers();
    type3Pointers();
    type4Pointers();

    return 0;
}

// ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ 
// ------------------------------------------------------------
//                           Type-1
// ------------------------------------------------------------
/**
 * MUTABLE (CHANGEABLE) POINTER pointing to READ/WRITE MEMORY
 * 
 * >>> Syntax: Type* pname = address;
 * 
 * With this pointer type:
 *      • Address can be changed
 *      • Values can be changed
 */
void type1Pointers() {
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
}

// ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ 
// ------------------------------------------------------------
//                           Type-2
// ------------------------------------------------------------
/**
 * MUTABLE (CHANGEABLE) POINTER pointing to READ ONLY MEMORY
 * 
 * >>> Syntax: const Type* pname = address;
 * 
 * The above syntax means that the pointer is given read only access on the given memory type.
 * The memory itself doesn't have to be constant. It's just the pointer is not give all rights, and
 * is given just the read access.
 * 
 * Address of the pointer can be changed and the pointer itself is not constant.
 * 
 * With this pointer type:
 *      • Address CAN be changed
 *      • Values CAN-NOT be changed
 */
void type2Pointers() {
    int A2[10] = {1, 2}; int size2 = 10;
    printArray("A2[10]: ", A2, size2); // A2[10]: {1, 2, 0, 0, 0, 0, 0, 0, 0, 0}

    const int* pname2 = &A2[0]; // copy of the address of first element of the array

    // ERROR!
    // *pname2 = 20; // Cannot change value, because of READ-Only access!

    // We can move to next location or to any other location (within memory) but it will always be read-only
    pname2++; // address moved to the next element --> in case of 'int' 4 would be added to the address

    // ERROR!
    // *(pname2 + 1) = 40; // Even though the address is moved to the next location, but the pointer is still read-only
    printArray("A2[10]: ", A2, size2); // A2[10]: {20, 30, 40, 0, 0, 0, 0, 0, 0, 0} --> notice the 3rd element
}

// ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ 
// ------------------------------------------------------------
//                           Type-3
// ------------------------------------------------------------
/**
 * IMMUTABLE (CONSTANT) POINTER pointing to READ/WRITE MEMORY
 * 
 * >>> Syntax: Type* const pname = address;
 * 
 * All static arrays are of this type!
 * 
 * With this pointer type:
 *      • Address CAN-NOT be changed
 *      • Values CAN be changed
 */
void type3Pointers() {

    int A3[10] = {1, 2}; int size3 = 10;
    printArray("A3[10]: ", A3, size3); // A2[10]: {1, 2, 0, 0, 0, 0, 0, 0, 0, 0}

    int* const pname3 = &A3[0]; // copy of the address of first element of the array

    *pname3 = 30; // values at the address can be changed
    printArray("A3[10]: ", A3, size3); // A2[10]: {30, 2, 0, 0, 0, 0, 0, 0, 0, 0} --> Notice change in the 1st element

    *(pname3 + 1) = 90; // But the addresses can be modified using this pointer
    printArray("A3[10]: ", A3, size3); // A2[10]: {30, 90, 0, 0, 0, 0, 0, 0, 0, 0} --> Notice change in the 2nd element

    // ERROR!
    // pname3++; // Address cannot be changed    
}

// ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ 
// ------------------------------------------------------------
//                           Type-4
// ------------------------------------------------------------
/**
 * IMMUTABLE (CONSTANT) POINTER pointing to READ-only MEMORY
 * 
 * >>> Syntax: const Type* const pname = address;
 * 
 * With this pointer type:
 *      • Address CAN-NOT be changed
 *      • Values CAN-NOT be changed
 */
void type4Pointers() {
    int A4[10] = {1, 2}; int size4 = 10;
    printArray("A4[10]: ", A4, size4); // A2[10]: {1, 2, 0, 0, 0, 0, 0, 0, 0, 0}

    const int* const pname4 = &A4[0]; // copy of the address of first element of the array

    // ERROR!
    // *pname4 = 20; // Cannot change value at a certain address!

    // ERROR!
    // pname4++; // Cannot change the address itself!

    cout << *pname4 << endl;
    cout << *(pname4 + 1) << endl;
}
