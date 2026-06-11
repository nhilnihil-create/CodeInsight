#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    int m;
    cin >> m;
    vector<int> p(m), x(m);
    rep(i, m) cin >> p[i] >> x[i], --p[i];
    int all = accumulate(t.begin(), t.end(), 0);
    rep(i, m) cout << all - t[p[i]] + x[i] << endl;
}
int main(void)
{
    solve();
}
