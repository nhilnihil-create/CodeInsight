#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll fac[200000+5];   //阶乘
ll inv[200000+5];   //逆元

ll quickmod(ll a, ll b){
    ll ans = 1;
    while (b) {
        if (b&1) {
            ans = ans * a % mod;
        }
        a = a*a % mod;
        b >>= 1;
    }
    return ans;
}

void getFac(){
    fac[0] = inv[0] = 1;
    for (int i = 1; i<=200005; i++) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = quickmod(fac[i], mod-2);     //i的阶乘的逆元
    }
}

ll getC(ll n, ll m){
    return fac[n] * inv[n-m] % mod * inv[m] % mod;
}

int main(){
    ll h, w, a, b;
    scanf("%lld%lld%lld%lld", &h, &w, &a, &b);
    ll c = h-a;
    ll ans = 0;
    getFac();
    for (ll i = 1; i<=c; i++) {
        ans += getC(i+b-2, b-1) * getC(h-i+w-b-1, w-b-1) % mod;
        ans %= mod;
    }
    printf("%lld\n", ans);
}