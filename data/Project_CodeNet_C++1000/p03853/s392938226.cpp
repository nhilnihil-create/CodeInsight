#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    rep(i, h)
    {
        rep(j, 2) cout << c[i] << endl;
    }
}

int main()
{
    solve();
    return 0;
}