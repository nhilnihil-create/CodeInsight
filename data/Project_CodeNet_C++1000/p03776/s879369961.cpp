#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin>>n>>a>>b;
    vl vs(n);
    cin>>vs;

    vector<vector<LP>> dp(n + 1, vector<LP>(n + 1));
    dp[0][0].se = 1;
    rep(i, n) rep(j, n) rep(k, j + 1) {
        ll temp = dp[i + 1][j + 1].fi - (dp[i][k].fi + vs[j]);
        if (temp > 0) continue;
        if (temp == 0) dp[i + 1][j + 1].se += dp[i][k].se;
        else dp[i + 1][j + 1] = LP(dp[i][k].fi + vs[j], dp[i][k].se);
    }

    priority_queue<pair<double, ll>> q;
    for (int i = a; i <= b; ++i) rep(j, n) {
        q.emplace((ld)dp[i][j + 1].fi / i, dp[i][j + 1].se);
    }
    double m = q.top().fi;
    ll cnt = 0;
    while (!q.empty() && q.top().fi == m) {
        cnt += q.top().se;
        q.pop();
    }
    printf("%.10f\n%ld\n", m, cnt);
}