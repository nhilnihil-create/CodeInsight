#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define rrep(i, a, b) for (int i = (a); i < (b); ++i)
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
using tl = tuple<ll, ll, ll>;

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

    ll n, ma, mb;
    cin>>n>>ma>>mb;
    vvl abc(n, vl(3)); cin>>abc;

    vector<vvl> dp(n + 1, vvl(410, vl(410, LINF)));
    dp[0][0][0] = 0;
    rep(i, n) {
        ll a = abc[i][0];
        ll b = abc[i][1];
        ll c = abc[i][2];
        rep(j, 410) rep(k, 410) {
            chmin(dp[i + 1][j][k], dp[i][j][k]);
            if (j + a < 410 && k + b < 410)
                chmin(dp[i + 1][j + a][k + b], dp[i][j][k] + c);
        }
    }

    ll ans = LINF;
    int i = ma, j = mb;
    while (i < 410 && j < 410) {
        chmin(ans, dp[n][i][j]);
        i += ma;
        j += mb;
    }
    if (ans == LINF) cout<<-1<<endl;
    else cout<<ans<<endl;
}