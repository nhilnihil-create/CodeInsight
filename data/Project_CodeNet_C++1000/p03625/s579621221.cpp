#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll n;
    cin >> n;
    map<ll,ll> m;
    rep(i,n){
        ll a;
        cin >> a;
        m[a]++;
    }
    vector<ll> e;
    vector<ll> sq;
    for(auto p : m){
        if(p.second >= 2)e.push_back(p.first);
        if(p.second >= 4)sq.push_back(p.first);
    }
    sort(sq.begin(),sq.end(),greater<ll>());
    ll ans = 0;
    if(!sq.empty())ans = sq.at(0)*sq.at(0);
    for(ll i : e){//長方形
        for(ll j : e){
            if(i != j)ans = max(ans,i*j);
        }
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