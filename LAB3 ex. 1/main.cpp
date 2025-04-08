#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Add(5, 5) = " << Math::Add(5, 5) << endl;
    cout << "Add(5, 5, 5) = " << Math::Add(5, 5, 5) << endl;
    cout << "Add(5.5, 5.5) = " << Math::Add(5.5, 5.5) << endl;
    cout << "Add(5.32423, 2.2242, 6.4321) = " << Math::Add(5.32423, 2.2242, 6.4321) << endl;
    cout << "Mul(5, 5) = " << Math::Mul(5, 5) << endl;
    cout << "Mul(5, 5, 5) = " << Math::Mul(5, 5, 5) << endl;
    cout << "Mul(0.5, 7.0) = " << Math::Mul(0.5, 7.0) << endl;
    cout << "Mul(0.25, 2.0, 7.0) = " << Math::Mul(0.25, 2.0, 7.0) << endl;
    cout << "Add(5, 1, 2, 3, 4, 5) = " << Math::Add(5, 1, 2, 3, 4, 5) << endl;

    char* concatenated = Math::Add("abc", "def");
    if (concatenated) {
        cout << "Add(\"abc\", \"def\") = " << concatenated << endl;
        delete[] concatenated;
    }
    else {
        cout << "Add(\"abc\", \"def\") = nullptr" << endl;
    }

    return 0;
}
