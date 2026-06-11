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

ll n;
string s;
vi ss;

bool dfs(ll i, vi& sw, int p, int c) {
    if (i == n) return (c == sw[0] && ss[0] * p * c == sw[1]);

    sw[i] = c;
    return dfs(i + 1, sw, c, ss[i] * p * c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    cin>>s;
    ss = vi(n);
    rep(i, n) ss[i] = (s[i] == 'o') ? 1 : -1;

    vi sw1(n);
    sw1[0] = 1;
    if (dfs(1, sw1, 1, 1)) {
        rep(i, n) cout<<(sw1[i] == 1 ? 'S' : 'W');
        cout<<endl;
        return 0;
    }
    vi sw2(n);
    sw2[0] = 1;
    if (dfs(1, sw2, 1, -1)) {
        rep(i, n) cout<<(sw2[i] == 1 ? 'S' : 'W');
        cout<<endl;
        return 0;
    }
    vi sw3(n);
    sw3[0] = -1;
    if (dfs(1, sw3, -1, 1)) {
        rep(i, n) cout<<(sw3[i] == 1 ? 'S' : 'W');
        cout<<endl;
        return 0;
    }
    vi sw4(n);
    sw4[0] = -1;
    if (dfs(1, sw4, -1, -1)) {
        rep(i, n) cout<<(sw4[i] == 1 ? 'S' : 'W');
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
}