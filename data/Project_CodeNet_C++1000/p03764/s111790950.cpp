#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x += a * 1LL * i;
        x -= a * 1LL * (n - 1 - i);
        x = (x % mod + mod) % mod;
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        y += a * 1LL * i;
        y -= a * 1LL * (m - 1 - i);
        y = (y % mod + mod) % mod;
    }
    cout << (x * 1LL * y) % mod << endl;
    return 0;
}