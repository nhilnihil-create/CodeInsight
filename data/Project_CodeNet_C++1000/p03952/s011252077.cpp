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

    ll n, x; cin>>n>>x;

    if (x == 1 || x == 2 * n - 1) {
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;

    if (n == 2) {
        rep(i, 3) cout<<i + 1<<endl;
        return 0;
    }

    vl ans(2 * n - 1);
    rep(i, 2 * n - 1) ans[i] = i + 1;
    if (x == 2) {
        swap(ans[2 * n - 2], ans[n - 2]);
        swap(ans[x - 2], ans[n - 1]);
        swap(ans[x - 1], ans[n]);
        swap(ans[2 * n - 3], ans[n + 1]);
    }
    else {
        swap(ans[0], ans[n - 2]);
        swap(ans[x - 1], ans[n - 1]);
        swap(ans[x], ans[n]);
        swap(ans[1], ans[n + 1]);
    }
    rep(i, 2 * n - 1) {
        cout<<ans[i]<<endl;
    }
}