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
    //cout << fixed << setprecision(10);
    int N,M;
    cin >> N >> M;
    vector<ll> a(N), b(N);
    vector<ll> c(M), d(M);

    rep(i, N) cin >> a[i] >> b[i];
    rep(i, M) cin >> c[i] >> d[i];

    rep(i,N){
        ll dist = 100100100100100;
        int n;
        rep(j, M) {
            if(chmin(dist, abs(a[i]-c[j]) + abs(b[i]-d[j]))){
                n = j;
            }
        }
        cout << (n + 1) << endl;
    }
}
