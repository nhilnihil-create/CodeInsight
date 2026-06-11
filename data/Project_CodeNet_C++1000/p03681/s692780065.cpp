#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

constexpr ll mod = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    if (abs(n - m) > 1)
    {
        cout << 0 << endl;
        return 0;
    }

    ll ans;
    if (abs(n - m) == 1)
        ans = max(n, m);
    else
        ans = 2;

    const int t = min(n, m);
    for (int i = 2; i <= t; ++i)
        ans = ans * i % mod, ans = ans * i % mod;

    cout << ans << endl;
}