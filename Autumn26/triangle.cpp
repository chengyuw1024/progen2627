#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cout << "entre three side lengths" << endl;
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "the triangle is invalid" << endl;
        return 0;
    }
    if (a == b || a == c || b == c)
    {
        if ( a == b && a == c)
        {
            cout << "the triangle is equilateral" << endl;
        }
        else
        {
            cout << "the triangle is isosceles" << endl;
        }
    }
    else
    {
        cout << "the triangle is scalene" << endl;
    }
    double s = 0.5 * (a + b + c);
    cout << "the perimeter of the triangle is " << a + b + c << endl;
    cout << "the area of the triangle is " << pow(s * (s - a) * (s - b) * (s - c), 0.5) << endl;
    return 0;
}