#include <iostream>
#include <cstring>
#include <cctype>
#include <stdexcept>
#include "Number.h"

using namespace std;

static int charToValue(char c) {
    if (c >= '0' && c <= '9') 
        return c - '0';
    if (c >= 'A' && c <= 'F') 
        return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f') 
        return 10 + (c - 'a');
    return 0;
}

static char valueToChar(int val) {
    if (val >= 0 && val <= 9) 
        return '0' + val;
    if (val >= 10 && val <= 15) 
        return 'A' + (val - 10);
    return '0';
}

Number::Number(const char* value, int base) {
    if (base < 2 || base > 16) {
        cout<<"Base must be between 2 and 16";
    }

    baza = base;
    int length = 0;
	while (value[length] != '\0') {
		length++;
	}
    valoare = new char[length + 1];
    for (int i = 0; i < length; i++) {
		valoare[i] = value[i];
    }
	valoare[length] = '\0';
}

Number::Number(int value) {
    baza = 10;
    if (value == 0) {
        valoare = new char[2];
        valoare[0] = '0';
        valoare[1] = '\0';
        return;
    }

    char buffer[32];
    int i = 0;
    while (value > 0) {
        buffer[i++] = '0' + (value % 10);
        value /= 10;
    }
    buffer[i] = '\0';

    // Reverse the string
    valoare = new char[i + 1];
    for (int j = 0; j < i; j++) {
        valoare[j] = buffer[i - 1 - j];
    }
    valoare[i] = '\0';
}

Number::Number(const char* value) : Number(value, 10) {}

Number::Number(const Number& other) {
    baza = other.baza;
    int length = 0;
    while (other.valoare[length] != '\0')
    {
		length++;
    }
    valoare = new char[length + 1];
    for (int i = 0; i < length; i++) {
		valoare[i] = other.valoare[i];
    }
	valoare[length] = '\0';
}

Number::Number(Number&& other) noexcept {
    baza = other.baza;
    valoare = other.valoare;
    other.valoare = nullptr;
    other.baza = 0;
}

Number::~Number() {
    delete[] valoare;
}

Number& Number::operator=(const Number& n) {
    if (this != &n) {
        int length = 0;
        while (n.valoare[length] != '\0') {
			length++;
        }
        char* newValoare = new char[length + 1];
        for (int i = 0; i < length; i++) {
			newValoare[i] = n.valoare[i];
        }
		newValoare[length] = '\0';

        delete[] valoare;
		valoare = newValoare;
        baza = n.baza;
    }
    return *this;
}

Number& Number::operator=(Number&& n) noexcept {
    if (this != &n) {
        delete[] valoare;
        baza = n.baza;
        valoare = n.valoare;
        n.valoare = nullptr;
        n.baza = 0;
    }
    return *this;
}

Number& Number::operator=(const char* value) {
	int length = 0;
    while (value[length] != '\0')
    {
		length++;
    }
    char* newValoare = new char[length + 1];
    for (int i = 0; i < length; i++) {
		newValoare[i] = value[i];
    }
	newValoare[length] = '\0';
	delete[] valoare;
	valoare = newValoare;
    baza = 10;
    return *this;
}

Number& Number::operator=(int value) {
    *this = Number(value);
    return *this;
}

Number operator+(const Number& n1, const Number& n2) {
    int num1 = 0;
    for (int i = 0; n1.valoare[i] != '\0'; i++) {
        num1 = num1 * n1.baza + charToValue(n1.valoare[i]);
    }

    int num2 = 0;
    for (int i = 0; n2.valoare[i] != '\0'; i++) {
        num2 = num2 * n2.baza + charToValue(n2.valoare[i]);
    }

    int sum = num1 + num2;
    int newBase = max(n1.baza, n2.baza);

    if (sum == 0) {
        return Number("0", newBase);
    }

    char buffer[32];
    int i = 31;
    buffer[i] = '\0';
    i--;

    while (sum > 0) {
        int digit = sum % newBase;
        buffer[i] = valueToChar(digit);
        sum /= newBase;
        i--;
    }

    return Number(&buffer[i + 1], newBase);
}

