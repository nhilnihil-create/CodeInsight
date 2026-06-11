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
//ミョ(-ω- ?)
int main() {
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,bool>> vp(n);
    rep(i,n){
        vp[i].first = 1;
        if(!i)vp[i].second = true;
        else vp[i].second = false;
    }
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        --vp[a-1].first;
        ++vp[b-1].first;
        if(vp[a-1].second)vp[b-1].second = true;
        if(vp[a-1].first <= 0)vp[a-1].second = false;
    }
    ll res = 0;
    for(auto a : vp)if(a.second)res++;
    cout << res << endl;
    return 0;
}