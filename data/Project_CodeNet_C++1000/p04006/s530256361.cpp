#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;
template <typename T>
void vecin(vector<T> &v, int n = 0)
{
    if (n == 0)
        n = v.size();
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
}
template <typename T>
void vecout(vector<T> &v, int n = 0)
{
    if (n == 0)
        n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        cout << v[i] << " ";
    }
    cout << v[n - 1] << endl;
}


int main()
{
    ciosup;
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    vecin(a);
    ll ans = LLONG_MAX;
    vector<ll> b(n, LLONG_MAX);
    REP(i, n)
    {
        ll temp = i * x;
        REP(j,n){
            b[j] = min(b[j], a[j - i >= 0 ? j - i: j - i + n]);
            temp += b[j];
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
}