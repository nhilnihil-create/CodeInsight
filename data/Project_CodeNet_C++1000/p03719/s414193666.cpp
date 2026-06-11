#include <iostream>
#include <iomanip>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a <= c && c <= b ? "Yes" : "No") << endl;
    return 0;
}