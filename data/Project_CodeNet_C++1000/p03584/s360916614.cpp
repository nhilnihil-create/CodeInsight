#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    ll ans = 0;
    rep(i,n){
        if( (k|a[i]) == k) ans += b[i];
    }
    int c = 0;
    ll k_ = k;
    while(k_>0) k_/=2,++c;

    for(int i=c-1;i>=0;i--){
        if(k>>i&1){
            ll p = (k ^ (1LL<<i)) | ((1LL<<i) - 1LL);
            ll res = 0;
            rep(i,n){
                if( (p|a[i]) == p) res += b[i];
            }
            ans = max(ans,res);
        }
    }
    cout << ans << endl;

    return 0;
}