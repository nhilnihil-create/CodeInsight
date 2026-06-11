#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

int main()
{
    int N;
    ll x;
    cin >> N >> x;

    vector<ll> a(N+2);
    rep(i, N) cin >> a[i+1];

    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        // a[i-1]との和がxより大きい場合、a[i]を減らす
        if(a[i-1]+a[i] > x){
            ll tmp = (a[i - 1] + a[i])-x;
            ans += tmp;
            a[i] -= tmp;
        }

        // a[i+1]との和がxより大きい場合、a[i+1]から減らせるだけ減らす
        // 減らせなくなったらa[i]から減らす
        if(a[i+1] + a[i] > x){
            ll tmp = (a[i + 1] + a[i])-x;

            if (a[i + 1] >= tmp){
                a[i + 1] -= tmp;
            }else{
                a[i] -= (tmp - a[i + 1]);
                a[i + 1] = 0;
            }
            ans += tmp;
        }
    }

    cout << ans << endl;
}
