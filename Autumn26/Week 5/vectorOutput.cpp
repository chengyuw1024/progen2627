#include <iostream>
#include<vector>

void viewVector (const std::vector<int>& vin)
{
    for (int i = 0; i < vin.size(); i++)
    {
        std::cout << vin[i] << ' ';
    }
    std::cout << std::endl;
}

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout)
{
    vout = vin1;
    if (vin2.size() != 0)
    {
        for (int i = 0; i < vin2.size(); i++)
        {
            vout.push_back(vin2[i]);
        }
    }
}

void filter_v(const std::vector<int>& vin, int t, std::vector<int>& vout)
{
    if (vin.size() != 0)
    {
        vout.clear();
        for (int i = 0; i < vin.size(); i++)
        {
            if (vin[i] >= t)
            {
                vout.push_back(vin[i]);
            }
        }
    }
}

int main()
{
    std::vector<int> vin1{3, 5, 2, 7, 9, 4};
    std::vector<int> vin2{8, 1, 3, 6};
    std::vector<int> vout;
    append_vectors(vin1, vin2, vout);
    viewVector(vout);
    filter_v(vin1, 4, vout);
    viewVector(vout);
}