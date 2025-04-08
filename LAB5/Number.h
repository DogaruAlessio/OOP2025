#pragma once
class Number
{
    char* valoare;
    int baza;

public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int value); // where value is in base 10
    Number(const char* value); // Constructor nou - defaults to base 10
    Number(const Number& others); // copy constructor
    Number(Number&& others) noexcept; // move constructor
    ~Number();

    Number& operator=(const Number& n); // copy assignment
    Number& operator=(Number&& n) noexcept; // move assignment
    Number& operator=(const char* value); // Operator de atribuire nou
    Number& operator=(int value); // Missing in original

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& n);

    bool operator>(const Number& n) const;
    bool operator<(const Number& n) const;
    bool operator>=(const Number& n) const;
    bool operator<=(const Number& n) const;
    bool operator==(const Number& n) const;
    bool operator!=(const Number& n) const;

    char operator[](int i) const;
    Number& operator--();
    Number operator--(int);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};