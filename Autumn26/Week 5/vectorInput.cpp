#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin)
{
    if (vin.size() == 0)
    {
        return -1;
    }
    double min = vin[0];
    if (vin.size() == 0)
    {
    return min;
    }
    for (int i = 1; i < vin.size(); i++)
    {
        if (vin[i] < min)
        {
            min = vin[i];
        }
    }
    return min;
}   

int search_vector(int n, const std::vector<double>& vin)
{
    for (int i = 0; i < vin.size(); i++)
    {
        if (n == vin[i])
        return i;
    }
    return -1;
}

int main()
{
    std::vector<double> vin{5, 4, 7, 9, 1};
    std::cout << min_vector_element(vin) << std::endl;
    std::cout << search_vector(1, vin) << std::endl;

}