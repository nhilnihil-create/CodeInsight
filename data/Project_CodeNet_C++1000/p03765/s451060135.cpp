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

    string s, t; cin>>s>>t;
    ll n = sz(s), m = sz(t);
    vvl ss(n + 1, vl(2)), ts(m + 1, vl(2));
    rep(i, n) {
        ss[i + 1][0] = ss[i][0];
        ss[i + 1][1] = ss[i][1];
        if (s[i] == 'A') ss[i + 1][0]++;
        else ss[i + 1][1]++;
    }
    rep(i, m) {
        ts[i + 1][0] = ts[i][0];
        ts[i + 1][1] = ts[i][1];
        if (t[i] == 'A') ts[i + 1][0]++;
        else ts[i + 1][1]++;
    }
    ll Q; cin>>Q;
    rep(q, Q) {
        ll a, b, c, d;
        cin>>a>>b>>c>>d; a--; c--;
        ll sa = ss[b][0] - ss[a][0];
        ll sb = ss[b][1] - ss[a][1];
        ll ta = ts[d][0] - ts[c][0];
        ll tb = ts[d][1] - ts[c][1];
        if (((sa - ta) - (sb - tb)) % 3) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}