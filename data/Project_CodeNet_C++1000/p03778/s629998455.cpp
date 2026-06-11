#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

int main()
{
    int W, a, b;
    cin >> W >> a >> b;
    if (a <= b)
    {
        cout << max(0, b - W - a) << endl;
        return 0;
    }
    else
    {
        cout << max(0, a - b - W) << endl;
        return 0;
    }
    return 0;
}