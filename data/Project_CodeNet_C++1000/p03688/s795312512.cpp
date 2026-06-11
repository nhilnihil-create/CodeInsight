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

    ll n;
    cin>>n;
    vl as(n);
    cin>>as;

    ll m = LINF, M = -1;
    rep(i, n) {
        chmin(m, as[i]);
        chmax(M, as[i]);
    }
    if (M - m > 1) {
        cout<<"No"<<endl;
        return 0;
    }
    if (m == M) {
        if (m + 1 == n || m * 2 <= n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }

    ll mc = 0, Mc = 0;
    rep(i, n) {
        if (as[i] == m) mc++;
        else Mc++;
    }
    if ((M - mc) * 2 > Mc || mc - 1 + 1 > m || mc - 1 + Mc / 2 < m) {
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;
    return 0;
}