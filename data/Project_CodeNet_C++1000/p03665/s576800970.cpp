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

#pragma endregion Macros

ll f(ll n){
    ll res = 1;
    while(n>0){
        res *= n--;
    }
    return res;
}

ll c(ll k, ll n){
    if (k < n) {
        return 0;
    }

    if (n >= k / 2) n = k - n;

 //   ll k2 = k;
    ll res = 1;
    rep(i, n) res *= k--;
    for (int i = 1; i <= n; i++) {
        res /= i;
    }
 //   cerr << k2 << "C" << n << "=" << res << endl;
    return res;
}

int main()
{
    int N,P;
    cin >> N >> P;
    vector<int> A(N);

    int o=0;
    int e = 0;
    rep(i, N) {
        int a;
        cin >> a;
        if (a % 2 == 0)
            e++;
        else
            o++;
    }

    if(P==1 && o==0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;

    for(int i=1;i<=e;i++){
        ans *= 2;
    }

    if(P==1){
        ll x = 0;
        for (int i = 1; i <= o; i += 2) {
            x += c(o, i);
        }
        ans *= x;
    } else {
        ll x = 0;
        for (int i = 0; i <= o; i += 2) {
            x  += c(o, i);
        }
        ans *= x;
    }

    cout << ans << endl;
}
