#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

bool isValidFruit(std::vector<std::string> v, std::string n)
{
    for (int i = 0; i <= v.size(); i++)
    {
        if (n == v[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::ifstream infile1;
    infile1.open("warehouse1.txt");
    std::vector<std::string> v;
    
    if (infile1.is_open())
    {
        std::string f;
        while (infile1 >> f)
        {
            v.push_back(f);
        }
        infile1.close();
    }
    
    std::ifstream infile2;
    infile2.open("warehouse2.txt");
    
    if (infile2.is_open())
    {
        std::string f;
        while (infile2 >> f)
        {
            if (isValidFruit(v, f))
            {
                v.push_back(f);
            }
        }
        infile2.close();
    }
    std::ofstream outfile;
    
    outfile.open("output.txt");
    if (outfile.is_open())
    {
        for (int i = 0; i <= v.size(); i++)
        {
            outfile << v[i] << std::endl;
        }
    }
    outfile.close();
    return 0;
}