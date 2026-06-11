#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll w, h, n; cin >> w >> h >> n;
    ll sx = 0, sy = 0, ex = w, ey = h;

    rep(i, n){
        ll x, y, a; cin >> x >> y >> a;
        if(a == 1){ if(sx < x) sx = x; }
        else if(a == 2){ if(ex > x) ex = x; }
        else if(a == 3){ if(sy < y) sy = y; }
        else if(ey > y) ey = y;
    }
    if(sx <= ex && sy <= ey) cout << (ex-sx)*(ey-sy) << endl;
    else cout << 0 << endl;
}