#include <iostream>

bool isLeap(int i)
{
    if (i % 4 == 0)
    {
        if (i % 100 == 0)
        {
            if (i % 400 == 0)
            {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int main()
{
    int y;
    std::cout << "please entre a year" << std::endl;
    std::cin >> y;
    if (isLeap(y))
    {
        std::cout << y << " is a leap year";
    }
    else
    {
        std::cout << y << " is not a leap year";
    }
}