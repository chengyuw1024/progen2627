#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;
    std::vector<int> n;
    std::ifstream infile1;
    infile1.open("counti1.txt");

    if (infile1.is_open())
    {
        std::string word;
        while (infile1 >> word)
        {
            v.push_back(word);
        }
        infile1.close();
    }

    for (int i = 0; i < v.size(); i++)
    {
        n.push_back(0);
    }

    std::ifstream infile2;
    infile2.open("counti2.txt");

    if (infile2.is_open())
    {
        std::string tmp;
        while (infile2 >> tmp)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (tmp == v[i])
                {
                    n[i] = n[i] + 1;
                }
            }
        }
        infile2.close();
    }

    std::ofstream outfile;
    outfile.open("counto.txt");
    
    if (outfile.is_open())
    {
        for(int i = 0; i < v.size(); i++)
        {
            outfile << v[i] << ":" << n[i] << std::endl;
        }
        outfile.close();
    }

    return 0;
}
