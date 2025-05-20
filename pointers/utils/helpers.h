//
// Created by Hanzla Khalid on 16.5.2025.
//

#ifndef HELPERS_H
#define HELPERS_H

// void ShowArray(int A[], const int size);

void ShowArray(int*, int);
void ShowArrayWithMsg(std::string, int*, const int);

// Helping Function
void Swap(int &A, int &B);

// Helping Function
void SortIntArrayAsc(int A[], int size);

// Helping Function
void SortIntArrayDesc(int A[], int size);

// Helping Function
void SortIntArray(int A[], const int size, const bool ascending = true);

int* LoadIntDataFromFile(std::string, int &);

#endif //HELPERS_H
