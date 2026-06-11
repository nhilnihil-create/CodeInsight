#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n)
    {
        if (i == n - 1)
            ans += t;
        else
            ans += min(a[i + 1] - a[i], t);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}