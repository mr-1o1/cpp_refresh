//
// Created by Hanzla Khalid on 16.5.2025.
//
#include <iostream>
#include <fstream>
#include "helpers.h"
using namespace std;


// ==============================================================================
void ShowArray(int* A, const int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    } cout << endl;
}

// ==============================================================================
void ShowArrayWithMsg(string msg, int* A, const int size) {
    if (msg.length() > 0)
        cout << msg;
    ShowArray(A, size);
}

// ==============================================================================
void Swap(int &A, int &B) {
    const int temp = A; A = B; B = temp;
}

// ==============================================================================
void SortIntArrayAsc(int A[], int size) {
    for (int t = 0; t < size - 1; t++) {
        for (int i = 0; i < size - 1; i++) {
            if (A[i] > A[i + 1]) {
                Swap(A[i], A[i + 1]);
            }
        }
    }
}

// ==============================================================================
void SortIntArrayDesc(int A[], int size) {
    for (int t = 0; t < size - 1; t++) {
        for (int i = 0; i < size - 1; i++) {
            if (A[i] < A[i + 1]) {
                Swap(A[i], A[i + 1]);
            }
        }
    }
}

// ==============================================================================
void SortIntArray(int A[], const int size, const bool ascending) {
    if (ascending)
        SortIntArrayAsc(A, size);
    else
        SortIntArrayDesc(A, size);
}

// ==============================================================================
int* LoadIntDataFromFile(string filename, int &size) {
    ifstream Rdr(filename);
    Rdr >> size;

    // create a new variable in Stack segment
    int * arr = new int[size];

    for (int i = 0; i < size; i++) {
        Rdr >> arr[i]; // same as *(arr + i)
    }

    // ShowArrayWithMsg("in Function: ", arr, size); // testing purpose

    // This function's memory will be destroyed but the Heap segmenet memory (created through `new` keyword)
    // will be returned (basically the first address of that memory)
    return arr;
}

