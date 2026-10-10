#include <iostream>

int main()
{
    int s1, s2;
    std::cout << "what is the length of the first side?";
    std::cin >> s1; 
    std::cout << "what is the length of the second side?";
    std::cin >> s2;
    std::cout << "the parametre of the rectangle is " << 2 * (s1 + s2) << std::endl;
    std::cout << "the area of the rectangle is " << s1 * s2 << std::endl;
}