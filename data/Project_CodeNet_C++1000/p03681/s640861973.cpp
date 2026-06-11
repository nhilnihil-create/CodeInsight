#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
const ll mod = 1e9+7;

int main() {
    ll n, m;
    cin >> n >> m;
    if(abs(n-m) > 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(ll i = 2; i <= n; ++i) {
        ans*=i%mod;
        ans%=mod;
    }

    for(ll i = 2; i <= m; ++i) {
        ans*=i%mod;
        ans%=mod;
    }
    if(abs(n-m)==0) ans*=2;
    ans%=mod;
    cout << ans << endl;
    return 0;
}