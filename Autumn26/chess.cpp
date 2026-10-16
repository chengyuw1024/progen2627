#include <iostream>
using namespace std;

bool isValidMovement (int a, int b, int c, int d)
{
    if (a < 1 || a > 8 || b < 1 || b > 8 || c < 1 || c > 8 || d < 1 || d > 8)
    {
        return 0;
    }
    if (a - c == 1 || a - c == -1)
    {
        if (b - d == 2 || b - d == -2)
        {
            return 1;
        }
    }
    if (a - c == 2 || a - c == -2)
    {
        if (b - d == 1 || b - d == -1)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int a, b, c, d;
    cout << "entre the x-coordinate of the source square" << endl;
    cin >> a;
    cout << "entre the y-coordinate of the source square" << endl;
    cin >> b;
    cout << "entre the x-coordinate of the destination square" << endl;
    cin >> c;
    cout << "entre the y-coordinate of the destination square" << endl;
    cin >> d;
    if (isValidMovement(a, b, c, d))
    {
        cout << "the movement is valid" << endl;
    }
    else
    {
        cout << "the movement is invalid" << endl;
    }
    return 0;
}