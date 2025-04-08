#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <cstdlib>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return static_cast<int>(a + b);
}

int Math::Add(double a, double b, double c)
{
    return static_cast<int>(a + b + c);
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return static_cast<int>(a * b);
}

int Math::Mul(double a, double b, double c)
{
    return static_cast<int>(a * b * c);
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* sir1, const char* sir2)
{
    if (sir1 == nullptr || sir2 == nullptr)
    {
        return nullptr;
    }

    size_t len1 = strlen(sir1);
    size_t len2 = strlen(sir2);

    char* result = new char[len1 + len2 + 1];

    if (result)
    {
        strcpy_s(result, len1 + len2 + 1, sir1);
        strcat_s(result, len1 + len2 + 1, sir2);
    }

    return result;
}
