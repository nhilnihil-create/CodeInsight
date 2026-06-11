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
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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

    ll a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;

    LP ans = LP(0, 0);
    rep(i, 31) rep(j, 31) {
        ll wat = 100 * a * i + 100 * b * j;
        if (wat > f) continue;
        rep(k, 3001) {
            ll sgru = (a * i + b * j) * e;
            ll sgr = d * k;
            if (sgr > sgru) continue;
            if (f - wat - sgr < 0) continue;
            sgr += min(sgru - sgr, f - wat - sgr) / c * c;
            if (ans.fi * sgr >= ans.se * (sgr + wat)) ans = LP(sgr + wat, sgr);
        }
    }
    cout<<ans.fi<<" "<<ans.se<<endl;
}