#include <iostream>

int main()
{
    int n, absv;
    std::cout << "please entre a number";
    std::cin >> n;
    absv = n;
    if (n < 0)
    {
        absv = -absv;
    }
    std::cout << '|' << n << "|=" << absv;
}