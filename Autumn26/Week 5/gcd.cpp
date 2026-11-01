#include <iostream>

int gcd(int a, int b)
{
    int c; 
    while (b != 0)
    {
        c = b;
        b = a % c;
        a = c;
    }
    return a;
}

int main()
{
    std::cout << gcd(48, 18) << std::endl;
}