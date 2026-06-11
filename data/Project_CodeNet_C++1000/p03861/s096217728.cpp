#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    a--;
    if (b >= 0)
        b = b / x + 1;
    else
        b = 0;
    if (a >= 0)
        a = a / x + 1;
    else
        a = 0;
    cout << b - a << endl;
    return 0;
}