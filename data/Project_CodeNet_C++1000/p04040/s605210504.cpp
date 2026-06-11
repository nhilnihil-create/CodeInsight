#include <bits/stdc++.h>
using namespace std;
const int maxn=212345;
const int mod=1000000007;
int h,w,a,b,fac[maxn],rev[maxn];
inline int ksm(int x,int n) {
    int ret=1;
    while (n) {
        if (n&1) ret=1ll*ret*x%mod;
        n>>=1;
        x=1ll*x*x%mod;
    }
    return ret;
}
inline int C(int x,int y) {
    return 1ll*fac[x]*rev[y]%mod*rev[x-y]%mod;
}
int main()
{
    fac[0]=rev[0]=1;
    for (int i=1;i<maxn;++i) {
        fac[i]=1ll*fac[i-1]*i%mod;
        rev[i]=ksm(fac[i],mod-2);
    }
    scanf("%d%d%d%d",&h,&w,&a,&b);
    int res=C(h+w-2,w-1);
    for (int i=1;i<=b;++i) {
        int y=i,x=h-a;
        res=((res-1ll*C(x+y-2,y-1)*C(w-x+h-y-1,w-y)%mod)%mod+mod)%mod;
    }
    printf("%d\n",res);
    return 0;
}
