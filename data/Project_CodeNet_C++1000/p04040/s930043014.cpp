#include<iostream>
#include<cstdio>
#include<functional>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5+7;
const int inf = 1e5;
const int modn = 1e9+7;
const ld eps = 1e-8;
const long double PI = acos(-1.0);
void qRead(ll &x){x = 0;char a;for(a = getchar();a <'0' || a > '9';a = getchar());for(;a >= '0' && a <= '9';a = getchar())x = x*10 + a-'0';}
void qRead(int &x){x = 0;char a;for(a = getchar();a <'0' || a > '9';a = getchar());for(;a >= '0' && a <= '9';a = getchar())x = x*10 + a-'0';}
ll qpow(ll a,ll b,ll mo = modn){
//    printf("%lld\n",mo);
    ll res = 1;
    while(b){
        if(b & 1)res = (res*a) % mo;
        a = (a*a) % mo;
        b >>= 1;
    }
    return res;
}
ld qpow(ld a,ll b){
    ld res = 1;
    while(b){
        if(b & 1)res *= a;
        a = a*a;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a,ll b){
    if(!b)return a;
    return gcd(b,a%b);
}
//ll vis[maxn],prime[maxn],cnt,smallP[maxn];
//void getPrime(int n){
//    cnt = 0;
//    for(int i = 1;i <= n;i++)vis[i] = 0;
//    for(ll i = 2;i <= n;i++){
//        if(!vis[i]){
//            prime[++cnt] = i;
//            smallP[i] = i;
//        }
//        for(int j = 1;j <= cnt && i*prime[j] <= n;j++){
//            vis[prime[j]*i] = 1;
//            smallP[prime[j]*i] = prime[j];
//            if((i % prime[j]) == 0)break;
//        }
//    }
//}
ll f[maxn],invF[maxn];
void getF(){
    f[0] = invF[0] = 1;
    for(int i = 1;i < maxn;i++){
        f[i] = f[i-1] *i %modn;
//        printf("%lld\n",f[i]);
    }
    invF[maxn-1] = qpow(f[maxn-1],modn-2);
    for(int i = maxn-2;i >= 1;i--){
        invF[i] = invF[i+1]*(i+1) % modn;
    }
//    for(int i = 1;i <= maxn-1;i++)if((invF[i]*f[i] % modn) != 1)printf("%d\n",i);
}
int main(){
    getF();
    int h,w,a,b;
    scanf("%d%d%d%d",&h,&w,&a,&b);
//    printf("%d %d %d %d\n",h,w,a,b);
    ll ans = 0;
    for(int i = 1;i <= h - a;i++){
        ans = (ans + f[b-1+i-1]*invF[b-1] % modn *invF[i-1] % modn*f[h-i+w-b-1] % modn * invF[h-i] % modn * invF[w-b-1] % modn) % modn;
//        printf("%d %d %d ||| %d %d %d\n",b-1+i-1,b,i-1,h-i+w-b-1,h-i,w-b-1);
//        printf("%lld %lld %lld ||| %lld %lld %lld\n",f[b-1+i-1],invF[b-1],invF[i-1],f[h-i+w-b-1],invF[h-i],invF[w-b-1]);
//        printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}
