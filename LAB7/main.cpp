#include <iostream>
#include "tree.h"
using namespace std;

constexpr float operator"" _Kelvin(unsigned long long kelvin) {
    return static_cast<float>(kelvin - 273.15);
}

constexpr float operator"" _Fahrenheit(unsigned long long fahrenheit) {
    return static_cast<float>((fahrenheit - 32) * 5.0 / 9.0);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << "300 Kelvin in grade Celsius: " << a << "C" << endl;
    cout << "120 Fahrenheit in grade Celsius: " << b << "C" << endl;

    Tree<int> tree;
    auto root = tree.add_node(nullptr, 1);
    auto child1 = tree.add_node(root, 2);
    auto child2 = tree.add_node(root, 3);
    tree.add_node(child1, 4);
    tree.add_node(child1, 5);
    tree.add_node(child2, 6);

    cout << "Numarul total de noduri: " << tree.count(nullptr) << endl;

    cout << "Valoarea radacinii: " << tree.get_node(nullptr)->value << endl;

    auto found_node = tree.find([](const int& value) { return value == 5; });
    if (found_node) {
        cout << "Nod gasit cu valoarea: " << found_node->value << endl;
    }
    else {
        cout << "Nodul cu valoarea 5 nu a fost gasit." << endl;
    }

    tree.insert(child2, 7, 0);
    cout << "Dupa inserarea lui 7 in child2, numarul total de noduri: " << tree.count(nullptr) << endl;

    tree.sort(root);
    cout << "Copiii radacinii dupa sortare: ";
    
    for (int i = 0; i < root->children_count; i++) {
        cout << root->children[i]->value << " ";
    }
    cout << std::endl;

    tree.delete_node(child1);
    cout << "Dupa stergerea lui child1, numarul total de noduri: " << tree.count(nullptr) << endl;

    return 0;
}