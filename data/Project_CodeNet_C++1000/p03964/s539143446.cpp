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
    cin >> N;

    vector<ll> T(N),A(N);
    rep(i, N) cin >> T[i] >> A[i];

    ll t = T[0];
    ll a = A[0];

    for(int i=1;i<N;i++){
        ll n = (t + T[i] - 1) / T[i];
        n = max(n, (a + A[i] - 1) / A[i]);

        t = T[i]*n;
        a = A[i]*n;
//        cerr << t << "," << a << endl;
    }

    cout << t + a << endl;
}
