#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 1e9 + 7;
LL fac[500007], n, k, ans, x, y;

LL power(LL x, LL y){return y ? power(x * x % mod, y / 2) * (y % 2 ? x : 1) % mod : 1;}

LL modInverse(LL n) { return power(n, mod-2); } 
 
LL nCr(LL n, LL r) { 
    if (n < 0 || r < 0 || r > n) return 0;  
    return (fac[n]* modInverse(fac[r]) % mod * modInverse(fac[n-r]) % mod) % mod; 
} 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    fac[0] = 1LL; 
    for (LL i=1;i<=500006;++i) 
        fac[i] = fac[i-1]*i%mod;

    LL n, m, a, b;
    cin >> n >> m >> a >> b;

    LL ans = nCr(n + m - 2, m - 1);
    for(LL i = n-a+1; i <= n; i++) {
        LL x = nCr(i-1 + b-1, b-1), y = nCr(n-i + m-b-1, n-i);
        LL z = (x * y) % mod;
        ans -= z;
        if(ans < 0) ans += mod;
    }
    cout << ans;
}