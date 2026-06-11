#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll n, m, a, b, c, dist[2000];
vector<pair<ll, ll>> x[3000];
void solve()
{
    dist[0] = 0;
    ll P = dist[n - 1];
    for (int i = 0; i < 8 * n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (pair<ll, ll> k : x[j])
                dist[k.first] = max(dist[k.first], dist[j] + k.second);
        }
        if (P != dist[n - 1] && i >= 5 * n)
        {
            cout << "inf" << endl;
            return;
        }
        P = dist[n - 1];
    }
    cout << dist[n - 1] << endl;
    return;
}
main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    rep(i, m)
    {
        cin >> a >> b >> c;
        a--, b--;
        x[a].push_back(make_pair(b, c));
    }
    rep(i, n) dist[i] = -(1LL << 60);
    solve();
    return 0;
}