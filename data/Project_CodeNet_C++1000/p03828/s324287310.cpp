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

// 素因数分解：nの素因数分解を{素数, 指数}の形で昇順に返す
vector<pair<long long, long long>> primeFactorize(long long n){
    vector<pair<long long, long long>> ret;
    for(long long i=2; i*i<=n; i++){
        if(n%i != 0) continue;
        long long ex = 0;
        while(n%i == 0){ ex++; n /= i; }
        ret.push_back({i, ex});
    }
    if(n != 1) ret.push_back({n, 1});
    return ret;
}

int main(){
    Init();
    ll n; cin >> n;
    vi cnt(1001);
    for(ll i=1; i<=n; i++){
        auto p = primeFactorize(i);
        for(auto c: p) cnt[c.first] += c.second;
    }
    ll ans = 1;
    for(auto c: cnt) if(c != 0) ans = (ans*(c+1))%MODV;
    cout << ans << endl;
}