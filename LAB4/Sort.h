#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>
#include <time.h>
#include <cstdarg>
#include <cstdlib>
#include <cstring>

using namespace std;
class Sort
{
    vector<int> numbers;

public:
    // add constuctors
    Sort(int count, int min, int max);
    Sort(initializer_list<int> list); 
    Sort(int* vector, int size);
    Sort(int count, ...);
    Sort(char* string);          

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

