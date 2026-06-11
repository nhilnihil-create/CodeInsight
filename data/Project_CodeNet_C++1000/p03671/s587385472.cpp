#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int a1 = a + b;
    int b1 = a + c;
    int c1 = c + b;
    if (a1 >= b1 && b1 >= c1 || b1 >= a1 && a1 >= c1)
    {
        cout << c1 << endl;
    }
    else if (b1 >= c1 && c1 >= a1 || c1 >= b1 && b1 >= a1)
    {
        cout << a1 << endl;
    }
    else
    {
        cout << b1 << endl;
    }
}