Number operator-(const Number& n1, const Number& n2) {
    int num1 = 0;
    for (int i = 0; n1.valoare[i] != '\0'; i++) {
        num1 = num1 * n1.baza + charToValue(n1.valoare[i]);
    }

    int num2 = 0;
    for (int i = 0; n2.valoare[i] != '\0'; i++) {
        num2 = num2 * n2.baza + charToValue(n2.valoare[i]);
    }

    int diff = num1 - num2;
    int newBase = max(n1.baza, n2.baza);

    if (diff == 0) {
        return Number("0", newBase);
    }

    char buffer[32];
    int i = 31;
    buffer[i] = '\0';
    i--;

    while (diff > 0) {
        int digit = diff % newBase;
        buffer[i] = valueToChar(digit);
        diff /= newBase;
        i--;
    }

    return Number(&buffer[i + 1], newBase);
}

Number& Number::operator+=(const Number& n) {
    *this = *this + n;
    return *this;
}

bool Number::operator>(const Number& n) const {
    int num1 = 0;
    for (int i = 0; valoare[i] != '\0'; i++) {
        num1 = num1 * baza + charToValue(valoare[i]);
    }

    int num2 = 0;
    for (int i = 0; n.valoare[i] != '\0'; i++) {
        num2 = num2 * n.baza + charToValue(n.valoare[i]);
    }

    return num1 > num2;
}

bool Number::operator<(const Number& n) const {
    return !(*this > n) && !(*this == n);
}

bool Number::operator>=(const Number& n) const {
    return !(*this < n);
}

bool Number::operator<=(const Number& n) const {
    return !(*this > n);
}

bool Number::operator==(const Number& n) const {
    int num1 = 0;
    for (int i = 0; valoare[i] != '\0'; i++) {
        num1 = num1 * baza + charToValue(valoare[i]);
    }

    int num2 = 0;
    for (int i = 0; n.valoare[i] != '\0'; i++) {
        num2 = num2 * n.baza + charToValue(n.valoare[i]);
    }

    return num1 == num2;
}

bool Number::operator!=(const Number& n) const {
    return !(*this == n);
}

char Number::operator[](int i) const {
    if (i < 0 || i >= GetDigitsCount()) {
        cout << "Index out of range";
    }
    return valoare[i];
}

Number& Number::operator--() {
    int length = GetDigitsCount();
    if (length <= 1) {
        delete[] valoare;
        valoare = new char[1];
        valoare[0] = '\0';
        return *this;
    }

    char* newValoare = new char[length];
    //strcpy(newValoare, valoare + 1);
    for (int i = 1; i < length; i++) {
        newValoare[i - 1] = valoare[i];
    }
	newValoare[length - 1] = '\0';

    delete[] valoare;
    valoare = newValoare;
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    int length = GetDigitsCount();
    if (length <= 1) {
        delete[] valoare;
        valoare = new char[1];
        valoare[0] = '\0';
        return temp;
    }

    char* newValoare = new char[length];
	for (int i = 0; i < length - 1; i++) {
		newValoare[i] = valoare[i];
	}
    newValoare[length - 1] = '\0';
    delete[] valoare;
    valoare = newValoare;
    return temp;
}

void Number::SwitchBase(int newBase) {
    if (newBase < 2 || newBase > 16) {
        cout<<"Base must be between 2 and 16";
    }

    int decimal = 0;
    for (int i = 0; valoare[i] != '\0'; i++) {
        decimal = decimal * baza + charToValue(valoare[i]);
    }

    if (decimal == 0) {
        delete[] valoare;
        valoare = new char[2];
        valoare[0] = '0';
        valoare[1] = '\0';
        baza = newBase;
        return;
    }

    char buffer[32];
    int i = 31;
    buffer[i] = '\0';
    i--;

    while (decimal > 0) {
        int digit = decimal % newBase;
        buffer[i] = valueToChar(digit);
        decimal /= newBase;
        i--;
    }

	int newLength = 31 - i;

    delete[] valoare;
    valoare = new char[newLength + 1];
    for (int j = 0; j < newLength; j++) {
		valoare[j] = buffer[i + 1 + j];
    }
	valoare[newLength] = '\0';
    baza = newBase;
}

void Number::Print() const {
    cout << "Number: " << valoare << " (base " << baza << ")" << endl;
}

int Number::GetDigitsCount() const {
    int count = 0;
	while (valoare[count] != '\0') {
		count++;
	}
    return count;
}

int Number::GetBase() const {
    return baza;
}