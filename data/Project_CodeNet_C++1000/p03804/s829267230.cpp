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
    ll n, m; cin >> n >> m;

    // 入力
    vector<string> a(n);
    vector<string> b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    
    // 縦横それぞれ(n-m+1)の範囲を探索
    ll range = n-m+1;

    // 探索
    bool ans = false;
    rep(i, range){
        rep(j, range){
            bool chk = true;
            rep(k, m) if(a[i+k].substr(j, b[k].size()) != b[k]){ chk = false; break; }
            if(!chk) continue;
            ans = true;
        }
    }

    // 結果出力
    (ans) ? Yes() : No();
}