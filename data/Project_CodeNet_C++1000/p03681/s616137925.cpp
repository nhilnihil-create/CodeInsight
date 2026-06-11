#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
const int INF = 1000000007;
const ll mod = 1000000007;
#define MAX_N 2200000
ll f[MAX_N];
ll invf[MAX_N];
ll modpow(ll  a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll nCm(ll n,ll m){return ((f[n]*invf[m])%mod)*invf[n-m]%mod;  }
signed main(){
    int n,m;cin >> n >> m;
    for(int i = 1;i <= 210000;i++){
        if(i == 1)f[i] = 1;
        else f[i] = (f[i-1]*i)%mod;
    }

    if(n == m+1){
        int ans = (f[n]*f[m])%mod;
        cout << ans << endl;



    }
    else if(m == n+1){
        int ans = (f[n]*f[m])%mod;
        cout << ans << endl;

    }
    else if(n == m){
        int ans = (f[n]*f[m])%mod;
        ans = (ans*2)%mod;
        cout << ans << endl;

    }
    else cout << 0 << endl;
    return 0;
}