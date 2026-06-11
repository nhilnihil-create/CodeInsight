// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (abs(n - m) >= 2)
        cout << 0 << endl;
    else
    {
        ll ans = 1;
        rep(i, n) ans = ans % mod * (i + 1);
        rep(i, m) ans = ans % mod * (i + 1);
        if (abs(n - m) == 0)
            ans = ans % mod * 2;
        ans %= mod;
        cout << ans << endl;
    }
}

int main()
{
    // srand((unsigned)time(NULL));
    // int t = clock();
    solve();
    // double et = 1.0 * (clock() - t) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}