#include <iostream>
using namespace std;

int main()
{
    cout << "please entre the size of the table" << endl;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int m = 1; m <= n; m++)
        {
            cout << m * i << ' ';
            if (m * i < 10)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}