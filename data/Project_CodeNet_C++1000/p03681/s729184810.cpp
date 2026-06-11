#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll kai(ll a){
    ll res = 1;
    while(a>1){
        res = res * a % MOD;
        a--;
    }
    return res % MOD;
}

int main(){ 
    ll n, m; cin >> n >> m;
    ll a = min(n, m), b = max(n, m);
    ll res;
    if(b-a>=2) res = 0;
    else if(b-a == 0){
        res = kai(a) * kai(b) % MOD * 2 % MOD;
    }
    else{
        res = kai(a) * kai(b) % MOD;
    }
    cout << res << ln;
}