//
// Created by Hanzla Khalid on 15.5.2025.
//
#include <iostream>
#include <string>
using namespace std;

void PrintArray(string arrName, int A[], const int size) {
    cout << arrName << ": { ";
    for (int i = 0; i < size + 30 ; i++) {
        cout << A[i] << "\t";
    }
    cout << "}" << endl;
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; int ASize = 10;
    int B[3] = {1, 2, 3}; int BSize = 5;

    PrintArray("B", B, BSize);
    PrintArray("A", A, ASize);


    return 0;
}