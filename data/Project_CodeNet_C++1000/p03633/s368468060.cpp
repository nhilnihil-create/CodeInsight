#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 最大公約数(ユークリッドの互除法)
// O(log max(a, b))
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

// 最小公倍数(最大公約数のライブラリ必須)
// O(log max(a, b))
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main(){
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i, n){
        cin >> t.at(i);
    }
    ll ans = t.at(0);
    rep(i, n){
        ans = lcm(ans, t.at(i));
    }
    cout << ans << endl;
}