#include <bits/stdc++.h>
#define repl(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n+1,0);
    v[n] = LONG_LONG_MAX;
    rep(i,n)cin >> v[i];
    ll ans = 0;
    repl(i,0,n){
        while(i+1 < n && v[i] == v[i+1])i++;
        if(i+1 < n && v[i] < v[i+1])while(i+1 < n && v[i] <= v[i+1])i++;
        else if(i+1 < n && v[i] > v[i+1])while(i+1 < n && v[i] >= v[i+1])i++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/