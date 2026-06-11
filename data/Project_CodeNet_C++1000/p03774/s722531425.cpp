#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, n, k) for (int i = n; i < k; i++)
#define P(p) cout << (p) << endl;
#define sP(p) cout << setprecision(15) << fixed << p << endl;
#define vi vector<int>
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        P(v[i]);
#define printt(a, b) cout << a << " " << b << endl;
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v, c;
    vi ans(100, 0);
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        c.push_back(make_pair(a, b));
    }
    rep(i, n)
    {
        ll mini = 1e18;
        rep(j, m)
        {
            ll dist = abs(v[i].first - c[j].first) + abs(v[i].second - c[j].second);
            if (mini > dist)
            {
                ans[i] = j + 1;
                mini = dist;
            }
        }
    }
    rep(i, n)
    {
        P(ans[i]);
    }
}

int main()
{
    solve();
    return 0;
}
