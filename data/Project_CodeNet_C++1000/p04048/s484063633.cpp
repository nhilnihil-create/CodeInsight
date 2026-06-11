#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#define pb push_back
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define l first
#define r second
#define int long long

using namespace std;

const int maxn = 5e3 + 2, mod = 998244353, inf = 4e18;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    cout << 3 * (n - __gcd(n, x));
    return 0;
}
