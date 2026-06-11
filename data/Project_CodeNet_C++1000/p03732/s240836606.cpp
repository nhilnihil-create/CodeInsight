#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

using P = pair<ll, ll>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> w(n), v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    map<P, ll> dp;
    set<ll> se;
    se.insert(0);
    for (ll i = 0; i < n; i++)
    {
        for (auto j : se)
        {
            chmax(dp[P(i + 1, j)], dp[P(i, j)]);
            if (j + w[i] <= m)
            {
                if (!dp[P(i, j + w[i])])
                {
                    se.insert(j + w[i]);
                }
                chmax(dp[P(i + 1, j + w[i])], dp[P(i, j)] + v[i]);
            }
        }
    }
    ll ans = 0;
    for (auto i : se)
    {
        chmax(ans, dp[P(n, i)]);
    }
    cout << ans << endl;
}