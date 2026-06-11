#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
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
    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll> t(n,0);
    rep(i,n)cin >> t[i];
    sort(begin(t),end(t));
    ll res = 0;
    for(ll i = 0;i<n;){
        res++;
        ll s = i;
        while(i<n && t[i] - t[s] <= k && i-s < c)++i;
    }
    cout << res << endl;
    return 0;
}