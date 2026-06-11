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

template <typename T>
void compression(vector<T> &v)
{
    vector<T> t = v;
    sort(ALL(t));
    t.erase(unique(ALL(t)), t.end());
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = distance(t.begin(), lower_bound(ALL(t), v[i]));
    }
}

struct BIT // 0-indexed
{
    ll n;
    vector<ll> bit;
    // 初期化
    void init(ll n_input)
    {
        n = n_input + 1;
        bit.resize(n + 1, 0);
    }
    // v[0] + ... + v[k-1]
    ll sum(ll k)
    {
        ll res = 0;
        for (ll i = k - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            res += bit[i];
        }
        return res;
    }
    // v[i] + ... + v[j]
    ll sum_between(ll i, ll j)
    {
        return i <= j ? sum(j + 1) - sum(i) : 0;
    }
    // v[k] += x
    void add(ll k, ll x)
    {
        for (ll i = k; i < n; i |= i + 1)
        {
            bit[i] += x;
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] -= k;
        a[i] += a[i - 1];
    }
    vector<P> b(n + 1);
    for (ll i = 0; i <= n; i++)
    {
        b[i] = P(a[i], i);
    }
    sort(ALL(b));
    BIT bit;
    bit.init(n + 1);
    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        ans += bit.sum(b[i].second + 1);
        bit.add(b[i].second, 1);
    }
    cout << ans << endl;
}