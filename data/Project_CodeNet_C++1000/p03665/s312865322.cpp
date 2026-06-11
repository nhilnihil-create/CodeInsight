#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
#define INF 1e+14

ll dp[51][5010];

int main() {
    int N,P; cin >> N >> P;
    vecl A(N);
    int W = 0;
    dp[0][0] = 1;
    REP(i, N)
    {
        cin >> A[i];
        W += A[i];
    }
    REP(i,N) REP(j,W) {
        dp[i+1][j] += dp[i][j];
        if(dp[i][j] != 0)
            dp[i+1][j + A[i]] += dp[i][j];
    }
    ll ans = 0;
    REP(j,W+1) {
        if(j%2 == P)
            ans += dp[N][j];
    }
    cout << ans << endl;
}
