#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    string o, b;
    cin >> o >> b;
    int n = min(o.size(), b.size());
    repi(i, n, 0)
    {
        cout << o[i] << b[i];
    }
    if (o.size() - n)
    {
        cout << o[n];
    }
    else if (b.size() - n)
    {
        cout << b[n];
    }
    cout << endl;
    return 0;
}