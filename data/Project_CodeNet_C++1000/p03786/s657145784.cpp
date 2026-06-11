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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    vector<ll> sum(N + 1);
    sum[0] = 0;
    rep(i, N){
        sum[i + 1] = sum[i] + A[i];
    }

    ll ans = 1;

    for (int i = A.size() - 2;i>=0;i--){
        if(sum[i+1]*2 < A[i+1]){
            break;
        }
        ans++;
    }

    cout << ans << endl;


}
