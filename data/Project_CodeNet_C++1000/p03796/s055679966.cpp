#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    ll d = 1e9 + 7;
    ll p = 1;
    for (ll i = 1; i <= n; i++)
    {
        p *= i;
        p %= d;
    }
    cout << p << endl;
    return 0;
}