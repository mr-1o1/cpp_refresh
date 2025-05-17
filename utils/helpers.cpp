//
// Created by Hanzla Khalid on 16.5.2025.
//
#include <iostream>
#include "helpers.h"
using namespace std;

void ShowArray(int* A, const int size) {
    cout << "\n=============================================\n";
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    } cout << endl;
}

// Helping Function
void Swap(int &A, int &B) {
    const int temp = A; A = B; B = temp;
}

// Helping Function
void SortIntArrayAsc(int A[], int size) {
    for (int t = 0; t < size - 1; t++) {
        for (int i = 0; i < size - 1; i++) {
            if (A[i] > A[i + 1]) {
                Swap(A[i], A[i + 1]);
            }
        }
    }
}

// Helping Function
void SortIntArrayDesc(int A[], int size) {
    for (int t = 0; t < size - 1; t++) {
        for (int i = 0; i < size - 1; i++) {
            if (A[i] < A[i + 1]) {
                Swap(A[i], A[i + 1]);
            }
        }
    }
}

// Helping Function
void SortIntArray(int A[], const int size, const bool ascending) {
    if (ascending)
        SortIntArrayAsc(A, size);
    else
        SortIntArrayDesc(A, size);
}

