#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int x, t;
    cin >> x >> t;
    int ans = max(x - t, 0);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}