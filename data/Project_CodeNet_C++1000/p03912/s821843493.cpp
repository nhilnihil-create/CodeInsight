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

    ll n, m; cin>>n>>m;
    map<ll, ll> mp;
    rep(i, n) {
        ll a; cin>>a;
        mp[a]++;
    }

    map<ll, LP> cnt;
    for (auto v : mp) {
        cnt[v.fi % m].fi += v.se;
        cnt[v.fi % m].se += v.se / 2;
    }

    ll ans = 0;
    rep(i, m) {
        if (i == 0 || i * 2 == m) {
            ans += cnt[i].fi / 2;
            continue;
        }

        if (i > m - i) break;

        LP a = cnt[i];
        LP b = cnt[m - i];
        if (a.fi < b.fi) swap(a, b);
        ans += min(a.se, (a.fi - b.fi) / 2);
        ans += b.fi;
    }
    cout<<ans<<endl;
}