#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
#define ll long long int
const double epsilon = 1e-7;

ll ma(ll x, ll y){
    if(x>y)return x;
    return y;
}
ll fac[200100];
ll inv[200100];
ll facinv[200100];
void C_init(){
    fac[0] = 1;
    for(int i = 1;i < 200100;i++)fac[i] = (fac[i-1] * i)%mod;
    inv[1] = 1;
    for(int i = 2;i < 200100;i++)inv[i] = ((-(mod/i)*inv[mod%i])%mod+mod)%mod;
    facinv[0] = 1;
    for(int i = 1;i < 200100;i++)facinv[i] = (facinv[i-1] * inv[i])%mod;
    return;
}
ll nCr(ll n, ll r){
    return ((fac[n] * facinv[n-r])%mod * facinv[r])%mod;
}
int main(void){
    int h, w, a, b;
    scanf("%d %d %d %d", &h, &w, &a, &b);
    C_init();
    ll ans = 0;
    for(int i = 0;a + i < h && b + i < w;i++){
        ans += (nCr(h-a+b-1, h-a-i-1)*nCr(a+w-b-1, w-b-i-1))%mod;
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}
