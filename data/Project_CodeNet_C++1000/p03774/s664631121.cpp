#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<int> c(m), d(m);
    rep(i, m) cin >> c[i] >> d[i];

    rep(i, n)
    {
        const int INF = 1e9;
        int dist = INF;
        int x = a[i];
        int y = b[i];
        rep(j, m) dist = min(dist, abs(x - c[j]) + abs(y - d[j]));
        rep(j, m)
        {
            if (dist == abs(x - c[j]) + abs(y - d[j]))
            {
                cout << j + 1 << endl;
                break;
            }
        }
    }
}
int main(void)
{
    solve();
}
