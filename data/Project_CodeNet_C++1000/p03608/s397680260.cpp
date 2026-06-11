#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
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

    ll n, m, r;
    cin>>n>>m>>r;
    vl rs(r);
    cin>>rs;
    rep(i, r) rs[i]--;
    vvl ds(n, vl(n, LINF));
    rep(i, m) {
        ll v1, v2, w;
        cin>>v1>>v2>>w; v1--; v2--;
        ds[v1][v2] = w;
        ds[v2][v1] = w;
    }

    rep(k, n) rep(i, n) rep(j, n) chmin(ds[i][j], ds[i][k] + ds[k][j]);

    vvl dp(1<<r, vl(r, LINF));
    rep(i, r) dp[1<<i][i] = 0;
    rep(i, 1<<r) rep(j, r) rep(k, r) {
        if (i>>j&1 == 0) continue;
        if (i>>k&1) continue;
        chmin(dp[i + (1<<k)][k], dp[i][j] + ds[rs[j]][rs[k]]);
    }

    ll ans = LINF;
    rep(i, r) chmin(ans, dp[(1<<r) - 1][i]);
    cout<<ans<<endl;
}