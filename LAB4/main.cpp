#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
    vector<int> vec = { 5, 1, 9, 3, 7 };
    Sort sorter(vec.data(), vec.size());

    cout << "Inainte de sortare: ";
    sorter.Print();

    sorter.InsertSort(true);
    cout << "Sortare InsertSort (ascendent): ";
    sorter.Print();

    sorter.QuickSort(false);
    cout << "Sortare QuickSort (descendent): ";
    sorter.Print();

    sorter.BubbleSort(true);
    cout << "Sortare BubbleSort (ascendent): ";
    sorter.Print();

    cout << "Numar de elemente: " << sorter.GetElementsCount() << endl;

    int index = 2;
    cout << "Elementul de la indexul " << index << " este: " << sorter.GetElementFromIndex(index) << endl;

    Sort sorter2 = { 10, 4, 8, 6, 2 }; 

    cout << "Inainte de sortare (lista de initializare): ";
    sorter2.Print();

    sorter2.InsertSort(false);
    cout << "Sortare InsertSort (descendent): ";
    sorter2.Print();

    sorter2.QuickSort(true);
    cout << "Sortare QuickSort (ascendent): ";
    sorter2.Print();

    return 0;
}
