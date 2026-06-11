#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

ll mod = 1000000007;

ll bigmod(ll a, ll b, ll mod)
{
    if (b == 0) return 1;
    ll x = bigmod(a, b / 2, mod);
    x = (x * x) % mod;
    if (b % 2) x = (x * (a % mod)) % mod;
    return x;
}

int main( )
{
    int n, i, j, k;
    map<int, int> mp;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> j;
        mp[j]++;
    }
    for (i = 1; i <= n; i++) {
        j = abs((i - 1) - (n - i));
        mp[j]--;
        if (mp[j] < 0) {
            cout << "0\n";
            return 0;
        }
    }
    cout << bigmod(2, n / 2, mod) << '\n';
    return 0;
}
