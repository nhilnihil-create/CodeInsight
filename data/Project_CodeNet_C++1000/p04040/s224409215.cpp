#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
int f[200005];
int g[200005];
int exp(int a, int x){
    if (x == 0) return 1;
    int p = exp(a,x/2);
    p *= p;
    p %= mod;
    if (x % 2 == 1) {
        p *= a;
        p %= mod;
    }
    return p;
}
int m(int n, int k){
    //printf("%lld %lld\n",n,k);
    return ((f[n+k] * g[n])%mod * g[k]) % mod;
}
main(){
    int h,w,a,b;
    scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
    f[0] = g[0] = 1;
    for (int i = 1; i <= h+w; i++){
        f[i] = (f[i-1]*i)%mod;
        g[i] = exp(f[i],mod-2);
        //printf("%lld %lld %lld\n",i,f[i],g[i]);
    }
    int ans = m(h-1,w-1);
    //printf("%lld\n",ans);
    for (int i = h-a; i < h; i++){
        //printf("-%lld * %lld\n",m(i,b-1),m(h-i-1,w-b-1));
        ans -= (m(i,b-1)*m(h-i-1,w-b-1));
        ans %= mod;
    }
    ans = (ans+mod)%mod;
    printf("%lld",ans);
}
