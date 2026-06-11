#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n,0);
    rep(i,n)cin >> a[i];
    ll res = LONG_LONG_MAX;
    for(ll bit = 0;bit < (1 << n);bit++){
        if(__builtin_popcount(bit) < k)continue;
        ll height = a.front();
        ll cost = 0;
        //rep(i,n)if(bit & (1 << i))h.emplace_back(a[i]);
        //rep(i,h.size()){
        //    while(h[i] < height){
        //        h[i]++;
        //        cost++;
        //    }
        //    height = h[i]+1;
        //}
        auto h = a;
        rep(i,n){
            if(bit & (1 << i)){
                while(h[i] < height){
                    h[i]++;
                    cost++;
                }
                height = h[i]+1;
            }else{
                height = max(height,h[i] + 1);
            }
        }
        res = min(res,cost);
    }
    cout << res << "\n";
    return 0;
}
