#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    rep(i, 2 * h) cout << c[i / 2] << endl;
}
int main(void)
{
    solve();
}
