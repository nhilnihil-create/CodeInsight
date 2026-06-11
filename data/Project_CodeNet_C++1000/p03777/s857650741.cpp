#include <iostream>
#include <iomanip>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

int main()
{
    char a, b;
    cin >> a >> b;
    if (a == 'H')
    {
        cout << b << endl;
    }
    else if (b == 'H')
    {
        cout << 'D' << endl;
    }
    else
    {
        cout << 'H' << endl;
    }
    return 0;
}