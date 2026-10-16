#include <iostream>

int main()
{
    int n ;
    int sum = 0, i = 0;
    while (i == 0)
    {
        std::cout << "entre a number";
        std::cin >> n;
        if (n != 0)
        {
            sum += n;
            std::cout << " The number so far is " << sum << std::endl;
        }
        else
        {
            i += 1;
        }
    }
}