#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

void solve()
{
    int k, s;
    cin >> k >> s;
    int ans = 0;
    rep(x, k + 1) rep(y, k + 1)
    {
        int z = s - x - y;
        if (!(0 <= z && z <= k))
            continue;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}