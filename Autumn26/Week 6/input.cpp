#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    std::ifstream infile;
    infile.open("input.txt");

    if (infile.is_open())
    {
        std::string tmp;
        std::vector<std::string> v;

        while(infile >> tmp)
        {
            v.push_back(tmp);
        }
    infile.close();

    for (int i = 0; i <= v.size(); i++)
        {
            std::cout << v[v.size() - i] << std::endl;
        }
    }
}