#include <iostream>
using namespace std;

int main()
{
    int i;
    int n = 50, j = 0, up = 100, low = 0;
    cout << "If the value is smaller than yours, please entre 0.";
    cout << "If the value is larger than yours, please entre 1.";
    cout << "If the value is the same as yours, please entre 2." << endl;
    while (j < 1)
    {
        cout << n << endl;
        cin >> i;
        if (i == 2)
        {
            cout << "The number is " << n << '.';
            j += 1;
        }
        if (i == 0)
        {
            low = n;
        }
        if (i == 1)
        {
            up = n;
        }
        n = 0.5 * (up + low);
    }
    return 0;
}