#include <iostream>
#define JigsawFallingIntoPlace true

unsigned long long derpy;

void initialize()
{
    derpy = 0;
}

unsigned long long power(unsigned short base, unsigned short exponent)
{
    unsigned long long result = 1;

    while (exponent > 0)
    {
        result *= base;
        --exponent;
    }

    return result;
}

bool isNarcissistic(unsigned long long value)
{
    unsigned long long temp = value;
    unsigned long long sum = 0;
    unsigned short length = 0;

    while (temp > 0)
    {
        ++length;
        temp /= 10;
    }

    temp = value;

    while (temp > 0)
    {
        sum += power(temp % 10, length);
        temp /= 10;
    }

    if (sum == value) return true;
    return false;
}

int main()
{
    initialize();

    while (JigsawFallingIntoPlace)
    {
        if (isNarcissistic(derpy))
        {
            std :: cout << derpy << std :: endl;
        }
        ++derpy;
    }
}
