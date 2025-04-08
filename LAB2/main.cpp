#include <iostream>
#include "NumberList.h"

int main()
{
    NumberList list;

    list.Init();  // Inițializează lista

    list.Add(5);
    list.Add(3);
    list.Add(8);
    list.Add(1);
    list.Add(9);

    std::cout << "Lista înainte de sortare: ";
    list.Print();

    list.Sort();

    std::cout << "Lista după sortare: ";
    list.Print();

    list.Add(6);
    list.Add(7);
    list.Add(2);
    list.Add(4);
    list.Add(10);

    if (!list.Add(11)) {
        std::cout << "Nu se mai pot adăuga numere, lista este plină." << std::endl;
    }

    std::cout << "Lista finală: ";
    list.Print();

    return 0;
}